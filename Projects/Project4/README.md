# Project 4 : 
In this project you will implement the Dijkstra’s algorithm and the Kruskal’s algorithm.


Step 1. Update code for PriorityQueue class:

    1. In function pop(), before removing min-Priority Item, set it’s keys[aheap[0].key] = -1. In this case if keys[v] is -1, then we will know that vertex v is not in the priority queue anymore.
    2. Write the member function bool isKey(int v) that returns true if v is in the priority queue (i.e. if keys[v] is not -1), and returns false otherwise.

Step 2. Update struct edge:

Step 3. Update code for Ugraph class:

    1. Write overloaded member function void addEdge(int u, int v, int aweight) that takes three parameters, integers u, v and weight, and adds an edge (u, v) in Adj[u] whose weight w is set to the third parameter aweight; and adds an edge (v, u) in Adj[v] with w set to aweight.
    2. Write a new member function void dijkstra(int s) that takes an integer s as a parameter and finds all shortest paths from s to all vertices (nodes) of the graph.
    3. Write a new member function void printDistance() that prints distance of each node v, and put a space after each node and endl at the end.
    4. Write a new member function void printParents() that prints parent of each node v, and put a space after each node and endl at the end.
    5. Write a new recursive member function void printPath(int u, int v) that prints path by backtracking parents array starting with the second parameter v until the first parameter u is found on the path. Path is printed in the format: <vertex><space>…<vertex><space>. The first vertex on the path is u and the last is v.
    6. Write a new member function int lenghtShortestW(int u, int v) that finds the shortest path from u to v using the Dijkstra’s algorithm, then prints this path and returns the length of the path:
    7. Add a new private data member to Ugraph that holds the minimum spanning tree of the graph. Add vector<vector< edge > > mst. Inside the constructor, resize mst to size.
    8. Write a new member function void kruskal() that will calculate the minimum spanning tree for the graph (and will store it in the data member mst).
    9. Write a new member function void printMST() that scans mst and prints out all vertices in mst[0], then all vertices in mst[1], and so on. Format of output: print a space after each vertex and print endl after each adjacency list of mst (e.g. print endl after all vertices of mst[0] have been printed, and so on).
    10. Write a new member function int weightMST() that scans mst and returns total weight of all the edges in the minimum spanning tree. Please note that each edge is repeated twice in MST, so to return the correct number, you may add up all the weights, and then divide the sum by 2.
----------------------------------------------------------------------------------

#### Compile your program by running the command: make
#### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
#### To better visualize the difference of the two outputs run this command: vimdiff tests/t01.out t01.my

----------------------------------------------------------------------------------

