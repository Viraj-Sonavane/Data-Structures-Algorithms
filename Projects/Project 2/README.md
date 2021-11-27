# Project 2 

----------------------------------------------------------------------------------

#### Compile your program by running the command: make
#### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
#### To better visualize the difference of the two outputs run this command: vimdiff tests/t01.out t01.my

----------------------------------------------------------------------------------

#### Part 1 : Implement an AVL-tree (balanced BST tree, name it BST and implement insert member function that inserts a new item in the tree and balances the tree.

#### Part 2 : Add member function remove that removes a node from the tree.

#### Part 3 : 

1. Add an integer size as a data member to Tnode class; the non-default constructor of the class will initialize size to 1. This data member, size, will be stored and maintained at each node. The meaning of size at any node i is the total number of nodes in the subtree rooted at i. When the constructor is called a new node is created in the tree, and this new node is the only node in the subtree rooted at this node, so the constructor initializes size at this node to 1.

2. You need to update your code for insert and remove to update size on each node on the path from the root to the new node (or to the removed node); this could be something similar to how you updated height – update function must run in constant time (this is not a recursive function, it should take just a few basic operations).

3. returns size of the subtree rooted at the parameter cur (think what should be size of a subtree rooted at node that is NULL, i.e. if the parameter cur is NULL):     int getSize(Tnode* cur)  

4. Updates the size of the subtree rooted at cur, use the size of left and right children:  void updateSize(Tnode *cur)

5. Traverses the tree using in-order traversal and prints size at each node (same format as printing height):  void printSize() ,void printSize(Tnode *cur)

#### Part 4 : 

1. Given two keys as parameters, akey1 and akey2, of the two nodes in AVL tree, write a member function findLCA for AVL class that finds and returns the lowest ancestor of the two nodes given by akey1 and akey2. Your function must be recursive and run in O(logn)-time. This function returns a key, i.e. string type object. If your function reaches NULL, return an empty string.

2. Write a recursive member function findKthSmallest for AVL tree that finds and returns the k-th smallest key in AVL tree, where k is given as a parameter to this function. Your function must run in O(logn) worst-case time.

3. Write a recursive member function printLongestPath for AVL tree that prints the longest path from the root to a deepest leaf in the tree (if there is a tie between some leaves, your function must choose the path to the leftmost, or the smallest-key, leaf). The order of printing is from the root to a leaf. You need to print only keys of the nodes.

4. Write a recursive member function(s) collectSubtree that takes an empty vector as a parameter, and at the end of this function, the vector will have all the nodes (keys) in the subtree rooted at the node whose key is akey in increasing order. You may write a few functions to handle this task. If akey is not in the tree, then the vector will be empty at the end of execution.

5. Update your main.cpp
- If command equals to "printSize", then call member function printSize()
Print out endl after calling this function
- Using cin, read in two strings akey1 and akey2, and use them as parameters to call member function findLCA().
Use cout to print out the result returned, and then print out endl.
- Using cin, read in an integer k. Call findKthSmallest using k as a parameter to find and return the k-th smallest key in the tree.
Use cout to print out the result returned, and then print out endl.
- Using cin, read in a string akey. Use this as a parameter to call the member function collectSubtree.


