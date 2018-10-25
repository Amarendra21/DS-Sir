#include "Header.h"

int main(int argc, const char * argv[]) {
    
    CircularQueue q1( 5 );
    
    cout<<"ins : "<<q1.insert( 10 )<<endl;
    cout<<"ins : "<<q1.insert( 20 )<<endl;
    cout<<"ins : "<<q1.insert( 30 )<<endl;
    cout<<"ins : "<<q1.insert( 40 )<<endl;
    cout<<"ins : "<<q1.insert( 50 )<<endl;
    cout<<"ins : "<<q1.insert( 60 )<<endl;
    
    cout<<"del : "<<q1.deleteData()<<endl;
    cout<<"ins : "<<q1.insert( 60 )<<endl;
    
    /*
    cout<<"del : "<<q1.deleteData()<<endl;
    cout<<"del : "<<q1.deleteData()<<endl;
    
    cout<<"ins : "<<q1.insert( 30 )<<endl;
    cout<<"ins : "<<q1.insert( 40 )<<endl;
    cout<<"ins : "<<q1.insert( 50 )<<endl;
    
    cout<<"del : "<<q1.deleteData()<<endl;
    cout<<"del : "<<q1.deleteData()<<endl;
    cout<<"del : "<<q1.deleteData()<<endl;
    
    cout<<"E : "<<q1.isEmpty()<<" f : "<<q1.isFull()<<endl;
    */
    
    return 0;
}









