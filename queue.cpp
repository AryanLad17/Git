#include<iostream>
using namespace std;
#define MAX 5
class Queue{
    int front,rear;
    int arr[MAX];
    public:
            Queue(): front(-1),rear(-1) {}

            bool isFull(){
                if((rear+1)%MAX==front)
                    return true;
                return false;
            }
            bool isEmpty(){
                if(front==-1 && rear==-1)
                    return true;
                return false;
            }
            void enqueue(int a){
                if(isFull()){
                    cout<<"Queue is full"<<endl;
                    return ;
                }
                else{
                    if(front==-1 && rear==-1){
                        front=0;
                        rear=0;
                    }
                    else{
                        rear=rear+1%MAX;
                    }
                    arr[rear]=a;
                }
            }
            int dequeue(){
                if(isEmpty()){
                    cout<<"Queue is empty"<<endl;
                }
                else{
                    int x=arr[front];
                    if(fornt==rear){
                        front=-1;
                        rear=-1;
                    }
                    else{
                        front=(front+1)%MAX;
                    }
                }
            }
            int peek(){
                if(isEmpty()){
                    cout<<"Queue is Empty"<<endl;
                    return -1;
                }
                return arr[front];
            }
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(50);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    return 0;
    
}