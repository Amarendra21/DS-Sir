#include "Header.h"

int main() {
	{
		LinkedList l1;

		l1.insert(10);
		l1.insert(20);
		l1.insert(30);
		l1.insert(40);
		l1.display();
		l1.insert(50, 1);
		l1.display();
		l1.insert(60, 4);
		l1.display();
		l1.insert(70, 7 );
		l1.display();
		l1.insert(90, 9 );
		l1.display();
		l1.deleteByPos(1);
		l1.display();
		l1.deleteByPos(3);
		l1.display();
		l1.deleteByPos(5);
		l1.display();
		l1.deleteByPos(5);
		l1.display();
	}
	_getch();
	return 0;
}