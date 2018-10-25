#include "Header.h"

int main() {

	Graph g1( 9 );
	g1.init();
	g1.display();
	
	cout << endl;

	g1.bfs( 8 );
	g1.dfs( 0 );
	cout << "DFS : ";
	g1.dfsRec(0);
	cout << endl;
	_getch();
	return 0;
}