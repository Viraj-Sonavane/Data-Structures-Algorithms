#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;

#include "graph.h"


int main(){
    Graph agraph;
	cout << "Graph is:" << endl;
    agraph.printGraph();
    string command;
    while(cin >> command){
        if(command == "printNeighbors"){
            int u;
            cin >> u;
            cout << "Neighbors of " << u << " are: " << endl;
            agraph.printNeighbors(u);
        }else if(command == "isNeighbor"){
            int u , v;
            cin >> u >> v;
            bool res = agraph.isNeighbor(u, v);
            if(res)
                    cout << v << " is a neighbor of " << u << endl;
            else
                    cout << v << " is not a neigbor of " << u << endl;
		}else if(command == "bfs"){
			int s;
			cin >> s;
			cout << "Running BFS on the source " << s << ":" << endl;
			agraph.bfs(s);
		
		}else if(command == "dfs"){
			cout << "Running DFS:" << endl;
			agraph.dfs();
		}else if(command == "printPath"){
			int s, v;
			cin >> s >> v;
			cout << "Running BFS on the source " << s << ":" << endl;
			agraph.bfs(s);
			cout << "Path from the source " << s << " to vertex " << v << " is:" << endl;
			agraph.printPath(v);
			cout<<endl;
		}else if(command == "printLevels"){
			int s;
			cin >> s;
			cout << "Running BFS on the source " << s << ":" << endl;
			agraph.bfs(s);
			cout << "Printing levels:" << endl;
			agraph.printLevels(s);
		}else if(command == "isCycle"){
		    bool res = agraph.isCycle();
			if(res){
				cout << "Graph has a cycle." << endl;
			}
			else
				cout << "Graph does not have a cycle." << endl;
		}else{
            cerr << "ERROR: command " << command << " is not recognized." << endl;
        }
    }
    return 0;
}
