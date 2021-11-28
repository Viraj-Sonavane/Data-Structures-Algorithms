# Assignment 13 : 

- In this assignment, you will work with a directed graph represented as Adjacency Lists and implemented using vector<vector< edge > > Adj.
- Instead of integers, each Adjacency List holds edge(s), each edge has int neighbor and int w such that Adj[u][j] is an edge, and Adj[u][j].
- Neighbor returns a vertex v of the edge (u, v) in the graph. The integer w stands for weight and will be used to solve problems. 
- For example, you can set w to -1 to mark the corresponding edge (u, v); here is how to access it: Adj[u][j].w = -1.

----------------------------------------------------------------------------------
### Compile your program by running the command: make
### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
### To better visualize the difference of the two outputs run this command: vimdiff t01.my tests/t01.out
----------------------------------------------------------------------------------

#### Problem 1. Given a graph G and two integers, vertices s and r, write a member function(s) that returns true if the given vertices s and r lie on the same cycle. If these vertices do not lie on the same cycle, then your method should return false.

> bool sameCycle(int s, int r);

#### Problem 2. Given a graph G and a vertex s, write a member function that returns an integer L, the length of the longest simple cycle, on which s lies. If s does not lie on any cycle, your method will return 0. A cycle is simple if each vertex occurs in the cycle only once. The length of a cycle is measured in the number of edges on that cycle. DFS might not discover all simple cycles, on which s lies, you only need to find the longest cycle that can be discovered by running dfsVisit on s (i.e. whatever cycle may be discovered, find it’s length, and choose the max length out of all such cycles).

> int longestCycle(int s);

#### Problem 3. Given a directed graph G and two vertices s and r in G, write a member function that returns true if there exist at least two distinct paths from s to r. Two paths are called distinct if they do not share any edges.

> bool twoPaths(int s, int r);

#### Problem 4. Given a directed graph, and three vertices s, r and q, write a member function that returns true if q is on the shortest path from s to r.

> bool isOnPath(int s, int r, int q);





