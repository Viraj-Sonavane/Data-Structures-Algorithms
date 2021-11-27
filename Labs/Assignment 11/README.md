# Assignment 11 : 
You will implement BFS and DFS on a directed graph. First, you will write class Graph. In addition, you will implement some member functions that solve specific problems on a directed graph.

----------------------------------------------------------------------------------

### Compile your program by running the command: make
### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
### To better visualize the difference of the two outputs run this command: vimdiff t01.my tests/t01.out
----------------------------------------------------------------------------------

#### Problem 1. This function prints the adjacency lists in this format u: v1 v2 v3
where u is the vertex whose Adjacency list is printed, and vertices v1, v2 and v3 are the vertices in the Adjacency list of u. There is a colon after u and then space after the colon, and space after each vertex in Adj[u], and then endl 

void printGraph();

#### Problem 2. This function takes an integer u as a parameter, u is a vertex in the graph. The function prints neighbors of u (i.e. vertices v such that there is an edge from u to v in the graph) in the format: <vertex><space>…<vertex><space><endl>

void printNeighbors(int u);

#### Problem 3. This function takes two vertices as parameters, u and v, and returns true if there is an edge from u to v in the graph. 

bool isNeighbor(int u, int v);

#### Problem 4. This function implements BFS algorithm. The parameter s is the source, from which BFS starts running. It initializes distance array to INT_MAX (defined in <climits>, so you need to include <climits>) It initializes parents[i] to i. It uses <queue> of the standard library (include it).To use queue, just do: queue<int> aq; //aq is the name of the queue Uses pseudocode from lecture notes.
bfs will print out a node as it pops the node from the queue. cout << node << " " ; After queue is empty, then print out endl

void bfs(int s)

#### Problem 5. This function implements DFS algorithm. dfs() initializes arrays colors, parents, stamps, and contains the main for loop, from which dfsVisit is called on each node whose color is White. Parameter u of dfsVisit is the current node, and parameter atime is the current time stamp used. DFS will print out a node inside dfsVisit before processing Adj[u]: cout << u << " " ;
After the main for loop, print out endl

void dfs()
void dfsVisit(int u, int &atime)

#### Problem 6. This function must be called after bfs is called, so that parents array has been calculated by the time printPath is called. Parameter v is the node from which we start backtracking the path from the source s to v. Path is printed in the format: <node><space>…<node><space><endl>

void printPath(int v)

#### Problem 7. This function uses code of bfs, but modifies it slightly by using queue< pair<int, int> > where first in pair is a node, and second is the distance from the source to this node. Include <utility> to use C++ pair. When enqueueing a node into the queue, make a pair: pair<int, int>(node, dist) and push it into the queue. Nodes at the same levels will be in consecutive order inside the queue. You will need to maintain a variable, current level being printed, and when the next popped node from the queue has a different distance than the current level, then reset this variable to the new level, print out endl after the last level and only then print the node on the new line.

void printLevels(int s)

#### Problem 6. This function uses code of dfs and dfs_visit, but it will modify this code. Whenever a node v in Adj[u] is found such that v is Grey, this means that v is an ancestor of u in the DFS-tree, and that there exists the path from v to u, and edge (u, v) concludes the cycle consisting of this path and edge (u, v). At this point (Grey vertex has been discovered), return true. Stop traversal after true has been returned. If the main for loop has been finished, and every time isCycleVisit has been called, it returned false, then return false. This function does not print anything, just returns Boolean.

bool isCycle()
bool isCycleVisit(int u, int & atime)





