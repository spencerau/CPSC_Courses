
#include <iostream>
#include "WGraph.h"
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {
    if (argc != 2) return -1;
    WGraph *graph = new WGraph();
    ifstream read(argv[1]);
    string N;
    getline(read, N);
    string line;
    for (int i = 0; i < stoi(N); i++) {
        getline(read, line);
        stringstream sstream(line);
        double weight;
        for (int j = 0; j < stoi(N); j++) {
            sstream >> weight;
            graph->addEdge(i, j, weight);
        }
    }
    graph->computeMST();
}