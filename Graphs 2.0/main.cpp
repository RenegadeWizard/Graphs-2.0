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
        std::cout << "Not enough parameters, exiting!\n";
        std::cout << "Usage: ./main [number] [input file] [output file] [size] [size of graph]\n";
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
    
    AdjacencyList lista(tab,size,size_of_graph);
    
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
