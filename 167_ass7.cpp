#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
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
            
        }
};
int main(){
    stack Previous_Stack,Next_Stack;
    return 0;
}