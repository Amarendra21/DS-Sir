#include "Header.h"

int main(int argc, const char * argv[]) {
    
    BST t1; 
    t1.insert( 50 );
    t1.insert( 30 );
    t1.insert( 20 );
    t1.insert( 25 );
    t1.insert( 40 );
    t1.insert( 45 );
    t1.insert( 90 );
	t1.insert(60);
	t1.insert(80);
	t1.insert(100);

	t1.inOrder();
	t1.preOrder();
	t1.postOrder();
    
	t1.deleteData(50);
	cout << endl;

	t1.inOrder();
	t1.preOrder();
	t1.postOrder();
   
	t1.deleteData(50);
	cout << endl;

	t1.inOrder();
	t1.preOrder();
	t1.postOrder();

	_getch();
    return 0;
}
