#include "WGraph.h"
#include "algorithm"

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

void WGraph::computeMST() {
	//double** sortedGraph = m_adj;
	//sortedGraph.sort();
	ListStack<double> *visited = new ListStack<double>();
	double min = 0;
	double lowest = numeric_limits<double>::max();
	int I;
	int J;
	for (int a = 0; a < m_size; a++) {
		for (int i = 0; i < m_size; i++) {
			for (int j = i+1; j < m_size; j++) {
				if (m_adj[i][j] < numeric_limits<double>::max()) {
					lowest = m_adj[i][j];
					I = i;
					J = j;
				}
			}
		}
		MST[I][J] = lowest;
		min += lowest;
	}
	cout << "MST Cost: " << min << endl;
	printMST();
}

void WGraph::printMST() {

}

