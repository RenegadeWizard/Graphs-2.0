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

void usage(int argc, int ile){
    if(argc < ile){
        std::cout<<"Not enough parameters, exiting!\n";
        exit(0);
    }
}


int main(int argc, const char * argv[]) {
    usage(argc,4);
    
    int number = atoi(argv[1]);
//    std::fstream dane;
//    std::fstream wynik;
//    dane.open(argv[2],std::ios_base::in);
//    wynik.open(argv[3],std::ios_base::app);
    
//    int tab[] = {0,1,2,3,4,5,6,0,1,3,6,1,4,0,2,4};
    
    int **tab = new int*[7];
    
    int arr[7][7] = {
        0,1,1,0,1,0,1,
        1,0,1,1,0,0,1,
        1,1,0,1,1,0,0,
        0,1,1,0,1,0,1,
        1,0,1,1,0,1,0,
        0,0,0,0,1,0,1,
        1,1,0,1,0,1,0
    };
    
    for(int i = 0;i<7;i++)
        tab[i] = new int[7];
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
            tab[i][j] = arr[i][j];
    
    
    
//    int size_of_tab = sizeof(tab)/sizeof(*tab);
    
    AdjacencyList lista(tab,7,0);

    
    
    switch(number){
        case 0:
            std::cout<<"Euler\n";
            lista.Euler(0);
            break;
        case 1:
            std::cout<<"Hamilton\n";
            break;
        case 2:
            std::cout<<"Part B\n";
            break;
        default:
            std::cout<<"WRONG OPTION!!\n";
            break;
    }
    
    
//    lista.Euler(0);
//    std::cout<<"\n";
    return 0;
}
