#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class LinkedList{
	private:
		Node* head;
	public:
	LinkedList(){
		head=NULL;
	}
    void insert(int n){
        for(int i=0;i<n;i++){
            Node* newnode=new Node;
            cout<<"Data "<<i+1<<" : ";
            cin>>newnode->data;
            newnode->next=nullptr;
            if(head==nullptr){
                head=newnode;
            }
            else {
                Node* temp=head;
                while(temp->next!=nullptr){
                    temp=temp->next;
                }
                temp->next=newnode;
            }
        }
    }
    void print(){
		Node* temp=head;
        while(temp!=nullptr){
        cout<<temp->data<<" ";
            temp=temp->next;
        }
	}
    void deletelist(int d, int n) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == d) {
        head = temp->next;  
        delete temp;
        return;
    }

    for (int i = 0; i < n && temp != NULL; ++i) {
        if (temp->data == d) {
            if (prev != NULL) {
                prev->next = temp->next;
            }
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

};
int main(){
    LinkedList l;
    int d;   
    l.insert(4);
    l.print();
    cout<<"Enter the Data to removed:";
    cin>>d;
    l.deletelist(d,4);
return 0;
}