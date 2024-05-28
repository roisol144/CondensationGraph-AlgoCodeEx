#include "SimpleDirectedGraph.h"
#include "MyExceptions.h"

void SimpleDirectedGraph::setN(int num) {
	n = num;
}

void SimpleDirectedGraph::setM(int num) {
	m = num;
}

void SimpleDirectedGraph::makeEmptyGraph(int n) {
	if (n < 0 || m < 0)
	{
		throw ValueNotSupportedException();
	}
	this->vertices.clear();
	this->vertices.resize(n);
	for (int i = 0; i < n; i++) {
		vertices[i] = new Vertex(i+1);
		vertices[i]->setVertexIndex(i + 1);
	}
}

void SimpleDirectedGraph::isValidVertices(int u, int v, int numOfVertices)
{
	if (u > numOfVertices || u < 1 || v < 1 || v > numOfVertices)
	{
		throw OutOfBoundsException();
	}
	if (u == v)
	{
		throw InvalidEdgeException();
	}
	if (n < 0 || m < 0)
	{
		throw ValueNotSupportedException();
	}
}


bool SimpleDirectedGraph::isAdjacent(int u, int v) {
	for (int vIndex : *vertices[u - 1]->getVertexAdjacentList()) {
		if (v == vIndex)
			return true;
	}
	return false;
}

list<int> SimpleDirectedGraph::getAdjList(int u) {
	return *vertices[u-1]->getVertexAdjacentList();
}

void SimpleDirectedGraph::addEdge(int index, int u, int v) {
	vertices[index]->addNeighbor(v);
}

void SimpleDirectedGraph::removeEdge(int u, int v) {
	vertices[u-1]->removeNeighbor(v);
}

void SimpleDirectedGraph::printGraph() {
	int index = 1;
	for (Vertex* u : vertices) {
		cout << "("<< u->getRepresentative() <<")" << u->getVertexIndex() << "-> ";
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
			visitForFinishListDFS(v, &finishedList);
		}
	}
	return finishedList;
}

void SimpleDirectedGraph::visitForFinishListDFS(Vertex* v, list<int>* finishedList)
{
	v->setVertexColor(1);

	for (int u: *v->getVertexAdjacentList()) {
		if (vertices[u - 1]->getVertexColor() == 0) {
			visitForFinishListDFS(vertices[u - 1], finishedList);
		}
	}
	finishedList->push_back(v->getVertexIndex());
	v->setVertexColor(2);

}

SimpleDirectedGraph SimpleDirectedGraph::treesDFS(list<int> loopOrder) {
	vector<SimpleDirectedGraph*> treesArray;
	SimpleDirectedGraph condensationGraph;
	for (int v : loopOrder) {
		if (vertices[v-1]->getVertexColor() == 0) { // I'm white, I'm root of new tree! 
			condensationGraph.vertices.push_back(new Vertex(v));
			condensationGraph.n++;
			treesArray.push_back(new SimpleDirectedGraph);
			treesArray.back()->vertices.push_back(new Vertex(v, v));
			vertices[v - 1]->setRepresentative(v);
			vertices[v - 1]->setRepIndex(condensationGraph.vertices.size() - 1);
			visitForTreesDFS(vertices[v - 1], treesArray.back(),&condensationGraph);
		}
	}
	return condensationGraph;
}

void SimpleDirectedGraph::visitForTreesDFS(Vertex* v, SimpleDirectedGraph* tree, SimpleDirectedGraph* condensationGraph) {
	v->setVertexColor(1); // make v grey
	int lastVertexIndexInArray = tree->vertices.size()-1;
	for (int u : *v->getVertexAdjacentList()) {
		if (vertices[u - 1]->getVertexColor() == 0) {
			vertices[u - 1]->setRepresentative(tree->vertices[0]->getVertexIndex());
			vertices[u - 1]->setRepIndex(condensationGraph->vertices.size() - 1);
			tree->vertices.push_back(new Vertex(u, tree->vertices[0]->getVertexIndex()));
			tree->addEdge(lastVertexIndexInArray, v->getVertexIndex(), u);
			visitForTreesDFS(vertices[u - 1], tree, condensationGraph);
		}
		//other tree
		if (v->getRepresentative() != vertices[u - 1]->getRepresentative() && vertices[u-1]->getVertexColor()==2) {	
			if (!condensationGraph->vertices[vertices[u - 1]->getRepIndex()]->getVertexAdjacentList()->size()) {
				condensationGraph->vertices[vertices[u - 1]->getRepIndex()]->getVertexAdjacentList()->push_back(v->getRepresentative());
				condensationGraph->m++;
			}
			else if (condensationGraph->vertices[vertices[u - 1]->getRepIndex()]->getVertexAdjacentList()->back() != v->getRepresentative()) {
				condensationGraph->vertices[vertices[u - 1]->getRepIndex()]->getVertexAdjacentList()->push_back(v->getRepresentative());
				condensationGraph->m++;
			}
		}
		
	}
	v->setVertexColor(2); // make v black
}


SimpleDirectedGraph SimpleDirectedGraph::getTransposeGraph() {
	SimpleDirectedGraph gT;
	gT.makeEmptyGraph(vertices.size());

	for (Vertex* v : vertices) {
		for (int u : *v->getVertexAdjacentList()) {
			gT.addEdge(u-1, u, v->getVertexIndex());
		}
	}
	return gT;
}

void SimpleDirectedGraph::resetColors() {
	for (Vertex* v : this->vertices) {
		v->setVertexColor(0);
	}
}
