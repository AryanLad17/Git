#include<iostream>
#include "stack.h"
using namespace std;

bool isOperand(char token){
    if(token>='a' && token<='z' || token>='A' && token<='Z' || token>='0' && token<='9'){
        return true;
    }
    return false;
}
int precedence(char token){
    if(token=='^')
        return 3;
    else if(token=='*' || token=='/')
        return 2;
    else if(token=='+' || token=='-')
        return 1;
    return -1;
}
void postfix(string exp){
    Stack s;
    string Postfix = "";

    char* temp = &exp[0];
while (*temp) {
    char token = *temp;

    if (token == '(') {
        s.push(token);
    }
    else if (token == ')') {
        while (!s.isEmpty() && s.peek() != '(') {
            Postfix += s.pop();
        }
        s.pop();
    }
    else if (isOperand(token)) {
        Postfix += token;
    }
    else { // operator
        while (!s.isEmpty() && s.peek() != '(' &&
               precedence(s.peek()) >= precedence(token)) {
            Postfix += s.pop();
        }
        s.push(token);
    }

    temp++;  // ✅ move to next character
}


    // Pop remaining
    while (!s.isEmpty()) {
        Postfix += s.pop();
    }

    cout << "Postfix: " << Postfix << endl;
}


int main(){
    string expression = "a+b*c-d/e^(f+g)";
    postfix(expression);
}