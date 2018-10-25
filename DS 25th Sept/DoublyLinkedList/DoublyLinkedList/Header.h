#include <iostream>
#include <conio.h>
using namespace std;

class Node {
	int data;
	Node * prev, * next;
public:

	Node(int);

	void setData(int);
	int getData();
	void setNext(Node *);
	Node * getNext();
	void setPrev(Node *);
	Node * getPrev();
}; 

class DoublyLinkedList {
	Node * head, * end;
public:

	DoublyLinkedList();
	bool insert(int);
	bool insert(int, int);
	bool deletebyPos(int);
	bool deleteByVal(int);
	void display();
	~DoublyLinkedList();
};
