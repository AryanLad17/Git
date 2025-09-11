#include<iostream>
#include <cstdlib>
using namespace std;
struct Node{
    int data;
    Node* next;

};
class stack{
    private:
        Node* top;
    public:
        stack(): top(NULL) {}
        bool isEmpty(){
            if(top==NULL)
                return true;
            return false;
        }
        bool isFull(){
            Node* newnode=new Node();
            if(newnode==NULL)
                return true;
            delete newnode;
            return false;
        }
        void push(int x){
            Node* newnode=new Node();
            newnode->data=x;
            newnode->next=NULL;
            if(top==NULL){
                top=newnode;
            }
            else{
                newnode->next=top;
                top=newnode;
            }
        }
        int pop(){
            if(top==NULL){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            int x=top->data;
            Node* temp=top;
            top=top->next;
            delete temp;
            return x;
        }
        int peek(){
            if(top==NULL){
                cout<<"stack is empty"<<endl;
                return -1;
            }
            return top->data;
        }
        void display(){
            if(top==NULL){
                cout<<"Stack is empty"<<endl;
                return;
            }
            Node* temp=top;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }  
};
int main(){
    stack s;
    int choice,value;
    while(true){
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to push:";
                cin>>value;
                s.push(value);
                break;
            case 2:
                cout<<"Popped value: "<<s.pop()<<endl;
                break;
            case 3:
                cout<<"Top value: "<<s.peek()<<endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                exit(0);
                break;
            default:
                cout<<"Invalid choice, try again."<<endl;
                break;
        }
    }
  // while(choice!=5);


    return 0;
}