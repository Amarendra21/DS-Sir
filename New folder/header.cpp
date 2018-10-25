#include <iostream>
#include <conio.h>
using namespace std;

class Node {
    int data;
    Node * left, * right;
public:
    Node( int data );
    void setData( int  );
    int getData();
    void setLeft( Node * );
    Node * getLeft();
    void setRight( Node * );
    Node * getRight();
};

class BST {
    Node * root;
	void free(Node *);
public:
    BST();
    bool insert( int data );
    void inOrder();
    void preOrder();
    void postOrder();
    
    void inOrder( Node * );
    void preOrder( Node * );
    void postOrder( Node * );

	Node * getRoot();
	int getCount( Node * );

	bool deleteData(int);
	~BST();
	
};














