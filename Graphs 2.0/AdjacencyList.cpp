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
        std::cout << i << " -> ";
        for (auto elem : lists[i]) {
            std::cout << elem << " -> ";
        }
        std::cout << ".\n";
    }
}

AdjacencyList::AdjacencyList(int *tab, int size_of_tab, int _size){
    size = _size;
    type = 0;
    lists = new std::list<int>[size];
    int last = tab[0];
    int current;
    int first = tab[0];
    bool temp = false;
    
    for(int i=1;i<size_of_tab;i++){
        current = tab[i];
        if(temp){
            temp = false;
            first = tab[i];
            last = tab[i];
            continue;
        }
        if(current == first)
            temp = true;
        lists[last].push_back(current);
        lists[current].push_back(last);
        
        last = tab[i];
    }
    
//    for (int i = 0; i < size; i++) {
//        std::cout << i + 1 << " -> ";
//        for (auto elem : lists[i]) {
//            std::cout << elem + 1<< " -> ";
//        }
//        std::cout << ".\n";
//    }
    
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

void AdjacencyList::print_list(){
    for (int i = 0; i < size; i++) {
        std::cout << i << " -> ";
        for (auto elem : lists[i]) {
            std::cout << elem << " -> ";
        }
        std::cout << ".\n";
    }

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


void AdjacencyList::Euler(int v){
    temp_euler.push(v);
    int j;
//    print_list();
//    std::cout<<std::endl;
    for(auto i = firstOnTheList(v);i != lastOnTheList(v);i=nextOnTheList(v)){
        j = getv(i);
        //
        lists[j].remove(v);
        lists[v].remove(j);
        Euler(j);
    }
    sol_euler.push_back(v);
    printf("%d ",v);
    temp_euler.pop();
}

std::list<int>::iterator AdjacencyList::firstOnTheList(int whichList)
{
    return lists[whichList].begin();
}

std::list<int>::iterator AdjacencyList::lastOnTheList(int whichList)
{
    return lists[whichList].end();
}

std::list<int>::iterator AdjacencyList::nextOnTheList(int whichList) {
    //intialisation
    static bool firstExecution = true;
    static std::list<int>::iterator* pointers = new std::list<int>::iterator[size];
    if (firstExecution) {
        for (int i = 0; i < size; i++)
            pointers[i] = lists[i].begin();
        firstExecution = false;
    }
    //actual function
    if (pointers[whichList] != lists[whichList].end())
        return pointers[whichList]++;
    pointers[whichList] = lists[whichList].begin();
    pointers[whichList]++;
    return lists[whichList].end();
}


void AdjacencyList::Hamilton(int i){
    static int* visited = new int[size];
    visited[i];
    for(auto succesor : lists[i])
        
        return;
}

