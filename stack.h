// stack.h
#ifndef STACK_H
#define STACK_H

class Stack {
private:
    char arr[100];   // store characters (operators, brackets, etc.)
    int top;

public:
    Stack();
    void push(char x);
    char pop();
    char peek();
    bool isEmpty();
    bool isFull();
};

#endif
