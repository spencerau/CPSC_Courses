/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA6

*/

#include "WGraph.h"
//#include <Algorithm>
//#include <bits/stdc++.h>

using namespace std;

WGraph::WGraph(){
	m_size = 0;
	m_adj = NULL;
}

WGraph::WGraph(unsigned int sz){
	m_size = sz;
	//allocate sz * sz adj matrix
	m_adj = new double*[sz];
	m_conn = new double*[sz];
	MST = new double*[sz];
	for(int i = 0; i < m_size; ++i){
		m_adj[i] = new double[sz];
		m_conn[i] = new double[sz];
		MST[i] = new double[sz];
	}
	//start with edges
	for(int i = 0; i < m_size; ++i){
		for(int j = 0; j < m_size; ++j){
			m_adj[i][j] = std::numeric_limits<double>::max();
			m_conn[i][j] = std::numeric_limits<double>::max();
			m_conn[i][j] = 0;
			MST[i][j] = 0;
		}
	}
}

WGraph::~WGraph(){
  	//release memory
	delete m_adj;
	delete m_conn;
}

void WGraph::addEdge(VertexID i, VertexID j, double w){
	if(i < m_size && j < m_size){
		m_adj[i][j] = w;
		m_adj[j][i] = w;
	}
}

void WGraph::removeEdge(VertexID i, VertexID j){
	if(i < m_size && j < m_size){
		m_adj[i][j] = std::numeric_limits<double>::max();
		m_adj[j][i] = std::numeric_limits<double>::max();
	}
}

bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}

void WGraph::calcFW(){
  	for(int i = 0; i < m_size; ++i){
    	for(int j = 0; j < m_size; ++j){
    	m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
    	}
  	}

  	for(int im = 0; im < m_size; ++im){ //transitive closure
    	for(int source = 0; source < m_size; ++source){
      		for(int sink = 0; sink < m_size; ++sink){
        		//every possible pair of source,sink and intermediate node
				if(source==sink){
				
				}
				if (m_conn[source][im] != std::numeric_limits<double>::max() &&
				m_conn[im][sink] != std::numeric_limits<double>::max() &&
				m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
					m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
				}

      		}
    	}
 	}
}

double WGraph::cheapestCost(VertexID i, VertexID j){
    return m_conn[i][j];
}

void WGraph::updateConn(VertexID i, VertexID j) {
	m_conn[i][j] = 1;
	m_conn[j][i] = 1;
	for (int a = 0; a < m_size; a++) {
		if (m_conn[i][a] == 1) {
			m_conn[j][a] = 1;
			m_conn[a][j] = 1;
		}
		if (m_conn[j][a] == 1) {
			m_conn[i][a] = 1;
			m_conn[i][a] = 1;
		}
	}
}
/*
int WGraph::find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
*/

void WGraph::computeMST() {
	cout << "Original Matrix: " << endl;
	printMatrix(m_adj);

	double mst = 0;
	double lowest = numeric_limits<double>::max();
	int I;
	int J;

	PQueue<Edge*> *allEdges = new PQueue<Edge*>(true);
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (m_adj[i][j] != 0) {
				Edge *edge = new Edge();
				edge->from = i;
				edge->to = j;
				edge->weight = m_adj[i][j];
				allEdges->add(edge);
			}
		}
	}
	cout << "PQueue: " << endl;
	allEdges->print();
	cout << endl;
	//sort(allEdges, );

	// change the bounds for this
	for (int a = 0; a < m_size; a++) { // goes through all nodes
		for (int i = 0; i < m_size; i++) {
			for (int j = i+1; j < m_size; j++) {
				if (m_adj[i][j] < lowest && m_adj[i][j] != 0) {
					// check if there is a cycle
					if (m_conn[i][j] != 1) {
						updateConn(i, j);
						lowest = m_adj[i][j];
						I = i;
						J = j;
					}
				}
			}
		}
		MST[I][J] = lowest;
		mst += lowest;
	}
	cout << "MST Cost: " << mst << endl;
	cout << endl;
	cout << "MST Matrix: "<< endl;
	printMatrix(MST);
	//printMST();
}

void WGraph::printMatrix(double **matrix) {
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void WGraph::printMST() {
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			cout << MST[i][j] << " ";
		}
		cout << endl;
	}
}

