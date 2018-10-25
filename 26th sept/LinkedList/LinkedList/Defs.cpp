#include "Defs.h"

Node::Node( int data ) {
    this->data = data;
    next = NULL;
}

void Node::setData(int data ){
    this->data = data;
}

int Node::getData() const {
    return data;
}

void Node::setNext(Node * next) {
    this->next = next;
}

Node * Node::getNext() const {
    return next;
}

CircularLinkedList::CircularLinkedList() {
    head = NULL;
}

bool CircularLinkedList::insert(int data) {
    
    Node * newNode = new Node( data );
    
    if( newNode == NULL ) {
        return false;
    }
    
    if( head == NULL ) {
        head = newNode;
        newNode->setNext( newNode );
        return true;
    }
    
    Node * last = head;
    while( last->getNext() != head ) {
        last = last->getNext();
    }
    
    newNode->setNext( head );
    last->setNext( newNode );
    
    return true;
}

void CircularLinkedList::display() {
    
    if( head == NULL ) {
        return;
    }
    
    Node * temp = head;
    
    do {
        cout<<temp->getData()<<" ";
        temp = temp->getNext();
    }while( temp != head );
    
    cout<<endl;
    
}

bool CircularLinkedList::insert(int data, int position ) {
    
    if( ( head == NULL && position > 1 ) || position <= 0 ) {
        return false;
    }
    
    Node * newNode = new Node( data );
    if( newNode == NULL ) {
        return false;
    }
    
    if( position == 1 ) {
        
        //if the list is empty
        if( head == NULL ) {
            head = newNode;
            newNode->setNext( newNode );
            return true;
        }
        
        //pos is 1, and list is not empty
        //locate last node
        Node * last = head;
        while( last->getNext() != head ) {
            last = last->getNext();
        }
        
        last->setNext( newNode );
        newNode->setNext( head );
        head = newNode;
        
        return true;
    }
    
    Node * prev = head;
    for( int i = 1; i < position - 1; i ++ ) {
        prev = prev->getNext();
        
        if( prev == head ) {
            delete newNode;
            return false;
        }
    }
    
    newNode->setNext( prev->getNext() );
    prev->setNext( newNode );
    
    return true;
    
}

bool CircularLinkedList::deleteByPosition(int position) {
    
    if( position <= 0 || head == NULL ) {
        return false;
    }
    
    if( position == 1 ) {
        
        //if the list is containing only one node
        if( head->getNext() == head ) {
            delete head;
            head = NULL;
            return true;
        }
        
        
        //list has more than a node
        Node * del = head;
        
        //locate last node
        Node * last = head;
        while( last->getNext() != head ) {
            last = last->getNext();
        }
        
        last->setNext( del->getNext() );
        head = head->getNext();
        delete del;
        
        return true;
    }
    
    Node * prev = head;
    for( int i = 1; i < position - 1; i++ ) {
        prev = prev->getNext();
        
        if( prev->getNext() == head ) {
            return false;
        }
    }
    
    Node * del = prev->getNext();
    prev->setNext( del->getNext() );
    delete del;
    
    return true;
    
}

bool CircularLinkedList::deleteByVal(int data) {
    
    if( head == NULL ) {
        return false;
    }
    
    if( head->getData() == data ) {
        
        if( head == head->getNext() ) {
            delete head;
            head = NULL;
            return true;
        }
        
        Node * del = head;
        Node * last = head;
        while( last->getNext() != head ) {
            last = last->getNext();
        }
        
        last->setNext( del->getNext() );
        head = head->getNext();
        delete del;
        
        return true;
    }
    
    Node * prev = head, * del = head;
    while( del->getData() != data ) {
        prev = del;
        del = del->getNext();
        
        if( del == head ) {
            return false;
        }
    }
    
    prev->setNext( del->getNext() );
    delete del;
    
    return true;
}

CircularLinkedList::~CircularLinkedList() {
    
    if( head == NULL ){
        return;
    }
    
    Node * del, * headBK = head;
     do{
        del = head;
        head = head->getNext();
        delete del;
     }while( head != headBK );
}













