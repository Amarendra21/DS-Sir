#include "Header.h"

Node::Node( int data) {
    this->data = data;
    left = right = NULL;
	lFlag = rFlag = 'T';
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

void Node::setLFlag(char lFlag) {
	this->lFlag = lFlag;
}

char Node::getLFlag() {
	return lFlag;
}

void Node::setRFlag(char rFlag) {
	this->rFlag = rFlag;
}

char Node::getRFlag() {
	return rFlag;
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
       
        if( data < temp->getData() ) {
            //insert to left
            //check if temp has left child
            if( temp->getLFlag() == 'T' ) {
				newNode->setRight(temp);
				newNode->setLeft(temp->getLeft());
				temp->setLeft(newNode);
				temp->setLFlag('L');
                return true;
            }
            temp = temp->getLeft();
        }
        else {
            //insert to right
            //check if temp has right child
            if( temp->getRFlag() == 'T' ) {
				newNode->setLeft(temp);
				newNode->setRight(temp->getRight());
				temp->setRight(newNode);
				temp->setRFlag('L');
                return true;
            }
            temp = temp->getRight();
        }
    }
    
    delete newNode;
    return false;
}




void BST::inOrder() {
    
    Node * temp = root;
	char flag = 'L';
	cout << "InOrder : ";

	while ( temp ) {

		//while temp has left child, shift temp to left
		while (temp->getLFlag() == 'L' && flag == 'L') {
			temp = temp->getLeft();
		}
		//visit temp
		cout << temp->getData() << " ";
		flag = temp->getRFlag();
		temp = temp->getRight();
	}
    cout<<endl;
    
}


void BST::preOrder() {

	Node * temp = root;
	char flag = 'L';
	cout << "PreOrder : ";

	while (temp) {

		//while temp has left child, shift temp to left
		while (temp->getLFlag() == 'L' && flag == 'L') {
			cout << temp->getData() << " ";
			temp = temp->getLeft();
		}
		if (flag == 'L') {
			cout << temp->getData() << " ";
		}
		flag = temp->getRFlag();
		temp = temp->getRight();
	}
	cout << endl;

}

bool BST::isRightChild(Node * node) {

	if (node == root) {
		return false;
	}

	Node * temp = root;

	while (true) {
		if (node->getData() < temp->getData()) {
			temp = temp->getLeft();
			if (temp == node) {
				return false;
			}
		}
		else {
			temp = temp->getRight();
			if (temp == node) {
				return true;
			}
		}
	}

}

void BST::postOrder() {
	Node * temp = root;
	char flag = 'L';

	cout << "postorder : ";
	while (temp) {

		while (temp->getLFlag() == 'L' && flag == 'L') {
			temp = temp->getLeft();
		}

		flag = temp->getRFlag();

		if (flag == 'L') {
			temp = temp->getRight();
		}
		else {
			while (true) {
				cout << temp->getData()<<" ";
				bool isRight = isRightChild(temp);
				if (isRight) {
					while (temp->getLFlag() == 'L') {
						temp = temp->getLeft();
					}
					temp = temp->getLeft();
				}
				else {
					while (temp->getRFlag() == 'L') {
						temp = temp->getRight();
					}
					temp = temp->getRight();
					break;
				}
			}
		}
	}
	cout << endl;
}

bool BST::deleteData(int data) {

	//locate del along with parent
	Node * parent = root, *del = root;
	while (del->getData() != data) {
		if (data < del->getData()) {
			if (del->getLFlag() == 'T') {
				return false;
			}
			parent = del;
			del = del->getLeft();
		}
		else {
			if (del->getRFlag() == 'T') {
				return false;
			}
			parent = del;
			del = del->getRight();
		}
	}

	while (true) {
		//if del is terminal, delete del and return true
		if (del->getLFlag() == 'T' && del->getRFlag() == 'T') {

			if (del == root) {
				delete root;
				root = NULL;
				return true;
			}

			if (del == parent->getLeft()) {
				//del is left child
				parent->setLeft(del->getLeft());
				parent->setLFlag('T');	
			}
			else {
				//del is right child
				parent->setRight(del->getRight());
				parent->setRFlag('T');
			}
			delete del;
			return true;
		}

		//else  shift del down the tree

		if (del->getLFlag() == 'L') {
			//find max from left
			Node * max = del->getLeft();
			parent = del;
			while (max->getRFlag() == 'L') {
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

			while (min->getLFlag() == 'L') {
				parent = min;
				min = min->getLeft();
			}

			int temp = min->getData();
			min->setData(del->getData());
			del->setData(temp);

			del = min;
		}

	}

}












void BST::freeTree(Node * root) {
	
	if (root == NULL) {
		return;
	}

	if (root->getLFlag() == 'L') {
		freeTree(root->getLeft());
	}
	if (root->getRFlag() == 'L') {
		freeTree(root->getRight());
	}

	delete root;
}

BST::~BST() {
	freeTree(root);
}




