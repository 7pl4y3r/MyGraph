// GraphDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Graph.h"

void testGraph() {

	Graph::Node *f = 0;

	Graph::add(f, 1);
	Graph::addEdge(f->f, 2);
	Graph::addEdge(f->f, 3);

	Graph::add(f, 2);
	Graph::addEdge(Graph::getLast(f)->f, 1);
	Graph::addEdge(Graph::getLast(f)->f, 3);

	Graph::add(f, 3);
	Graph::addEdge(Graph::getLast(f)->f, 1);
	
	Graph::printNodes(f);
}

int main()
{
	testGraph();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
