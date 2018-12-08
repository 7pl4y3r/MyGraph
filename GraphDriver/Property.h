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