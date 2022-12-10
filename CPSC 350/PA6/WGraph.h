#ifndef WGraph_H
#define WGraph_H

#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits>
#include "ListStack.h"

//an unweighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

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
	void printMST();

private:
	double **MST;
	double** m_adj;
	double** m_conn;
	unsigned int m_size; //nodes in WGraph (fixed)

};






#endif
