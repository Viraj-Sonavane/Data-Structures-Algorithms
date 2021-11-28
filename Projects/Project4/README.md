# Project 4 : 
In this project you will implement the Dijkstra’s algorithm and the Kruskal’s algorithm.


Step 1. Update code for PriorityQueue class:

  - In function pop(), before removing min-Priority Item, set it’s keys[aheap[0].key] = -1. In this case if keys[v] is -1, then we will know that vertex v is not in the priority queue anymore.
  - Write the member function bool isKey(int v) that returns true if v is in the priority queue (i.e. if keys[v] is not -1), and returns false otherwise.

Step 2. Update struct edge:

Step 3. Update code for Ugraph class:

----------------------------------------------------------------------------------

#### Compile your program by running the command: make
#### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
#### To better visualize the difference of the two outputs run this command: vimdiff tests/t01.out t01.my

----------------------------------------------------------------------------------

