#include "Header.h"

Graph::Graph(int noOfVertices) {
	this->noOfVertices = noOfVertices;
	vertices = new char[noOfVertices];

	adjMat = new int *[noOfVertices];
	for (int i = 0; i < noOfVertices; i++) {
		adjMat[i] = new int[noOfVertices];
	}
}

Graph::~Graph() {
	delete[] vertices;
	for (int i = 0; i < noOfVertices; i++) {
		delete[] adjMat[i];
	}
	delete [] adjMat;
}

void Graph::init() {
	cin.clear();
	cout << "Enter vertices : " << endl;
	for (int i = 0; i < noOfVertices; i++) {
		//cin >> vertices[i];
		vertices[i] = 65 + i;
	}

	int arr[] = { 0,1,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0 };
	int k = 0;


	cout << "Enter connectivity info : " << endl;
	for (int i = 0; i < noOfVertices; i++) {
		for (int j = 0; j < noOfVertices; j++) {
			//cout << "Edge between " << vertices[i] << " & " << vertices[j] << endl;
			//cin >> adjMat[i][j];
			adjMat[i][j] = arr[k++];
		}
	}
}

void Graph::display() {
	cout << "  ";
	for (int i = 0; i < noOfVertices; i++) {
		cout << vertices[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < noOfVertices; i++) {
		cout << vertices[i] << " ";
		for (int j = 0; j < noOfVertices; j++) {
			cout << adjMat[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::bfs(int v) {

	int * visited = new int[noOfVertices] { 0 };
	int q[100];
	int front = -1, rear = -1;

	q[0] = v;
	front = rear = 0;
	cout << "BFS : ";
	while (front <= rear) {

		v = q[front++];
		if (visited[v] == 0) {
			cout << vertices[v] << " ";
			visited[v] = 1;

			for (int i = 0; i < noOfVertices; i++) {
				if (adjMat[v][i] == 1 && visited[i] == 0) {
					q[++rear] = i;
				}
			}
		}

	}
	cout << endl;
	delete[] visited;
}

void Graph::dfs(int v) {

	int * visited = new int[noOfVertices] { 0 };
	int stack[100];
	int top = -1;

	cout << "DFS : ";
	cout << vertices[v] << " ";
	visited[v] = 1;
	stack[++top] = v;

	while (top != -1) {

		for (int i = 0; i < noOfVertices; i++) {
			if (adjMat[v][i] == 1 && visited[i] == 0) {
				cout << vertices[i] << " ";
				visited[i] = 1;
				stack[++top] = i;
				v = i;
				i = -1;
			}
		}

		v = stack[top--];
	}
	cout << endl;

}

void Graph::dfsRec(int v) {
	
	 static int visited[100] = { 0 };

	if (visited[v] == 0) {
		cout << vertices[v] << " ";
		visited[v] = 1;
		for (int i = 0; i < noOfVertices; i++) {
			if (adjMat[v][i] == 1 && visited[i] == 0) {
				dfsRec(i);
			}
		}
	}

}