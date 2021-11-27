#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
#include "graph.h"
using namespace std;

Graph::Graph()
{
    int N,M;
    cin>>N>>M;
    size = N;
    Adj.resize(size);
    distance.resize(size);
    parents.resize(size);
    colors.resize(size);
    stamps.resize(size);

    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
        Adj[u].push_back(v);
    }
}
void Graph::printGraph()
{
    for(int u=0;u<size;u++)
    {
        cout<<u<<": ";
        for(int j=0;j<(int)Adj[u].size();j++)
        {
            int v = Adj[u][j];
            cout<<v<<" ";
        }
        cout<<endl;
    }
}

void Graph::printNeighbors(int u)
{
    for(int j=0;j<(int)Adj[u].size();j++)
    {
        int v = Adj[u][j];
        cout<<v<<" ";
    }
    cout<<endl;
}

bool Graph::isNeighbor(int u,int v)
{
    for(int i=0;i<(int)Adj[u].size();i++)
    {
        if(Adj[u][i]==v)
        {
            return true;
        }
    }
    return false;
}

void Graph::bfs(int s)
{
    for(int i=0;i<size;i++)
    {
        distance[i]=INT_MAX;
        parents[i]=i;
    }
    distance[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int j=0;j<(int)Adj[u].size();j++)
        {
            int v = Adj[u][j];
            if(distance[v]==INT_MAX)
            {
                distance[v] = distance[u]+1;
                parents[v] = u;
                q.push(v);
            }
        }
    }
    cout<<endl;
}

void Graph::printPath(int u)
{
    if(parents[u]== u)
    {
        cout<<u<<" ";
        return;
    }
    else
    {
        printPath(parents[u]);
        cout<<u<<" ";
    }
}

void Graph::printLevels(int s)
{
    for(int i=0;i<size;i++)
    {
        distance[i]=INT_MAX;
        parents[i]=i;
    }
    distance[s]=0;
    queue<pair<int,int>> q;
    q.push(make_pair(s,distance[s]));
    int curlevel = 0;
    while(!q.empty())
    {
        pair<int,int>apair = q.front(); 
        int u = apair.first;
        int level = apair.second; 
        if(level == curlevel)
        {    
            cout<<u<<" ";
        }    
        else
        {
            cout<<endl;
            cout<< u << " ";
            curlevel++;
        }
            
        q.pop();
        for(int j=0;j<(int)Adj[u].size();j++)
        {
            int v = Adj[u][j];
            if(distance[v]==INT_MAX)
            {
                distance[v] = distance[u]+1;
                parents[v] = u;
                q.push(make_pair(v,distance[v]));
            }
        }
    }
    cout<<endl;
}

void Graph::dfs()
{
    for(int i=0;i<size;i++)
    {
        parents[i] = i;
        colors[i] = 'W';
    }
    int t=0;
    for(int i=0;i<size;i++)
    {
        if(colors[i]=='W')
        {
            dfsVisit(i,t);
        }
    }
    cout<<endl;
}

void Graph::dfsVisit(int u,int &atime)
{
    cout << u << " " ;
    colors[u]='G';
    stamps[u].d = atime;
    atime++;
    for(int i=0;i<(int)Adj[u].size();i++)
    {
        int v = Adj[u][i];
        if(colors[v]=='W')
        {
            parents[v] =  u;
            dfsVisit(v,atime);
        }
    }
    colors[u] = 'B';
    stamps[u].f = atime;
    atime++;
}

bool Graph::isCycle()
{
    for(int i=0;i<size;i++)
    {
        parents[i] = i;
        colors[i] = 'W';
    }
    int t=0;
    for(int i=0;i<size;i++)
    {
        if(colors[i]=='W')
        {
            bool res = isCycleVisit(i,t);
            if(res)
            {
                return true;
            }
        }
    }
    return false;
}

bool Graph::isCycleVisit(int u, int & atime)
{
    colors[u]='G';
    stamps[u].d = atime;
    atime++;
    for(int i=0;i<(int)Adj[u].size();i++)
    {
        int v = Adj[u][i];
        if(colors[v]=='W')
        {
         parents[v] =  u;
         bool res  = isCycleVisit(v,atime);
            if(res)
            {
                return true;
            }
        }
        else if(colors[v] == 'G')
        {
            return true;
        }
    }
    colors[u] = 'B';
    stamps[u].f = atime;
    atime++;
    return false;
}
