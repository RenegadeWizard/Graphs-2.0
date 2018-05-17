//
//  AdjacencyMatrix.hpp
//  Graphs
//
//  Created by Krzysztof Sychla on 18.04.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once
#include <stdio.h>

class AdjacencyMatrix{
    friend class AdjacencyList;
	friend class GraphMatrix;
public:
    void fill(int tab[]);
    void DFS(int v);
    void SortBFS();
    void SortDFS();
    int GetN(){return n;}
    bool GetVisited(int v){return visited[v];}
    int** GetTab(){return tab;}
    void printTab();
    void printSorted();
    AdjacencyMatrix(int ile);
    ~AdjacencyMatrix();
private:
    int n;
    int temp;
//    int **tab = new int *[n];
//    bool *visited = new bool [n];
//    int *sorted = new int [n];
    int **tab;
    bool *visited;
    int *sorted;
//    int *ptr = &sorted[n-1];
};
