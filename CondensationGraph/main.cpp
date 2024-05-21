#include <iostream>
using namespace std;
#include "SimpleDirectedGraph.h"

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
		g.addEdge(u-1, v-1);
	}
	g.printGraph();
}