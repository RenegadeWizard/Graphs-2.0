/*
 AdjacencyList.cpp
 Graphs
 
 Copyright � 2018  Dominik Witczak
 
 This program is free software : you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#include"AdjacencyList.hpp"

//AdjacencyList::AdjacencyList(AdjacencyMatrix source, int which)
//{
//    inicjalize(source.tab, source.n, which);
//}
//
//AdjacencyList::AdjacencyList(AdjacencyMatrix *source, int which)
//{
//    inicjalize(source->tab, source->n, which);
//}

AdjacencyList::AdjacencyList(int **tab, int _size, int which)
{
    inicjalize(tab, _size, which);
}

void AdjacencyList::inicjalize(int **tab, int _size, int which)
{
    size = _size;
    type = which;
    
    //declare a table
    lists = new std::list<int>[size];
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((tab[i][j] == 1 && type == NEXT) || (tab[i][j] == 0 && tab[j][i] == 0 && type == NOINCIDENCY)) {
                lists[i].push_back(j);
            }
            else if (tab[j][i] == 1 && type == PREV) {
                lists[i].push_back(j);
            }
        }
    }
    
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << " -> ";
        for (auto elem : lists[i]) {
            std::cout << elem + 1 << " -> ";
        }
        std::cout << ".\n";
    }
}

AdjacencyList::AdjacencyList(int tab[6][6], int _size, int which)
{
    size = _size;
    type = which;
    
    //declare a table
    lists = new std::list<int>[size];
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((tab[i][j]==1 && type == NEXT) || (tab[i][j]==0 && tab[j][i]==0 && type == NOINCIDENCY)) {
                lists[i].push_back(j);
            }
            else if (tab[j][i] == 1 && type == PREV) {
                lists[i].push_back(j);
            }
        }
    }
    
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << " -> ";
        for (auto elem : lists[i]) {
            std::cout << elem + 1 << " -> ";
        }
        std::cout << ".\n";
    }
}


AdjacencyList::~AdjacencyList()
{
    for (int i = size; --i > 0;) {
        for (int j = 0; j < size; j++) {
            lists[i].clear();
        }
    }
    //delete lists;
}

void AdjacencyList::DFS(int i, int &idx)
{
    if (visited == NULL)
        return;
    visited[i] = 1;
    for (auto element : lists[i]) {
        if(!visited[element])
            DFS(element, idx);
    }
    sorted[--idx] = i;
}

void AdjacencyList::sortDFS()
{
    if (type != NEXT) {
        std::cout << "  Tip:\tTo sort the graph use type = NEXT\n";
        return;
    }
    
    visited = new int[size];
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }
    sorted = new int[size];
    
    int idx = size;
    for (int i = 0; i < size; i++) {
        if (!visited[i])
            DFS(i, idx);
    }
    
    for (int i = 0; i < size; i++)
        std::cout << sorted[i] + 1 << " ";
    std::cout << "\n";
    delete visited;
    delete sorted;
}


void AdjacencyList::sortBFS()
{
    //check for error
    if (type != NEXT) {
        std::cout << "  Tip:\tTo sort the graph use type = NEXT\n";
        return;
    }
    //initialize arrays
    predecessors = new int[size];
    for (int i = 0; i < size; i++)
        predecessors[i] = 0;
    sorted = new int[size];
    
    //fill the ancestors list
    for (int i = 0; i < size; i++) {
        for (auto elem : lists[i]) {
            predecessors[elem]++;
        }
    }
    
    //sort
    for (int idx = 0; idx < size;) {
        //find an elem with no ancestors;
        int k = 0;
        while (predecessors[k] != 0 && k < size - 1)
            k++;
        
        //Indicate as sorted
        sorted[idx++] = k;
        predecessors[k]--;
        
        //for every succesor of k, decrement it predecessors count
        for (auto elem : lists[k]) {
            predecessors[elem]--;
        }
    }
    //write the sorted Graph
    for (int i = 0; i < size; i++)
        std::cout << sorted[i] + 1 << " ";
    std::cout << "\n";
    
    delete visited;
    delete sorted;
}

void AdjacencyList::Euler(){
    return;
}

void AdjacencyList::Hamilton(){
    return;
}




