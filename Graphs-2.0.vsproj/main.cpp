#include <iostream>
#include <conio.h>

#include "../Graphs 2.0/AdjacencyList.hpp"
#include "../Graphs 2.0/AdjacencyMatrix.hpp"


int getv(std::list<int>::iterator p) {
	return *&*p;
}

int main() {
	int n_tab[] = {1,0,0,1,1,0,1,0,0,0,1,0,1,0,1};

	AdjacencyMatrix *macierz = new AdjacencyMatrix(6);
	macierz->fill(n_tab);
	AdjacencyList *lista = new AdjacencyList(macierz,0);
	
	for (auto i = lista->nextOnTheList(0); i != lista->lastOnTheList(0); i = lista->nextOnTheList(0)) {
		std::cout << getv( i );
	}

	
	delete lista;
	delete macierz;
	_getch();
}