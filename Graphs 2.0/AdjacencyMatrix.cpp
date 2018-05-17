//
//  AdjacencyMatrix.cpp
//  Graphs
//
//  Created by Krzysztof Sychla on 18.04.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "AdjacencyMatrix.hpp"
#include <iostream>
#include <queue>

AdjacencyMatrix::AdjacencyMatrix(int ile){
    n = ile;
    temp = n-1;
    tab = new int *[n];
    visited = new bool [n];
    sorted = new int [n];
    for(int i = 0;i < n;i++)
        tab[i] = new int [n];
}

AdjacencyMatrix::~AdjacencyMatrix(){
//    for(int i=0;i<n;i++)
//        delete[] tab[i];
//    delete[] tab;
//    delete[] sorted;
//    delete[] visited;
}

void AdjacencyMatrix::fill(int array[]) {
	int *ptr = array;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				tab[i][j] = *ptr;
				ptr++;
			}
			else {
				tab[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}

}

void AdjacencyMatrix::printTab(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout<<tab[i][j];
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

void AdjacencyMatrix::printSorted(){
    for(int i=0;i<n;i++){
        std::cout<<sorted[i];
    }
    std::cout<<"\n";
}

void AdjacencyMatrix::DFS(int v){
    visited[v] = true;
//    std::cout<<v<<" ";
    for(int i=0;i<n;i++)
        if(tab[v][i] && !visited[i])
            DFS(i);
    sorted[temp--] = v;
}

void AdjacencyMatrix::SortDFS(){
    for(int i=0;i<n;i++)
        if(!visited[i])
            DFS(i);
}


void AdjacencyMatrix::SortBFS(){
    int *b_count= new int [n];
    int temp = n;
    for(int i=0;i<n;i++)
        b_count[i] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tab[i][j] == 1)
                b_count[j] += 1;
        }
    }
    while(temp){
        for(int i=0;i<n;i++){
            if(b_count[i]==-1)
                continue;
            if(b_count[i]==0){
                b_count[i] = -1;
                for(int j=0;j<n;j++)
                    if(tab[i][j]==1)
                        b_count[j]--;
//                std::cout<<i<<" ";
                temp--;
            }
        }
    }
//    std::cout<<"\n";
	delete b_count;
}
