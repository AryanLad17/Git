#include<iostream>
#include "stack.h"
using namespace std;
bool isOperand(char token){
    if(token>= 'a' && token<='z' ||token>= 'A' && token<='Z' ||token>= '1' && token<='9' ||)
        return true;
    return false;
}
bool operator(char token){
    if(token=='^' || token=='*' || token=='/' || token=='+' || token=='-')
        return true;
    return false;
}
void infix(string exp){
    Stack s;
    string Infix="";
    char *temp=&exp[0];
    while(*temp){
        char token=*temp;
        if(isOperand(token)){
            Infix+=token;
        }
        else if(operator(token)){
            char p1=s.pop();
         string  p2=s.pop();
            s.push(p2+token+p1);

        }
        temp++;

    }
    cout<<"Infix: "<<s.pop()<<endl;

}
int main(){
    string exp="ab+cde+**";
    infix(exp);
    return 0;

}