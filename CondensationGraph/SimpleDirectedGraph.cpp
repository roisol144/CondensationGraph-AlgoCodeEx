#include "SimpleDirectedGraph.h"
#include "MyExceptions.h"

void SimpleDirectedGraph::makeEmptyGraph(int n) {
	this->vertices.clear();
	this->vertices.resize(n);
	for (int i = 0; i < n; i++) {
		vertices[i] = new Vertex();
		vertices[i]->setVertexIndex(i + 1);
	}
}

void SimpleDirectedGraph::isValidVertices(int u, int v, int numOfVertices)
{
	if (u > numOfVertices || u < 1 || v < 1 || v > numOfVertices)
	{
		throw OutOfBoundsException();
	}
	if (!isdigit('0' + u) || !isdigit('0' + v))
	{
		throw WrongTypeException();
	}
}


bool SimpleDirectedGraph::isAdjacent(int u, int v) {
	return find((*vertices[u - 1]->getVertexAdjacentList()).begin(),
				(*vertices[u - 1]->getVertexAdjacentList()).end(), v) != (*vertices[u - 1]->getVertexAdjacentList()).end();
}

list<int> SimpleDirectedGraph::getAdjList(int u) {
	return *vertices[u-1]->getVertexAdjacentList();
}

void SimpleDirectedGraph::addEdge(int u, int v) {
	vertices[u - 1]->addNeighbor(v);
}

void SimpleDirectedGraph::removeEdge(int u, int v) {
	vertices[u-1]->removeNeighbor(v);
}

void SimpleDirectedGraph::printGraph() {
	int index = 1;
	for (Vertex* u : vertices) {
		cout << u->getVertexIndex() << "-> ";
		for (int v : *u->getVertexAdjacentList()) {
			cout << v << ", ";
		}
		index++;
		cout << endl;
	}
}



list<int> SimpleDirectedGraph::finishedListDFS()
{
	list<int> finishedList;
	
	for(Vertex* v: vertices)
	{
		if (v->getVertexColor() == 0)
		{
			visit(v, &finishedList);
		}
	}
	return finishedList;
}

void SimpleDirectedGraph::visit(Vertex* v, list<int>* finishedList)
{
	v->setVertexColor(1);
	/*for (list<int>::iterator i = (*v->getVertexAdjacentList()).begin(); i != (*v->getVertexAdjacentList()).end(); ++i) {
		if (vertices[*i - 1]->getVertexColor() == 0) {
			visit(vertices[*i - 1], finishedList);
		}
	}*/
	for (int u: *v->getVertexAdjacentList()) {
		if (vertices[u - 1]->getVertexColor() == 0) {
			visit(vertices[u - 1], finishedList);
		}
	}
	finishedList->push_back(v->getVertexIndex());
	v->setVertexColor(2);

}

SimpleDirectedGraph SimpleDirectedGraph::getTransposeGraph() {
	SimpleDirectedGraph gT;
	gT.makeEmptyGraph(vertices.size());

	for (Vertex* v : vertices) {
		for (int u : *v->getVertexAdjacentList()) {
			gT.addEdge(u, v->getVertexIndex());
		}
	}
	return gT;
}
