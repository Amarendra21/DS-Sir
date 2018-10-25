#include "Defs.h"

int main(int argc, const char * argv[]) {
    
    CircularLinkedList c1;
    c1.display();
    c1.insert( 10 );
    c1.insert( 20 );
    c1.insert( 30 );
    c1.display();
    c1.insert(40, 1);
    c1.display();
    c1.insert(50, 4);
    c1.display();
    c1.insert(60, 6);
    c1.display();
    c1.insert(70, 9);
    c1.display();
    
    c1.deleteByVal( 40 );
    c1.display();
    c1.deleteByVal( 50 );
    c1.display();
    c1.deleteByVal( 60 );
    c1.display();
    c1.deleteByVal( 60 );
    c1.display();
    
//    c1.deleteByPosition(1);
//    c1.display();
//    c1.deleteByPosition(3);
//    c1.display();
//    c1.deleteByPosition(4);
//    c1.display();
//    c1.deleteByPosition(4);
//    c1.display();
    
    return 0;
}
