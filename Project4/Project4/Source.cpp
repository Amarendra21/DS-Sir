#include "Header.h"

Node::Node(int data) {
	this->data = data;
	next = NULL;
}

void Node::setData(int data) {
	this->data = data;
}

int Node::getData() {
	return data;
}

void Node::setNext(Node * next) {
	this->next = next;
}

Node * Node::getNext() {
	return next;
}


LinkedList::LinkedList() {
	head = NULL;
}

bool LinkedList::insert(int data) {
	
	Node * newNode = new Node(data);

	if (newNode == NULL) {
		return false;
	}

	if (head == NULL) {
		head = newNode;
		return true;
	}

	Node * last = head;

	while (last->getNext() != NULL) {
		last = last->getNext();
	}
	
	last->setNext(newNode);
	return true;
}

void LinkedList::display() {

	Node * temp = head;

	while (temp != NULL) {
		cout << temp->getData()<<" ";
		temp = temp->getNext();
	}
	cout << endl;

}

LinkedList::~LinkedList() {
	Node * temp ;

	while ( head ) {
		temp = head;
		head = temp->getNext();
		//cout << "del : " << temp->getData();
		delete temp;
	}
}

bool LinkedList::insert(int data, int position ) {

	if (position <= 0 || ( head == NULL && position > 1 )) {
		return false;
	}

	Node * newNode = new Node(data);

	if (newNode == NULL) {
		return false;
	}

	if (position == 1) {
		if (head != NULL) {
			newNode->setNext(head);
		}
		head = newNode;
		return true;
	}

	Node * prev = head;

	for (int i = 1; i < position - 1; i++) {
		prev = prev->getNext();

		if (prev == NULL) {
			delete newNode;
			return false;
		}
	}

	newNode->setNext(prev->getNext());
	prev->setNext(newNode);

	return true;
}


bool LinkedList::deleteByPos(int position) {

	if (position <= 0) {
		return false;
	}

	if (position == 1) {
		Node * del = head;
		head = head->getNext();
		delete del;
		return true;
	}

	Node * prev = head;
	for (int i = 1; i < position - 1; i++) {
		prev = prev->getNext();
		if (prev == NULL) {
			return false;
		}
	}

	Node * del = prev->getNext();
	prev->setNext( del->getNext() );

	delete del;

	return true;
}






