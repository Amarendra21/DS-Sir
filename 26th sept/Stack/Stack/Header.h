#include <iostream>
using namespace std;

class Stack {
    int * arr;
    int top;
    int size;
public:
    Stack( int size = 5 ) {
        this->size = size;
        arr = new int[ size ];
        top  = -1;
    }
    ~Stack() {
        delete [] arr;
    }
    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == ( size - 1);
    }
    
    bool push( int data ) {
        if( isFull() ) {
            return false;
        }
        
        arr[++top] = data;
        return true;
    }
    
    int pop() {
        if( isEmpty() ) {
            return -999;
        }
        
        return arr[top--];
    }
    
    int peek() {
        if( isEmpty() ) {
            return -999;
        }
        
        return arr[top];
    }
};

class DoubleStack {
    int * arr;
    int size;
    int top1, top2;
public:
    DoubleStack( int size = 10) {
        this->size = size;
        arr = new int[ size ];
        top1 = -1;
        top2 = size;
    }
    
    ~DoubleStack() {
        delete [] arr;
    }
    
    bool isEmpty1() {
        return top1 == -1;
    }
    bool isEmpty2() {
        return top2 == size;
    }
    bool isFull() {
        return ( top1 + 1 ) == top2;
    }
    
    bool push1( int data ) {
        if( isFull() ) {
            return false;
        }
        arr[++top1] = data;
        return true;
    }
    bool push2( int data ) {
        if( isFull() ) {
            return false;
        }
        arr[--top2] = data;
        return true;
    }
    
    int pop1() {
        if( isEmpty1() ) {
            return -999;
        }
        return arr[top1--];
    }
    int pop2() {
        if( isEmpty2() ) {
            return -999;
        }
        
        return arr[top2++];
    }
};




















