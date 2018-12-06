// GraphDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Graph.h"

#include <iostream>

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
	
	//Graph::printNodes(f);
}

void createGraph(Graph::Node *&f, int len) {

	f = 0;
	int edgeLen, id;
	for (int i = 0; i < len; i++) {

		std::cout << "Node " << i + 1 << " id...\n";
		std::cin >> id;
		std::cout << "Number of edges...\n";
		std::cin >> edgeLen;

		Graph::add(f, id);
		for(int j = 0; j < edgeLen; j++) {
		
			std::cout << "Edge " << j + 1 << " id...\n";
			std::cin >> id;
			Graph::addEdge(Graph::getLast(f)->f, id);
		
		}
	}
}

void createList(Graph::Edge *&f, int len) {

	int id;
	for (int i = 0; i < len; i++) {

		std::cout << "Element " << i + 1 << " id...\n";
		std::cin >> id;
		Graph::addEdge(f, id);

	}
}

bool isChain(Graph::Node *f, Graph::Edge *list) {

	Graph::Node *q;
	for (Graph::Edge *p = list; p->next; p = p->next) {

		q = Graph::getById(f, p->id);
			if (!q || !Graph::getById(q->f, p->next->id))
				return false;
	}

	return true;
}

int main()
{
	Graph::Node *f = 0;
	Graph::Edge *list = 0;
	int len;

	std::cout << "Number of nodes in graph...\n";
	std::cin >> len;
	createGraph(f, len);

	std::cout << "Number of elements in the possible chain...\n";
	std::cin >> len;
	createList(list, len);
	
	std::cout << "The graph is:\n\n";
	Graph::printGraph(f);

	std::cout << "The list is:\n\n";
	Graph::printEdges(list);
	
	std::cout << ((isChain(f, list) ? "Yeah it is!" : "Nope!"));

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
