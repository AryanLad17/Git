#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
int main(){
    node n1,n2,n3;
    n1.data=10;
    n2.data=20;
    n3.data=30;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=NULL;
  
    node* temp=&n1;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;   
}