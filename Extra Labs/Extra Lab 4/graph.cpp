#include<climits>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<iostream>
#include<string>
#include<utility>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include "graph.h"

Graph::Graph(int N){

	size = N;
	
	Adj.resize(size);
	distance.resize(size);
	parents.resize(size);
	colors.resize(size);
	stamps.resize(size);
	//L.resize(size);

}//default

void Graph::addEdge(int u, int v){
	Adj[u].push_back(edge(v, 0));
}
void Graph::addEdge(int u, int v, int weight){
	Adj[u].push_back(edge(v, weight));

}

void Graph::printGraph(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < (int)Adj[i].size(); j++){
			int v = Adj[i][j].neighbor;
			cout << v << " " ;
		}//for j
		cout << endl;
	}
}//printGraph

void Graph::bfs(int s){
	for(int i = 0; i < size; i++){
		distance[i] = INT_MAX;
		parents[i] = i;
	}//for
	distance[s] = 0;
	queue<int> aq;
	aq.push(s);
	while(!aq.empty()){
		int u = aq.front();
        aq.pop();

		for(int i = 0; i < (int)Adj[u].size(); i++){
			int v = Adj[u][i].neighbor;
			if(distance[v] == INT_MAX){
				distance[v] = distance[u] + 1;
				parents[v] = u;
				aq.push(v);
			}
		}//for
	}//while

}//bfs

void Graph::dfs(){
	for(int i = 0; i < size; i++){
		parents[i] = i;
		colors[i] = 'W';
	}	
	int t = 0;

	for(int i = 0; i < size; i++){
		if(colors[i] == 'W'){
			//color[i] = 'G';
			dfsVisit(i, t);
		}//if
	}//for

}//dfs

void Graph::dfsVisit(int u, int &t){
	colors[u] = 'G';
	stamps[u].d = t;
	t++;

	for(int i = 0; i < (int)Adj[u].size(); i++){
			int v = Adj[u][i].neighbor;
			if(colors[v] == 'W'){
				parents[v] = u;
				colors[v] = 'G';
				dfsVisit(v, t);
			}
	}//for
	colors[u] = 'B';
	stamps[u].f = t;
	t++;
}//dfsVisit	

void Graph::dfsVisit_copy(int u)
{
	colors[u]= 'G';
    for(int i = 0; i < (int)Adj[u].size(); i++)
	{
		//colors[u] = 'G';
	  	int v = Adj[u][i].neighbor;

	  // if source found, i.e. cycle
	  if(colors[v] == 'G'){
		// if source
		if(v == source){
			if(distance[u] == -1){
				distance[u] = 1;
			 	parents[u] = v;
			}
		}
	  }

	  if(colors[v] == 'B'){
		  if(distance[u] < distance[v] + 1 ){
			  distance[u] =  distance[v] + 1;
			  parents[u] = v;
			  colors[u] = 'B';
		  }
	  }

      if(colors[v]=='W')//not visited vertices
	  {
        dfsVisit_copy(v);
		if(distance[v] != -1 && distance[u] < distance[v] + 1 ){
			  distance[u] =  distance[v] + 1;
			  parents[u] = v;
			  colors[u] = 'B';
		  }
      }
	}
    colors[u] = 'B';	
}//dfsVisit	

int Graph::longestCycle()
{
    //int max_length = 0;
    for(int i=0;i<size;i++)
	   {
          parents[i] = i;
          distance[i]= -1;
          colors[i]='W';
        }
     distance[source] = 0;
	 colors[source] = 'G';
	
     dfsVisit_copy(source);

	 int i = source;

	 cout << source << " ";
	 while(parents[i] != source){
		 cout << parents[i] << " ";
		 i = parents[i];
	 }
	 cout << parents[i] << " " << endl;
	 //printlong();
     return distance[source];
}

void Graph::printlong()
{
	for(int i=0; i<L.size(); i++)
	{
		cout<<L[i]<<" "<<endl;
	}
	cout<<endl;
}