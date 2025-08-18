#include<iostream>
using namespace std;
struct Node{
    int metro;
    double time;
    Node* next;
    Node* prev;
    Node(int m = 0, double t = 0.0) : metro(m), time(t), next(nullptr), prev(nullptr) {}
};
class Metro{
    private:
        Node* head;
        Node* tail;
    public:
        Metro(): head(NULL),tail(NULL) {}

        void addstation(int n){
            for(int i=0;i<n;++i){
                Node* newnode=new Node;
                cout<<"Enter metro number and time for station "<<i+1<<": ";
                cin>>newnode->metro>>newnode->time;
                newnode->next=NULL;
                newnode->prev=NULL;
                if(head==NULL){
                    head=newnode;
                    tail=newnode;
                }
                else{
                    tail->next=newnode;
                    newnode->prev=tail;
                    tail=newnode;
                }
            }
        }
        void em(int d,double t){
            Node* nn=new Node(d,t);
            if(head==NULL){
                head=nn;
                tail=nn;
            }
            else{
                nn->next=head;
                head->prev=nn;
                head=nn;
            }
        }
        void display(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<"Metro: "<<temp->metro<<", Time:"<<temp->time<<endl;
                temp=temp->next;
            }
        }
        void reverse(){
            Node* temp = tail;
            while(temp != NULL){
                cout<<"Metro: "<<temp->metro<<", Time:"<<temp->time<<endl;
                temp = temp->prev;
            }
        }

        void deletestation(int metronumber){
            Node* temp=head;
            if(head==NULL)return;
            while(temp!=NULL){
                if(temp->metro==metronumber){
                    if(temp==head){
                        head=head->next;
                        if(head!=NULL){
                            head->prev=NULL;
                        }
                        if(temp==tail){
                            tail=temp->prev;
                             if(tail != NULL) tail->next = NULL;
                        }
                    }
                    else {
                        temp->prev->next=temp->next;
                        if(temp->next!=NULL){
                            temp->next->prev=temp->prev;
                        }
                    }
                        delete temp;
                    cout<<"Station "<<metronumber<<" deleted successfully!"<<endl;
                    return;
                }
                temp=temp->next;
            } 
           // cout<<"Station "<<metronumber<<" not found!"<<endl;
        }
        ~Metro(){
            Node* current=head;
            while(current!=NULL){
                Node* nextnode=current->next;
                delete current;
                current=nextnode;
            }
            head = nullptr;
            tail = nullptr;
        }
};
int main(){
    int n;
    cout<<"Enter number of stations to add: ";
    cin>>n;
    Metro m;
    m.addstation(n);
    cout<<"Metro List:"<<endl;
    m.display();
    m.em(101, 12.5);
    cout << "Reversed Metro List:" << endl;
    m.reverse();
    int metroNumber;
    cout << "Enter metro number to delete: ";
    cin >> metroNumber;
    m.deletestation(metroNumber);
    m.display();
    return 0;
}