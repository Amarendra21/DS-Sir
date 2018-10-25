#include "Header.h"

int main() {
	{
		LinkedList l1;

		l1.insert(10);
		l1.insert(20);
		l1.insert(30);
		l1.insert(40);
		l1.insert(20);
		l1.display();
		l1.insert(50, 1);
		l1.display();
		l1.insert(60, 2);
		l1.display();

		l1.reverse();
		l1.display();
		
		//l1.displayRev();
		//l1.displayRev( l1.getHead() ); 
		//cout << endl;

		//while(l1.deleteByVal(20))
			//;

		 
	}
	_getch();
	return 0;
}