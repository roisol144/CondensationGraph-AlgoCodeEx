#include "SimpleDirectedGraph.h"

void SimpleDirectedGraph::makeEmptyGraph(int n) {
	this->adjacentArr.clear();
	this->adjacentArr.resize(n);
}

bool SimpleDirectedGraph::isAdjacent(int u, int v) {
	return (find(adjacentArr[u].begin(), adjacentArr[u].end(), v) != adjacentArr[u].end());
}

list<int> SimpleDirectedGraph::getAdjList(int u) {
	return adjacentArr[u];
}

void SimpleDirectedGraph::addEdge(int u, int v) {
	adjacentArr[u].push_back(v);
}

void SimpleDirectedGraph::removeEdge(int u, int v) {
	adjacentArr[u].remove(v);
}

void SimpleDirectedGraph::printGraph() {
	int index = 1;
	for (list<int> u : adjacentArr) {
		cout << index << "-> ";
		for (int v : u) {
			cout << v+1 << ", ";
		}
		index++;
		cout << endl;
	}
}