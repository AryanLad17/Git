#include <iostream>
using namespace std;

struct Node {
    int power;
    int coeff;
    Node* next;
};

class Polynomial {
    Node* head;

public:
    Polynomial() {
        head = nullptr;
    }

   
    void insertAtEnd(int coeff, int power) {
        Node* nn = new Node{power, coeff, nullptr};
        if (!head) {
            head = nn;
        } else {
            Node* t = head;
            while (t->next) t = t->next;
            t->next = nn;
        }
    }

    
    void insertAtCorrectPlace(int coeff, int power) {
        if (coeff == 0) 
        {
            return;
        }

        Node* nn = new Node{power, coeff, nullptr};

       
        if (!head) {
            head = nn;
            return;
        }

       
        if (power > head->power) {
            nn->next = head;
            head = nn;
            return;
        }

        Node* t = head;
        Node* prev = nullptr;

        while (t && t->power >= power) {
            if (t->power == power) 
            {
               { 
                t->coeff += coeff;
                delete nn; 
               }
                if (t->coeff == 0) 
                { 
                    if (prev) prev->next = t->next;
                    else head = t->next;
                    delete t;
                }
                return;
            }
            prev = t;
            t = t->next;
        }

       
        nn->next = t;
        prev->next = nn;
    }

  
    void print() {
        Node* t = head;
        if (!t) {
            cout << "0" << endl;
            return;
        }
        while (t) {
            cout << t->coeff << "t^" << t->power;
            if (t->next) cout << " + ";
            t = t->next;
        }
        cout << endl;
    }

    void subtract(Polynomial& second, Polynomial& result) {
        Node* t1 = head;
        Node* t2 = second.head;

        while (t1 && t2) {
            if (t1->power > t2->power) {
                result.insertAtEnd(t1->coeff, t1->power);
                t1 = t1->next;
            } else if (t1->power < t2->power) {
                result.insertAtEnd(-t2->coeff, t2->power);
                t2 = t2->next;
            } else {
                result.insertAtEnd(t1->coeff - t2->coeff, t1->power);
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        while (t1) {
            result.insertAtEnd(t1->coeff, t1->power);
            t1 = t1->next;
        }
        while (t2) {
            result.insertAtEnd(-t2->coeff, t2->power);
            t2 = t2->next;
        }
    }

  
    void multiply(Polynomial& second, Polynomial& result) {
        Node* t1 = head;
        while (t1) {
            Node* t2 = second.head;
            while (t2) {
                result.insertAtCorrectPlace(t1->coeff * t2->coeff,t1->power + t2->power);
                t2 = t2->next;
            }
            t1 = t1->next;
        }
    }
};

int main() {
    Polynomial V, I, P, L;

  
    V.insertAtEnd(7, 4);
    V.insertAtEnd(1, 2);
    V.insertAtEnd(1, 0);

   
    I.insertAtEnd(7, 5);
    I.insertAtEnd(1, 4);
    I.insertAtEnd(1, 3);

    cout << "V(t) = "; V.print();
    cout << "I(t) = "; I.print();

    V.multiply(I, P);
    cout << "P(t) = V(t) * I(t) = ";
    P.print();

    V.subtract(I, L);
    cout << "L(t) = V(t) - I(t) = ";
    L.print();

    return 0;
}
