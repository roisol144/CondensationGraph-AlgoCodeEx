#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <iterator>
using namespace std;
class Vertex
{
private:
	int index;
	list<int> adjacentList;
	int color = 0;


public:

	
	int getVertexIndex()
	{
		return index;
	}
	list<int>* getVertexAdjacentList()
	{
		return &adjacentList;
	}

	void addNeighbor(int v) {
		adjacentList.push_back(v);
		
	}

	void removeNeighbor(int v) {
		adjacentList.remove(v);
	
	}

	int getVertexColor()
	{
		return color;
	}

	void setVertexIndex(int index)
	{
		this->index = index;
	}
	
	void setVertexColor(int color)
	{
		this->color = color;
	}

};



