#include "Header.h"

int main(int argc, const char * argv[]) {
    
    BST t1; 
    t1.insert( 50 );
    t1.insert( 20 );
    t1.insert( 10 );
    t1.insert( 30 );
    t1.insert( 80 );
    t1.insert( 60 );
    t1.insert( 100 );
    
    t1.preOrder();
	t1.preOrder( t1.getRoot() );
	cout << endl;
    t1.inOrder();
	t1.inOrder(t1.getRoot());
	cout << endl;
    t1.postOrder();
	t1.postOrder(t1.getRoot());
	cout << endl;

	cout << t1.getCount(t1.getRoot()) << endl << endl;;

	//t1.free( t1.getRoot() );

	t1.deleteData(50);
	t1.preOrder();
	t1.inOrder();
	t1.postOrder();

	cout << endl;

	t1.deleteData(50);
	t1.preOrder();
	t1.inOrder();
	t1.postOrder();

	_getch();
    return 0;
}
