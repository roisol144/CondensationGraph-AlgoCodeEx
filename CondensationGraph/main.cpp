#include <iostream>
using namespace std;
#include "SimpleDirectedGraph.h"
#include "MyExceptions.h"
#include <stdlib.h>
int main() {
	int n,m;
	SimpleDirectedGraph g;
	//cout << "Enter how many vertices:" << endl;
	cin >> n;
	//cout << "Enter how many edges:" << endl;
	cin >> m;

	g.setN(n);
	g.setM(m);

	try {
		g.makeEmptyGraph(n);
	}
	catch (ValueNotSupportedException exception)
	{
		cout << "Invalid Input." << endl;
		exit(1);
	}
	int u, v;
	for (int i = 0; i < m; i++) {
	//	cout << "edge number " << (i + 1) << ":" << endl;
		cin >> u >> v;
		try {
			g.isValidVertices(u, v, n);
		}
		catch(OutOfBoundsException exception){
			cout << "Invalid Input." << endl;
			exit(1);
		}
		catch (InvalidEdgeException exception) {
			cout << "Invalid Input." << endl;
			exit(1);
		}


		g.addEdge(u-1,u, v);
	}
	//cout << "ORIGINAL:" << endl;
	//g.printGraph();

	list<int> reversedFinishList = g.finishedListDFS();
	reversedFinishList.reverse();
	/*for (int i : reversedFinishList) {
		cout << i << ", ";
	}*/
	g.resetColors();
	//cout << endl << "TRANSPOSE" << endl;;
	SimpleDirectedGraph gT = g.getTransposeGraph();
	//gT.printGraph();


	SimpleDirectedGraph condensationGraph = gT.treesDFS(reversedFinishList);
	//cout << "Condensation graph:" << endl;
	//condensationGraph.printGraph();
	cout <<condensationGraph.getN() <<" " << condensationGraph.getM() << endl;
	return 0;
}

// TODO
// 1. DFS functions
// 2. Build G^T
// 3. 


// 4 , 2 , 3, 1, 6, 5

/*
6
8
1 2
1 3
3 2
2 4
4 3
5 4
5 6
6 5
*/


/*
6
4
1 4
2 3
2 5
4 6
*/
