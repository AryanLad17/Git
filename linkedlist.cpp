#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
int  whatdoesitdo(){
     Node* head=nullptr;
    Node* temp1=head;
    Node* temp2=head;
    while(temp1 && temp1->next){
        temp1=temp1->next->next;
        temp2=temp2->next;
    }
    return temp2->data;
}
int main(){
    int n;
    cout<<"Enter the number elements in Node:";
    cin>>n;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;++i){
        Node* newnode=new Node;
        cout<<"Data"<<i+1<<" :";
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
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    whatdoesitdo();
    
    return 0;

}