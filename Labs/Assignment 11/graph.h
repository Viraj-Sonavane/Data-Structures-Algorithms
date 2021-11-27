#include<vector>
#include "timestamp.h"
using namespace std;
#ifndef _GRAPH_H
#define _GRAPH_H

class Graph{
    public :
        Graph();
        void printGraph();
        void printNeighbors(int u);
        bool isNeighbor(int u,int v);
        void bfs(int s);
        void printPath(int v);
        void printLevels(int s);
        void dfs();
        void dfsVisit(int u,int &atime);
        bool isCycle();
        bool isCycleVisit(int u, int & atime);
        

     private:
        vector< vector<int> > Adj; //adjacency lists of the graph
        vector< int > distance; //for BFS
        vector<int> parents; //for BFS and DFS
        vector<char> colors; //for DFS
        vector<TimeStamp> stamps; //for DFS
        int size; //total vertices
};
#endif // _GRAPH_H
