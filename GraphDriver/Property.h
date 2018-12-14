#pragma once
#include <iostream>

#include "Graph.h"

class Property {

public:

	static void chainType() {
	
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

		if (isChain(f, list)) {

			if (list->id == Graph::getLast(list)->id)
				std::cout << "It is a cycle\n";
			else
				std::cout << "It is a simple chain\n";

		}
		else std::cout << "It is no chain\n";


		//Graph::deleteGraph(f);
	}

	/*
	*Improve the for statements
	*Problems:
	*For graph ids 1 2 3 5 6
	*1. It checks if 4 is a node (Maybe it is not necessary to check. You could go directly to the next node)
	*2. It does not check if node 6 can be linked to other nodes
	*/
	static void roy_Warshall() {

		Graph::Node *f = 0;
		int size;
		std::cout << "Number of nodes...\n";
		std::cin >> size;

		createGraph(f, size);
		
		Graph::Node *g1 = 0;
		Graph::Node *g2 = 0;
		Graph::Edge *e1 = 0;
		Graph::Edge *e2 = 0;
		for(int k = 1; k <= Graph::getSize(f); k++)
		for(int i = 1; i <= Graph::getSize(f); i++)
		for(int j = 1; j <= Graph::getSize(f); j++) {

			if (i != k && j != k) {
			
				g1 = Graph::getById(f, i);
				g2 = Graph::getById(f, k);

				e1 = Graph::getById(g1->f, k);
				e2 = Graph::getById(g2->f, j);

				if (e1 && e2) {
				
					if(g1->id != e2->id && !Graph::getById(g1->f, e2->id))
					Graph::addEdge(g1->f, e2->id);
				}
			}
		}

		Graph::printGraph(f);
	}

private :

	static void createGraph(Graph::Node *&f, int len) {

		f = 0;
		int edgeLen, id;
		for (int i = 0; i < len; i++) {

			std::cout << "Node " << i + 1 << " id...\n";
			std::cin >> id;
			std::cout << "Number of edges...\n";
			std::cin >> edgeLen;

			Graph::add(f, id);
			for (int j = 0; j < edgeLen; j++) {

				std::cout << "Edge " << j + 1 << " id...\n";
				std::cin >> id;
				Graph::addEdge(Graph::getLast(f)->f, id);

			}
		}
	}

	static void createList(Graph::Edge *&f, int len) {

		int id;
		for (int i = 0; i < len; i++) {

			std::cout << "Element " << i + 1 << " id...\n";
			std::cin >> id;
			Graph::addEdge(f, id);

		}
	}

	static bool isChain(Graph::Node *f, Graph::Edge *list) {

		Graph::Node *q;
		for (Graph::Edge *p = list; p->next; p = p->next) {

			q = Graph::getById(f, p->id);
			if (!q || !Graph::getById(q->f, p->next->id))
				return false;
		}

		return true;
	}

};