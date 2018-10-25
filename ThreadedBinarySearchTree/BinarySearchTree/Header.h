#include <iostream>
#include <conio.h>
using namespace std;

class Node {
    int data;
    Node * left, * right;
	char lFlag, rFlag;
public:
    Node( int data );
    void setData( int  );
    int getData();
    void setLeft( Node * );
    Node * getLeft();
    void setRight( Node * );
    Node * getRight();
	void setLFlag(char);
	char getLFlag();
	void setRFlag(char);
	char getRFlag();
};

class BST {
    Node * root;
	bool isRightChild(Node *);
	void freeTree(Node *);
public:
    BST();
    bool insert( int data );
    void inOrder();
    void preOrder();
    void postOrder();
	bool deleteData(int); 
	~BST();
};














