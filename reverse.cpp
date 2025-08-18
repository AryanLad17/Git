#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int n) {
        for (int i = 0; i < n; i++) {
            Node* newnode = new Node;
            cout << "Data " << i + 1 << " : ";
            cin >> newnode->data;
            newnode->next = nullptr;

            if (head == nullptr) {
                head = newnode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void reverseUntil(Node* curr, Node* prev) {
        if (curr == nullptr) {
            head = prev; // 
            return;
        }

        Node* next = curr->next;
        reverseUntil(next, curr);
        curr->next = prev;
    }

    void reverse() {
        reverseUntil(head, nullptr);
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList l;
    l.insert(5);
    cout << "Original List: ";
  //  l.print();
    cout << endl;
    cout << "Reversed List: ";
    l.reverse();
    cout << endl;
    return 0;
}
