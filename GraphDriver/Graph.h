#pragma once
#include <iostream>

class Graph {

public:

	struct Edge {

		int id;
		Edge *next;
	};

	struct Node {

		int id;
		Edge *f;
		Node *next;
	};

	static void add(Node *&f, int id) {

		if (!f) {

			f = 0;
			f = new Node;
			f->id = id;
			f->next = 0;
			f->f = 0;
		}
		else {

			Node *l = getLast(f);
			Node *p = 0;
			p = new Node;
			p->id = id;
			p->next = 0;
			p->f = 0;
			l->next = p;
		}
	}

	static void addEdge(Edge *&f, int id) {

		if (!f) {

			f = 0;
			f = new Edge;
			f->id = id;
			f->next = 0;
		}
		else {

			Edge *l = getLast(f);
			Edge *p = 0;
			p = new Edge;
			p->id = id;
			p->next = 0;
			l->next = p;
		}
	}

	static Node *getLast(Node *f) {

		while (f->next)
			f = f->next;

		return f;
	}

	static Node *get(Node *f, int i) {

		while (i && f) {
			f = f->next;
			i--;
		}

		if (i)
			return 0;

		return f;
	}

	static Edge *getLast(Edge *f) {

		while (f->next)
			f = f->next;

		return f;
	}

	static Edge *get(Edge *f, int i) {

		while (i && f) {
			f = f->next;
			i--;
		}

		if (i)
			return 0;

		return f;
	}

	static void printNodes(Node *f){
	
		for (Node *p = f; p; p = p->next) {

			std::cout << "Node " << p->id << " links to node:\n";
			for (Edge *q = p->f; q; q = q->next)
				std::cout << q->id << ' ';

			std::cout << "\n";
		}
	}
};