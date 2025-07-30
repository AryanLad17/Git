#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
int main(){
    int n;
    cout<<"Enter the number of nodes:";
    cin>>n;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;++i){
        Node* newnode=new Node;
        cout<<"Enter data for Node "<<i+1<<": ";
        cin>>newnode->data;
        newnode->next=nullptr;
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    cout<<"Linked list :";
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