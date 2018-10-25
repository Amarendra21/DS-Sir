#include <iostream>
using namespace std;

class Queue {
    int * arr;
    int size, front, rear;
public:
    Queue( int size = 5 ) {
        this->size = size;
        arr = new int[ size ];
        front = rear = -1;
    }
    ~Queue() {
        delete [] arr;
    }
    
    bool isEmpty() {
        return ( ( front == -1 ) && ( rear == -1 )) || ( front > rear);
    }
    
    bool isFull() {
        return rear == ( size - 1 );
    }
    
    bool insert( int data ) {
        if( isFull() ) {
            return false;
        }
        
        arr[++rear] = data;
        if( front == -1 ) {
            front = 0;
        }
        return true;
    }
    
    int deleteData() {
        if( isEmpty() ) {
            return -999;
        }
        
        return arr[front++];
    }
};

class CircularQueue {
    int * arr;
    int size, front, rear;
public:
    CircularQueue( int size ) {
        this->size = size;
        front = rear = -1;
        arr = new int[ size ];
    }
    ~CircularQueue() {
        delete [] arr;
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return ( front == -1 && ( rear == size -1 ))  || ( ( (rear + 1 ) % size ) == front );
    }
    
    bool insert( int data ) {
        if( isFull() ) {
            return false;
        }
        
        rear = ( rear + 1 ) % size;
        arr[rear] = data;
        
        return true;
    }
    
    int deleteData() {
        if( isEmpty() ) {
            return -999;
        }
        
        front = ( front + 1) % size;
        return arr[front];
    }
    
    
};


























