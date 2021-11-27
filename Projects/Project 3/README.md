# Project 3 : 
In this project you will implement an undirected graph that is represented as an Adjacency List s(implemented as vector<vector< edge > > Adj). You will use struct edge that contains two data members: an integer neighbor and an integer w. 

Step 1. Implement a class Ugraph (stands for undirected graph). You need to write two files: ugraph.h
and ugraph.cpp.

- Constructor. The constructor of the class takes a single parameter, an integer N, and resizes Adj, parents, stamps, distance and colors to the size N. Initialize parents array: parent of a vertex v is equal to v. Initialize distance array with INT_MAX. Initialize colors with 'W' (stands for White).

- void addEdge(int u, int v): This member function inserts a new edge between the existing vertices u and v in the graph. Since this is an undirected graph, this function must add edge(v, 0) to Adj[u] and add edge(u, 0) to Adj[v], where 0 is used to initialize w data member of an edge.

- void removeEdge(int u, int v): This function will remove edge (u, v) from a graph. Since this is an undirected graph, two Adjacency lists must be modified: one of u and another of v. Here is how the removal must be implemented:
1. In Adj[u], find an edge with neighbor equal to v, assume that it is found at index j.
2. Copy the last edge in Adj[u] into j-th entry of Adj[u] (hence, edge with v becomes overwritten).
3. Resize Adj[u] to (Adj[u].size() - 1) size.

Repeat the same steps for Adj[v] and edge with neighbor equal to u.

- BFS and DFS. You will need to implement BFS and DFS member functions.

- printGraph. Write a public member function printGraph that prints Adjacency lists in the order: all nodes in the Adj[0], then all nodes in the Adj[1], and so on. This function will not print out w of each edge, only neighbor. Print out endl after each Adjacency list, and a space after each node (neighbor).

Step 2. Solve the following problems using Ugraph. You may add any member functions to class Ugraph to solve these problems. You may use w of struct edge to hold any information at each edge to help you to solve a problem. Your member functions may NOT change Adj (you may modify w at each edge, but you cannot remove or add edges of Adj), i.e. if you need to modify Adj, simply make a copy of Adj and pass this copy by reference to your member functions.

----------------------------------------------------------------------------------

#### Compile your program by running the command: make
#### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
#### To better visualize the difference of the two outputs run this command: vimdiff tests/t01.out t01.my

----------------------------------------------------------------------------------

#### Problem 1: Given an undirected graph G and two vertices u and v of G, design an algorithm that will return true if there are two distinct paths from u to v in G and will print these two paths; otherwise, it will return false and will not print anything. You will need to write the following public member function (with exact name, parameters, return type):
bool distinctPaths(int u, int v).

#### Problem 2: Given an undirected connected graph G, find and print all bridge edges of G.You will need to write the following public member function: 
void printBridges()

#### Problem 3: Given an undirected graph G, find all connected components of G and print out the vertices in each component on a separate line. The order of printing is the following: all vertices in ConnectedComponent with ID 0 on the first line, nodes in Connected Component with ID 1 on the second line, and so on. You need to write the following public member function: 
void printCC()

#### Problem 4: Given an undirected connected graph G, design an algorithm that returns true if it is possible to color all vertices of G in two colors, Red and Blue, such that if there is an edge (u, v) in G, then u and v must be colored with different colors. Your program must contain the following member function: 
bool twoColoring()



