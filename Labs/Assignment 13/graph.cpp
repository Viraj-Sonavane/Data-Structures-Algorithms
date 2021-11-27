#include<climits>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<iostream>
#include<string>
#include<utility>
using namespace std;

#include "graph.h"

Graph::Graph(int N){

	size = N;
	
	Adj.resize(size);
	distance.resize(size);
	parents.resize(size);
	colors.resize(size);
	stamps.resize(size);

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

void Graph::bfscopy(int s){
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
			edge v = Adj[u][i];
			if(distance[v.neighbor] == INT_MAX && v.w!=-1){//checking for negative edge
				distance[v.neighbor] = distance[u] + 1;
				parents[v.neighbor] = u;
				aq.push(v.neighbor);
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


void Graph::dfsVisit(int u, int &t)
{
	colors[u]='G';
    for(int i = 0; i < (int)Adj[u].size(); i++)
	{
	  int v = Adj[u][i].neighbor;
      if(colors[v]=='W')//not visited vertices
	  {
        parents[v] = u; 
		distance[v] = distance[u]+1;
        dfsVisit(v,t);
      }
	  else if(colors[v]=='G' && parents[v]==v && distance[u]+1>t)//cycle found
	  {
        t=distance[u]+1;
      }
        
    }
    colors[u] = 'B';	
}//dfsVisit	

void Graph::resetWeights(int u)
{
	if (parents[u] ==u)
	{
		return; 
	}
	int par = parents[u]; 
	for (int i =0; i<(int)Adj[par].size(); i++)
	{
		int v = Adj[par][i].neighbor;
		if(u==v)
		{
			Adj[par][i].w =-1; 
			break; 
		} 
	} 
	resetWeights(parents[u]);
}

bool Graph::sameCycle(int s, int r)
{
	bfs(s); //step 1 bfs on s
	if(distance[r]==INT_MAX)
	{
		return false; 
	}
	resetWeights(r); //step 2 backtrack parent array starting with r
	bfscopy(r); //step 3 bfs on r
	
	if (distance[s]!=INT_MAX)//step 4 check for s != infinity
	{
		return true; 
	}
	return false; 
}

int Graph::longestCycle(int s){
    int max_length = 0;
    for(int i=0;i<size;i++)
	   {
          parents[i] = i;
          distance[i]=INT_MAX;
          colors[i]='W';
        }
     distance[s]=0;
     dfsVisit(s,max_length);
     return max_length;
}

bool Graph::twoPaths(int s, int r)
{
	bfs(s);//step1 run bfs on s
	if (distance[r]==INT_MAX)
	{
		return false; 
	} 
	resetWeights(r); //step 2 backtrack from r and set eges to -1
	bfscopy(s); //step 3 bfs on s and rejecting negative edges
	
	if (distance[r]!=INT_MAX)//step 4 checking if r ! = infinity
	{
		return true; 
	}  
	return false;
}

bool Graph::isOnPath(int s, int r, int q)
{
	if(s==q || r==q)
	{
		return true;
	}
	bfscopy(s);
	if (distance[r]!=INT_MAX)  
	{
		int current = r;
		int dist = distance[current];
		while(current!=s)
		{
            if(current==q && dist == distance[q])
			{
                return true;
            }
			else
			{
				current = parents[current];//backtracking
				dist = distance[current];
			}
	    }
	}
	return false;
}