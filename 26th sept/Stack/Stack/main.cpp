#include "Header.h"

int main(int argc, const char * argv[]) {
    
    Stack s( 3 );
    
    cout<<s.pop()<<endl;
    cout<<s.push( 10 )<<endl;
    cout<<s.push( 20 )<<endl;
    cout<<s.push( 30 )<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    
    return 0;
}
