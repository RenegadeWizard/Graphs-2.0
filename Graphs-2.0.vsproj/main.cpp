//
//  main.cpp
//  Graphs 2.0
//
//  Created by Krzysztof Sychla on 17.05.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <conio.h>
#include "../Graphs 2.0/AdjacencyList.hpp"

void usage(int argc, int ile) {
	if (argc < ile) {
		std::cout << "Not enough parameters, exiting!\n";
		exit(0);
	}
}


int main(int argc, const char * argv[]) {
	

	int tab[] = { 0,1,2,3,4,5,6,0,1,3,6,1,4,0,2,4 };

	int size_of_tab = sizeof(tab) / sizeof(*tab);

	AdjacencyList lista(tab, size_of_tab, 7);

	lista.print_list();

	lista.Euler(0);
	_getch();
	return 0;
}
