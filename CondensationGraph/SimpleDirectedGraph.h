#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <list>
using namespace std;
class SimpleDirectedGraph {
private:
	int n;
	int m;
	vector<list<int>> adjacentArr;

public:
	// created empty graph with n vertices.
	void makeEmptyGraph(int n);

	//returns true if the edge (u,v) is in the graph, false otherwise.
	bool isAdjacent(int u, int v);

	//returns linked list of the neighbors of vertex u
	list<int> getAdjList(int u);

	//adds the edge (u,v) to the graph
	void addEdge(int u, int v);

	//removes the edge (u,v) from the graph
	void removeEdge(int u, int v);

	//prints the adjacent array of the graph
	void printGraph();
};