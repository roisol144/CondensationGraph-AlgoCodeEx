#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include "Vertex.h"
using namespace std;
class SimpleDirectedGraph {
private:
	int n;
	int m;
	vector<Vertex*> vertices;

public:
	int getN() { return n; }
	int getM() { return m; }
	void setN(int num);
	void setM(int num);

	// created empty graph with n vertices.
	void makeEmptyGraph(int n);

	// checking valid Vertices
	void isValidVertices(int u, int v, int numOfVertices);

	//returns true if the edge (u,v) is in the graph, false otherwise.
	bool isAdjacent(int u, int v);

	//returns linked list of the neighbors of vertex u
	list<int> getAdjList(int u);

	//adds the edge (u,v) to the graph
	void addEdge(int index, int u, int v);

	//removes the edge (u,v) from the graph
	void removeEdge(int u, int v);

	//prints the adjacent array of the graph
	void printGraph();

	list<int> finishedListDFS();

	void visitForFinishListDFS(Vertex* v, list<int>* finishedList);

	SimpleDirectedGraph getTransposeGraph();
	
	SimpleDirectedGraph treesDFS(list<int> loopOrder);

	void visitForTreesDFS(Vertex* v, SimpleDirectedGraph* tree, SimpleDirectedGraph* condensationGraph);

	void resetColors();

};



