#include <iostream>
#include <conio.h>
using namespace std;

class Node {
	int data;
	Node * next;
public:

	Node(int);

	void setData(int);
	int getData();
	void setNext(Node *);
	Node * getNext();
};

class LinkedList {
	Node * head;
public:
	LinkedList();
	~LinkedList();

	bool insert(int);
	bool insert(int, int);
	bool deleteByPos(int);
	void display();
};