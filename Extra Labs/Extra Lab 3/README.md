# Extra 

Given a binary search tree of integers (positive and negative), BST, and an integer val, find the previous node (i.e. in-order predecessor) and return the value of that node. Nodes in the BST do not have links to parents.

Requirements:
- Your program (functions) must run in O(log(n))-time (if a BST is balanced, then height of the tree is O(log(n))), where n is the size of the given BST.
- Your public function must be called previous and take one parameter, the given integer, and return an integer, the value of the previous node:
int previous(int val);
- In all cases where previous node does not exist (BST is empty, the given node is the leftmost node of the given BST, the given value has not been found in the given BST), return INT_MIN (defined in <climits>).

----------------------------------------------------------------------------------

### Compile your program by running the command: make
### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
### To better visualize the difference of the two outputs run this command: vimdiff tests/t01.out t01.my

----------------------------------------------------------------------------------





