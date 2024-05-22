#include <iostream>
using namespace std;
#include "SimpleDirectedGraph.h"
#include <stdlib.h>
 // TODO - Error check
void main() {
	int n,m;
	SimpleDirectedGraph g;
	cout << "Enter how many vertices:" << endl;
	cin >> n;
	cout << "Enter how many edges:" << endl;
	cin >> m;

	g.makeEmptyGraph(n);
	int u, v;
	for (int i = 0; i < m; i++) {
		cout << "edge number " << (i + 1) << ":" << endl;
		cin >> u >> v;
		if (u > n || u < 1 || v < 1 || v > n || !isdigit('0' + u) || !isdigit('0' + v))
		{
			cout << "Invalid input" << endl;
			exit(1);
		}

		g.addEdge(u, v);
	}
	cout << "ORIGINAL:" << endl;
	g.printGraph();

	list<int> finish = g.finishedListDFS();
	for (int i : finish) {
		cout << i << ", ";
	}
	cout << endl << "TRANSPOSE" << endl;;
	SimpleDirectedGraph gT = g.getTransposeGraph();
	gT.printGraph();
}

// TODO
// 1. DFS functions
// 2. Build G^T
// 3. 


// 4 , 2 , 3, 1, 6, 5

