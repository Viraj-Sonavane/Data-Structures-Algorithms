# Project 2 

----------------------------------------------------------------------------------

#### Compile your program by running the command: make
#### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
#### To better visualize the difference of the two outputs run this command: vimdiff tests/t01.out t01.my

----------------------------------------------------------------------------------

### Part 1 : implement an AVL-tree (balanced BST tree, name it BST and implement insert member function that inserts a new item in the tree and balances the tree.

### Part 2 : Add member function remove that removes a node from the tree.

### Part 3 : 


#### Part 3i:

- Add an integer size as a data member to Tnode class; the non-default constructor of the class will initialize size to 1. This data member, size, will be stored and maintained at each node. The meaning of size at any node i is the total number of nodes in the subtree rooted at i. When the constructor is called a new node is created in the tree, and this new node is the only node in the subtree rooted at this node, so the constructor initializes size at this node to 1.- You need to update your code for insert and remove to update size on each node on the path from the root to the new node (or to the removed node); this could be something similar to how you updated height – update function must run in constant time (this is not a recursive function, it should take just a few basic operations).

