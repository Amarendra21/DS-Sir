#include <iostream>
using namespace std;

class Node {
    int data;
    Node * next;
public:
    Node( int );
    void setData( int );
    int getData() const;
    void setNext( Node * );
    Node * getNext() const;
};

class CircularLinkedList {
    Node * head;
    
public:
    CircularLinkedList();
    bool insert( int  );
    bool insert( int, int );
    void display();
    bool deleteByPosition( int );
    bool deleteByVal( int );
    ~CircularLinkedList();
};












