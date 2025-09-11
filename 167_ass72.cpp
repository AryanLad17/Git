#include<iostream>
#define size 5
using namespace std;
class stack{
    private:
        int top;
        int arr[size];
    public:
        stack(): top(-1) {}
        bool isEmpty(){
            if(top==-1)
                return true;
            return false;
        }
        bool isFull(){
            if(top==size-1)
                return true;
            return false;
        }
        void push(int x){
            if(isFull()){
                cout<<"Stack overflow"<<endl;
                return ;
            }
            top++;
            arr[top]=x;
        }
        int pop(){
            if(isEmpty()){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            int x=arr[top];
            top--;
            return x;
        }
        int peek(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return arr[top];
        }
}; 
    int main() {
    stack Previous_Stack, Next_Stack;
    int choice;
    int currentSlide = 1;   // Start at slide 1

    do {
        cout << "\n1. Move to Next slide"
             << "\n2. Move to Previous slide"
             << "\n3. Current Slide"
             << "\n4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: // Next slide
                Previous_Stack.push(currentSlide);
                if(!Next_Stack.isEmpty()) {
                    currentSlide = Next_Stack.pop();
                } else {
                    currentSlide++;  // go to a new slide
                }
                cout << "Current slide: " << currentSlide << endl;
                break;

            case 2: // Previous slide
                if(Previous_Stack.isEmpty()) {
                    cout << "No previous slide" << endl;
                } else {
                    Next_Stack.push(currentSlide);
                    currentSlide = Previous_Stack.pop();
                    cout << "Current slide: " << currentSlide << endl;
                }
                break;

            case 3: // Show current
                cout << "Current slide: " << currentSlide << endl;
                break;

            case 4: 
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != 4);

    return 0;
}
