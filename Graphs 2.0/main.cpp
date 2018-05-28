//
//  main.cpp
//  Graphs 2.0
//
//  Created by Krzysztof Sychla on 17.05.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "AdjacencyList.hpp"
#include "Timer.hpp"

void usage(int argc, int ile){
    if(argc < ile){
        std::cout<<"Not enough parameters, exiting!\n";
        exit(0);
    }
}


int main(int argc, const char * argv[]) {
    usage(argc,6);
    
    int number = atoi(argv[1]);
    std::fstream dane;
    std::fstream wynik;
    dane.open(argv[2],std::ios_base::in);
    wynik.open(argv[3],std::ios_base::app);
    
    int size = atoi(argv[4]);
    int size_of_graph = atoi(argv[5]);
    
    int *tab = new int [size];
    
    for(int i=0;i<size;i++)
        dane >> tab[i];
    
//    for(int i=0;i<77;i++)
//        std::cout<<tab[i]<<" ";
//    std::cout<<"\n";
    
//    int tab[] = {0,1,2,3,4,5,6,0,1,6,4,1,1,3,5,1};
//    int size = sizeof(tab)/sizeof(*tab);
//
//    AdjacencyList *lista = new AdjacencyList(tab,size,7);
//    lista->Hamilton(0, true);
//    delete lista;
//    std::cout<<"\n";
    AdjacencyList lista(tab,size,size_of_graph);
//    lista2->Euler(0);
//    delete lista2;
//    std::cout<<"\n";
    
    Timer time;
    
    switch(number){
        case 0:
            time.StartTimer();
            lista.Euler(0);
            time.EndTimer();
            wynik<<"\t"<<time.GetDelta();
            break;
        case 1:
            time.StartTimer();
            lista.Hamilton(0,true);
            time.EndTimer();
            wynik<<"\t"<<time.GetDelta();
            break;
        case 2:
            time.StartTimer();
            lista.Hamilton(0, false);
            time.EndTimer();
            wynik<<"\t"<<time.GetDelta();
            break;
        default:
            std::cout<<"WRONG OPTION!!\n";
            break;
    }
    
    delete [] tab;
    dane.close();
    wynik.close();

    return 0;
}
