#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
int main(){
    int n;
    cout<<"Enter teh number of nodes:";
    cin>>n;
    Node* head=nullptr;
   // Node* tail=nullptr;
    for(int i=0;i<n;++i){
        Node* newnode=new Node;
        cout<<"Enter the data for Node "<<i+1<<": ";
        cin>>newnode->data;
        newnode->next=nullptr;
        newnode->prev=nullptr;
        if(head==nullptr){
            head=newnode;
            //tail=newnode;
        }
        else{
            Node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;

        }
    }
    cout<<"Doubly Linked list :";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    // Free allocated memory
    temp=head;
    while(temp!=nullptr){
        Node* next=temp->next;
        delete temp;
        temp=next;
    }
    return 0;
}