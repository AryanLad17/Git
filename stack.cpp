#include<iostream>

using namespace std;
class stack{
    int top=-1;
    int arr[10];
    public:
    bool isfull(){
        if(top==9)
            return 1;
        else
            return 0;
    }
    void push(int x){
        if(isfull()){
            cout<<"Stack is Overflow"<<endl;
        }
        else{
            top++;
            arr[top]=x;
        }
    }
    int isempty(){
        if(top==-1)
            return 1;
        else
            return 0;
    }
    int pop(int x){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
           exit(0);
        }
        else{ 
            return arr[top];           
           top--;
            
        
        }
    }
    void display(){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
           exit(0);
        }
        else{
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    int peek(){
        if(isempty()){
            cout<<"Stack is empty";
              exit(0);
        }
        else{
            return arr[top];
        }
    }
    int eixt(){
        exit(0);
    }
};
int main(){
    stack s;
    int choice,element;
    while(1){
        cout<<"1.Push \n2.Pop \n3.Display \n4.Top element\n5.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to be pushed:";
                cin>>element;
                s.push(element);
                break;
            case 2:
                cout<<"Popped elements is:"<<s.pop(element)<<endl;
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout<<"Top element is:"<<s.peek()<<endl;
                break;
            case 5:
                s.eixt();
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }

    return 0;
}