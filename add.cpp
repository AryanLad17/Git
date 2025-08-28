#include<iostream>
using namespace std;
struct Node{
    int data ;
    Node* next;

};
class Linkedlist{
    private:
    Node* head;
    public:
    Linkedlist():head(nullptr){}
    void insert(){
        for(int i=0;i<3;i++){
            Node* newnode=new Node;
            cout<<"Enter data  "<<i+1<<": ";
            cin>>newnode->data;
            newnode->next=NULL;
            if(head==NULL){
                head=newnode;
            }
            else{
                Node*temp=head;while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newnode;
                 
        
    }

        }}
    Linkedlist add(Linkedlist &l2){
        Linkedlist result;
        Node* t1=head;
        Node* t2=l2.head;
        Node* tail=nullptr; // Initialize tail to nullptr

        while(t1!=NULL || t2!=NULL){
            Node* nn=new Node;
            nn->next=NULL;
            if(t1!=nullptr && t2!=nullptr){
                nn->data=t1->data+t2->data;
                t1=t1->next;
                t2=t2->next;
            }
            else if(t1!=nullptr){
                nn->data=t1->data;
                t1=t1->next;
            }
            else if(t2!=nullptr){
                nn->data=t2->data;
                t2=t2->next;
            }
            if(result.head==NULL){
                result.head=nn;
                tail=nn; // Set tail to the new node
            }
            else{
             tail->next=nn;
             tail=nn;   
            }


        }
        return result;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};
int main(){
    Linkedlist l1,l2,result;
    cout<<"Enter elements for List 1:\n";
    l1.insert();
    cout<<"Enter elements for List 2:\n";
    l2.insert();
    cout<<"List 1: ";
    l1.display();
    cout<<"List 2: ";
    l2.display();
    cout<<"Adding the two lists...\n"; 
    
    // The above two lines should be corrected to call the add function correctly
    // result.add(l1, l2); // Corrected call to add function
    result=l1.add(l2);
    cout<<"Resultant List: ";
    result.display();

    
    return 0;
}