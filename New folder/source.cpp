#include "Header.h"

Node::Node( int data) {
    this->data = data;
    left = right = NULL;
}

void Node::setData(int data) {
    this->data = data;
}

int Node::getData() {
    return data;
}

void Node::setLeft( Node * left ) {
    this->left = left;
}

Node * Node::getLeft() {
    return left;
}

void Node::setRight(Node * right) {
    this->right = right;
}

Node * Node::getRight() {
    return right;
}

//BST

BST::BST() {
    root = NULL;
}

bool BST::insert(int data) {
    
    Node * newNode = new Node( data );
    
    if( newNode == NULL ) {
        return false;
    }
    
    if( root == NULL ) {
        root = newNode;
        return true;
    }
    
    Node * temp = root;
    
    while( temp->getData() != data ) {
        
//        if( temp->getData() == data ) {
//            delete newNode;
//            return false;
//        }
        
        if( data < temp->getData() ) {
            //insert to left
            //check if temp has left child
            if( temp->getLeft() == NULL ) {
                temp->setLeft( newNode );
                return true;
            }
            temp = temp->getLeft();
        }
        else {
            //insert to right
            //check if temp has right child
            if( temp->getRight() == NULL ) {
                temp->setRight( newNode );
                return true;
            }
            temp = temp->getRight();
        }
    }
    
    delete newNode;
    return false;
}

void BST::preOrder() {
    
    Node * temp = root;
    Node * stack[100];
    int top = -1;
    
    cout<<"Pre : ";
    while( temp != NULL || top != -1 ) {
        
        while( temp ) {
            cout<<temp->getData()<<" ";
            stack[++top] = temp;
            temp = temp->getLeft();
        }
        
        temp = stack[top--];
        temp = temp->getRight();
        
    }
    cout<<endl;
}


void BST::inOrder() {
    
    Node * temp = root;
    Node * stack[100];
    int top = -1;
    
    cout<<"In : ";
    while( temp != NULL || top != -1 ) {
        
        while( temp ) {
            stack[++top] = temp;
            temp = temp->getLeft();
        }
        
        temp = stack[top--];
        cout<<temp->getData()<<" ";
        temp = temp->getRight();
        
    }
    cout<<endl;
    
}

void BST::postOrder() {
    
    typedef struct {
        Node * address;
        char flag;
    } Pair;
    
    Node * temp = root;
    Pair stack[100];
    int top = -1;
    
    cout<<"Post : ";
    while( temp != NULL || top != -1) {
        
        while( temp ) {
            Pair p;
            p.address = temp; p.flag = 'L';
            stack[++top] = p;
            temp = temp->getLeft();
        }
        
        Pair p = stack[top--];
        
        if( p.flag == 'L') {
            temp = p.address->getRight();
            p.flag = 'R';
            stack[++top] = p;
        }
        else {
            cout<<p.address->getData()<<" ";
        }
    }
    cout<<endl;
}


void BST::preOrder( Node * root ) {
    
    if( root == NULL ) {
        return;
    }
    
    cout<<root->getData()<<" ";
    preOrder( root->getLeft() );
    preOrder( root->getRight() );
    
}

void BST::inOrder(Node * root) {
    if( root == NULL ) {
        return;
    }
    
    inOrder( root->getLeft());
    cout<<root->getData()<<" ";
    inOrder( root->getRight() );
}

void BST::postOrder(Node * root) {
    if( root == NULL ) {
        return;
    }
    
    postOrder( root->getLeft());
    postOrder( root->getRight() );
    cout<<root->getData()<<" ";
    
}















Node * BST::getRoot() {
	return root;
}

int BST::getCount(Node * root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + getCount(root->getLeft()) + getCount(root->getRight());
}

bool BST::deleteData(int data) {
	
	if (root == NULL) {
		return false;
	}

	Node * parent = root, *del = root;

	//locate p and del
	while (del->getData() != data) {
		if (data < del->getData()) {
			parent = del;
			del = del->getLeft();
		}
		else {
			parent = del;
			del = del->getRight();
		}
		//if del becomes null, means data is not existing
		if (del == NULL) {
			return false;
		}
	}

	while (true) {
		//check if del is terminal
		if (del->getLeft() == NULL && del->getRight() == NULL) {

			if (del == root) {
				delete root;
				root = NULL;
				return true;
			}

			if (parent->getLeft() == del) {
				parent->setLeft(NULL);
			}
			else {
				parent->setRight(NULL);
			}
			delete del;
			return true;
		}

		//shift del 
		if (del->getLeft()) {
			//find max from left
			Node * max = del->getLeft();
			parent = del;

			while (max->getRight()) {
				parent = max;
				max = max->getRight();
			}

			int temp = max->getData();
			max->setData(del->getData());
			del->setData(temp);

			del = max;
		}
		else {
			//find min from right
			Node * min = del->getRight();
			parent = del;

			while (min->getLeft()) {
				parent = min;
				min = min->getLeft();
			}

			int temp = del->getData();
			del->setData(min->getData());
			min->setData(temp);

			del = min;
		}
	}
}

void BST::free(Node * root) {
	if (root == NULL)
		return;

	free(root->getLeft());
	free(root->getRight());

	delete root;
}

BST::~BST() {
	free(root);
}