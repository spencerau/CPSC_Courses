/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA6

*/

#ifndef WGraph_H
#define WGraph_H

#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits>
#include "PQueue.h"

//an unweighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

// Data structure to store a graph edge
struct Edge {
	double weight;
	int from;
	int to;
};

class WGraph{
public:
    WGraph();
    WGraph(unsigned int sz);
    ~WGraph();
    void addEdge(VertexID i, VertexID j, double w);
    void removeEdge(VertexID i, VertexID j);
    bool areAdjacent(VertexID i, VertexID j);
    double cheapestCost(VertexID i, VertexID j);
    void calcFW();
    void computeMST();
	void printMatrix(double **matrix);

private:
	double **MST;
	double** m_adj;
	double** m_conn;
	unsigned int m_size; //nodes in WGraph (fixed)

	void updateConn(VertexID i, VertexID j);
	void printMST();
 

};






#endif
