#include <iostream>
#include <conio.h>
using namespace std;

class Graph {
	char * vertices;
	int noOfVertices;
	int ** adjMat;
public:
	Graph(int);
	void init();
	void display();
	void bfs( int );
	void dfs(int);
	void dfsRec(int);
	~Graph();
};