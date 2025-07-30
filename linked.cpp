#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
int main(){
    node* n=new node[10];
    cout<<"Enter the number of elements:";
    for(int i=0;i<10;i++){
        cout<<"Enter the element"<<i+1<<": ";
        cin>>n[i].data;
        if(i<9){
            n[i].next=&n[i+1];
        }
        else{
            n[i].next=nullptr;
        }
    }
    node* temp=n;
    cout<<"The elements in the linked list are: ";
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    delete[] n;
    return 0;
}