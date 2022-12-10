/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA6

Main File; does File IO and creates a new WGraph pointer, and calls computeMST()

*/

#include <iostream>
#include "WGraph.h"
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {
    if (argc != 2) return -1;
    ifstream read(argv[1]);
    string N;
    getline(read, N);
    int size = stoi(N);
    WGraph *graph = new WGraph(size);
    string line;
    for (int i = 0; i < size; i++) {
        getline(read, line);
        stringstream sstream(line);
        double weight;
        for (int j = 0; j < size; j++) {
            sstream >> weight;
            graph->addEdge(i, j, weight);
        }
    }
    graph->computeMST();
}