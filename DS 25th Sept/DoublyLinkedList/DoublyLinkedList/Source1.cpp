#include "Header.h"

int main() {

	DoublyLinkedList d1;

	d1.insert(10);
	d1.insert(20);
	d1.insert(30);
	d1.insert(40);
	d1.display();
	d1.insert(50, 1);
	d1.display();
	d1.insert(60, 4);
	d1.display();
	d1.insert(70, 7);
	d1.display();
	d1.insert(80, 9);
	d1.display();

	d1.deleteByVal(50);
	d1.display();
	d1.deleteByVal(60);
	d1.display();
	d1.deleteByVal(70);
	d1.display();
	d1.deleteByVal(50);
	d1.display();

	_getch();




	return 0;
}