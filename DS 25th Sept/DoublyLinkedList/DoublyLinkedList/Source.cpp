#include "Header.h"

Node::Node(int data) {
	this->data = data;
	prev = next = NULL;
}

void Node::setData(int data) {
	this->data = data;
}

int Node::getData() {
	return data;
}

void Node::setPrev(Node * prev) {
	this->prev = prev;
}

Node * Node::getPrev() {
	return prev;
}




void Node::setNext(Node * next) {
	this->next = next;
}

Node * Node::getNext() {
	return next;
}


DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
}

bool DoublyLinkedList::insert(int data) {

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
	newNode->setPrev(last);

	return true;

}

void DoublyLinkedList::display() {

	Node * temp = head;

	while (temp != NULL ) {
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}
	cout << endl;
}

bool DoublyLinkedList::insert(int data, int position) {

	if (position <= 0 || (head == NULL && position > 1)) {
		return false;
	}

	Node * newNode = new Node(data);
	if (newNode == NULL) {
		return false;
	}

	if (position == 1) {
		if (head != NULL) {
			newNode->setNext(head);
			head->setPrev(newNode);
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

	newNode->setPrev(prev);
	if (prev->getNext() != NULL) {
		newNode->setNext(prev->getNext());
		prev->getNext()->setPrev(newNode);
	}
	prev->setNext(newNode);

	return true;




}

bool DoublyLinkedList::deletebyPos(int position) {

	if (position <= 0 || head == NULL ) {
		return false;
	}

	if (position == 1) {
		Node * del = head;
		head = head->getNext();
		if (head != NULL) {
			head->setPrev(NULL);
		}
		delete del;
		return true;
	}

	Node * del = head;
	for (int i = 1; i < position; i++) {
		del = del->getNext();
		if (del == NULL) {
			return false;
		}
	}

	del->getPrev()->setNext(del->getNext());
	if (del->getNext() != NULL) {
		del->getNext()->setPrev(del->getPrev());
	}

	delete del;
	return true;


}

bool DoublyLinkedList::deleteByVal(int data) {

	if ( head == NULL) {
		return false;
	}

	if ( head->getData() == data ) {
		Node * del = head;
		head = head->getNext();
		if (head != NULL) {
			head->setPrev(NULL);
		}
		delete del;
		return true;
	}

	Node * del = head;
	while( del->getData() != data ){
		del = del->getNext();
		if (del == NULL) {
			return false;
		}
	}

	del->getPrev()->setNext(del->getNext());
	if (del->getNext() != NULL) {
		del->getNext()->setPrev(del->getPrev());
	}

	delete del;
	return true;


}

DoublyLinkedList::~DoublyLinkedList() {

	Node * del;
	while (head != NULL) {
		del = head;
		head = head->getNext();
		delete del;
	}

}