#include<climits>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<iostream>
#include<string>
#include<utility>
using namespace std;

#include "ugraph.h"
#include "item.h"
#include "priorityqueue.h"

Ugraph::Ugraph(int N){

	size = N;
	Adj.resize(size);
	distance.resize(size);
	parents.resize(size);
	colors.resize(size);
	stamps.resize(size);
    low.resize(size);
    ccID.resize(size);
    RB.resize(size);
    mst.resize(size);
}

void Ugraph::resetWeights(int u)
{
	if (parents[u]==u)
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

void Ugraph::addEdge(int u, int v)
{
    Adj[u].push_back(edge(v, 0));
    Adj[v].push_back(edge(u, 0));
}

void Ugraph::addEdge(int u, int v, int aweight)
{
    Adj[u].push_back(edge(u,v, aweight));
    Adj[v].push_back(edge(v,u, aweight));
}

void Ugraph::dijkstra(int s)
{ 
    for(int i = 0; i < size; i++)
    {
        parents[i] = i;
		distance[i] = INT_MAX;
	}//for
    distance[s] = 0;
    
    Item *Items = new Item[size];//creating new array 
    for(int i = 0; i < size; i++)
    {
        Items[i] = Item(i,distance[i]);//Initializing array
    }   

	PriorityQueue Q  = PriorityQueue(Items,size);
    while(Q.getSize()!=0)
    {
        Item anitem = Q.getMin();
        int u = anitem.key;
        Q.pop();
        for(int i = 0; i < (int)Adj[u].size();i++)
        {
            int v = Adj[u][i].neighbor;
            int w = Adj[u][i].w;

            if(Q.isKey(v))
            {
                int nd = distance[u]+w;
                if(nd<distance[v])
                {
                    distance[v] = nd;
                    parents[v] = u;
                    Q.updatePriority(v,nd);
                }
            }
        }
    }
}

void Ugraph::printDistance()
{
    for(int i=0;i<size;i++)
    {
        cout<<distance[i]<<" ";
    }
    cout<<endl;
}

void Ugraph::printParents()
{
    for(int i=0;i<size;i++)
    {
        cout<<parents[i]<<" ";
    }
    cout<<endl;
}
    
void Ugraph::printPath(int u,int v)
{
    int cur = v; 
        
    if(cur==u)
    {
        P.push_back(u);
        for(int i = P.size()-1; i>=0; i--)
        {
            cout<<P[i]<<" ";
        }
        P.clear();
    }
            
    else
    {
        P.push_back(cur);
        printPath(u,parents[cur]);     
    }
}
    
int Ugraph::lenghtShortestW(int u, int v)
{
    dijkstra(u);
    printPath(u,v);
    cout<<endl;
    return distance[v];   
}

bool lessThan(const edge &x, const edge &y){ return (x.w < y.w) ? true : false; }

void Ugraph::kruskal()
{
    vector<edge> edgesAll;

    if(mst.size()>0)
    {
        mst.clear();
    }
    mst.resize(size);


    for(int i = 0;i< size;i++)
    {
        parents[i]  =  i;
        distance[i] = 0 ;
        for(int j=0;j<(int)Adj[i].size();j++)
        {
            int v = Adj[i][j].neighbor;
            int w = Adj[i][j].w;

            if(i<v)
            {
                edgesAll.push_back(edge(i,v,w));
            }
        }
    }
        sort(edgesAll.begin(), edgesAll.end(), lessThan);
        
        int counter1 = 0;
        int counter2 = 0;
        while(counter1!=size-1)
        {
             edge E = edgesAll[counter2++];
             int u = E.source;
             int v = E.neighbor;
             int we = E.w;
             int rep_u = findSet(u);
             int rep_v = findSet(v); 
        
            if(rep_u!=rep_v)
            {  
                mst[u].push_back(edge(u,v,we));
                mst[v].push_back(edge(v,u,we));
                combine(rep_u,rep_v);
                counter1++;    
            }
        }
}
    
int Ugraph::findSet(int v)
{   
    if(v==parents[v])
    {
        return parents[v];
    }
    
    else
    {
        parents[v] = findSet(parents[v]);
        return parents[v];
    } 
}

void Ugraph::combine(int x, int y)
{
    if(distance[y] == distance[x])
    {
        distance[y] = distance[y] + 1;
        parents[x] = y;
    }

    if(distance[y]>distance[x])
    {
        parents[x] = y;   
    }
    
    if(distance[x]>distance[y])
    {
        parents[y] = x;
    }
}

void Ugraph::printMST()
{
    for(int i=0;i<size;i++)
    {
        for(int j = 0;j<(int)mst[i].size();j++ )
        {
            cout<<mst[i][j].neighbor<<" ";
        }
        cout<<endl;
    }
}

int Ugraph::weightMST()
{
    int tw_mst,w_mst,allweight=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<mst[i].size();j++)
        {
            w_mst = mst[i][j].w;
            allweight +=w_mst;
        }
    }
    tw_mst = (allweight/2);
    return tw_mst;
}


void Ugraph::printGraph()
{
    for(int i = 0; i < size; i++)
    {
		for(int j = 0; j < (int)Adj[i].size(); j++)
        {
			int v = Adj[i][j].neighbor;
			cout << v << " " ;
		}//for j
		cout << endl;
	}
}

void Ugraph::bfs(int s)
{
for(int i = 0; i < size; i++)
    {
		distance[i] = INT_MAX;
		parents[i] = i;
	}//for
	distance[s] = 0;
	queue<int> aq;
	aq.push(s);
	while(!aq.empty()){
		int u = aq.front();
        cout<<u<<" ";
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
    cout<<endl;
}



void Ugraph::bfscopy(int s)
{
for(int i = 0; i < size; i++)
    {
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
    //cout<<endl;
}

void Ugraph::bfs_distinct(int s){
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

void Ugraph::removeEdge(int u, int v)
{
    int sizeu = (int)Adj[u].size();
    for(int j=0;j<sizeu;j++)
    {
        int cur = Adj[u][j].neighbor;
        if(cur == v)
        {
            Adj[u][j] = Adj[u][sizeu-1];
            Adj[u].resize(sizeu-1);
            break;
        }
    }

    int sizev = (int)Adj[v].size();
    for(int k=0;k<sizev;k++)
    {
        int cur = Adj[v][k].neighbor;
        if(cur == u)
        {
            Adj[v][k] = Adj[v][sizev-1];
            Adj[v].resize(sizev-1);
            break;
        }
    }
}


void Ugraph::dfs()
{
    for(int i = 0; i < size; i++){
		parents[i] = i;
		colors[i] = 'W';
	}	
	int t = 0;

	for(int i = 0; i < size; i++){
		if(colors[i] == 'W'){
			dfsVisit(i, t);
		}//if
	}//for
    cout<<endl;
}

void Ugraph::dfsVisit(int u, int &t)
{
    cout << u << " ";
	colors[u] = 'G';
	stamps[u].d = t;
	t++;

	for(int i = 0; i < (int)Adj[u].size(); i++)
    {
			int v = Adj[u][i].neighbor;
			if(colors[v] == 'W')
            {
				parents[v] = u;
				colors[v] = 'G';
				dfsVisit(v, t);
			}
	}//for
	colors[u] = 'B';
	stamps[u].f = t;
	t++;
}//dfsVisit	

bool Ugraph::distinctPaths(int u, int v)
{
	vector<int> p1;
	vector<int> p2;
    bfscopy(u);//step1 run bfs on s
	if (distance[v]==INT_MAX)
	{
		return false; 
	} 
	resetWeights(v); //step 2 backtrack from r and set eges to -1
	
	if(distance[v]!=INT_MAX) 
	{
            int current = v; 

            while(current!=u)
			{	
               p1.push_back(current);
			   current = parents[current];
			}
			p1.push_back(u);
	}

	if (distance[v]==INT_MAX)
	{
		return false; 
	} 
	bfs_distinct(u); //step 3 bfs on s and rejecting negative edges

	if (distance[v]!=INT_MAX)//step 4 checking if r ! = infinity
	{
			int current = v; 
            while(current!=u)
			{	
               p2.push_back(current);
               current = parents[current];
            }
			p2.push_back(u);
	

		for(int i=p1.size()-1;i>=0;i--)
		{
        	cout<<p1[i]<<" ";
    	}

		cout<<endl;

		for(int i=p2.size()-1;i>=0;i--)
		{
        	cout<<p2[i]<<" ";
    	}
	}
	else
	{
		return false;
	}
	
	cout<< endl;
	return true;
}

void Ugraph::printBridges()
{
    for(int i = 0; i < size; i++)
    {
	    parents[i] = i;
		colors[i] = 'W';
		low[i] = 0;
	}
	int t = 0;

	for(int j = 0; j < size; j++)
    {
		if(colors[j] == 'W')
        {
            dfsVisitcopy(j, t);
        }
    }
}
void Ugraph::dfsVisitcopy(int u, int &t)
{
	colors[u] = 'G';
	stamps[u].d = t;
    low[u] = t;
	t++;

	for(int i = 0; i < (int)Adj[u].size(); i++)
    {
			int v = Adj[u][i].neighbor;
			if(colors[v] == 'W')
            {
				parents[v] = u;
				colors[v] = 'G';
				dfsVisitcopy(v, t);
                
                if(low[u]<low[v])
                {
                    low[u] = low[u];
                }
                else
                {
                    low[u] = low[v];
                }

                if(low[v] == stamps[v].d)
                {
                    cout<<u<<" "<<v<<endl;
                }

                else if(low[v] > stamps[u].d)
                {
                    cout<<u<<" "<<v<<endl;
                }
			}
            else if(colors[v] == 'G' && v!=parents[u])
            {
               if(low[u]<stamps[v].d)
               {
                   low[u] = low[u];
               }
               else
               {
                   low[u] = stamps[v].d;
               }   
            }
	}//for
	colors[u] = 'B';
	stamps[u].f = t;
	t++;
}

void Ugraph::printCC()
{
    for(int i = 0; i < size; i++){
		parents[i] = i;
		colors[i] = 'W';
	}	
	int t = 0;
    int id = 0;
    vector<vector<int>> diffcc;

	for(int i = 0; i < size; i++)
    {
		if(colors[i] == 'W')
        {
			printCC_copy(i, t, id);
            id++;
		}//if
	}//for
    diffcc.resize(id); 

    for(int i=0;i<ccID.size();i++)
    {
       (diffcc[ccID[i]]).push_back(i);
    }    
    
    for (int i = 0; i < diffcc.size(); i++)
    {
        for (int j = 0; j < diffcc[i].size(); j++)
        {
            cout << diffcc[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Ugraph::printCC_copy(int u, int &t, int &id)
{   
    colors[u] = 'G';
	stamps[u].d = t;
    ccID[u] = id;
	t++;

	for(int i = 0; i < (int)Adj[u].size(); i++)
    {
			int v = Adj[u][i].neighbor;
			if(colors[v] == 'W')
            {
				parents[v] = u;
				colors[v] = 'G';
				printCC_copy(v, t, id);
			}
	}//for
	colors[u] = 'B';
	stamps[u].f = t;
	t++;   
}



