#include<string>
#include<iostream>
using std::string;
using std::cin; 
using std::cout;

#include "timestamp.h"

#ifndef GRAPH_H
#define GRAPH_H

struct edge{
	int neighbor; // adjacent node
	int w; //keeps auxiliary information
	edge(){
		neighbor = 0;
		w = 0;
	};
	edge(int i, int j){
		neighbor = i;
		w = j;
	};
};

class Graph{
public:
	Graph(int N);
	void bfs(int s);
	void dfs();
	void dfsVisit(int u, int &t);
	void dfsVisit_copy(int u);
	void printGraph();
	void addEdge(int u, int v);
	void addEdge(int u, int v, int weight);
	int longestCycle();
	int longestCycleHelper();

	
	int longestCycleSCC();
	void printlong();

private:
	vector< vector<edge> > Adj; //adjacency lists of the graph 
	vector<int> distance; //for BFS and DFS
	vector<int> parents; //for BFS and DFS
	vector<char> colors; //for DFS
	vector<TimeStamp> stamps; //for DFS: stamps[v].d returns discovery time of v, and stamps[v].f finishing time.
    int size;
	int source = 0;
	vector<int>L;
	int maxlen = 0;
};

#endif
