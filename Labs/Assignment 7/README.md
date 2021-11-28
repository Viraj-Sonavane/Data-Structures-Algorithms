# Assignment 7 : 
Objective: Make BST class to behave as balanced BST (i.e. as AVL-tree).

----------------------------------------------------------------------------------

### Compile your program by running the command: make
### To test your function, run the following command using correct test files: ./main text1.txt 10 20 > t01.my
### To better visualize the difference of the two outputs run this command: vimdiff t01.my tests/t01.out
----------------------------------------------------------------------------------

#### Problem 1. A private member function that returns the height of the node pointed to by the pointer cur passed as a parameter to this function. This function must run in O(1)-time.

> int getHeight(Tnode* cur)

#### Problem 2.Updates the height of the current node pointed by the pointer cur. This function must run in O(1)-time.

> void updateHeight(Tnode *cur)

#### Problem 3. Calculates and returns the balance factor of the current node pointed by cur; balance factor is defined as the height of the left sub-tree of the current node minus the height of the right sub-tree of the current node. This function must run in O(1)-time.

> int balanceFactor(Tnode *cur)

#### Problem 4. Public and private member functions that print balanced factors of the nodes in AVL-tree using in-order traversal (left, cur, right).

> void printBF()

> void printBF(Tnode *cur)

#### Problem 5. Update insert member functions to support balance of an AVL-tree (you need to update both public and private insert member functions).

#### Problem 6. Update main.cpp – you only need to add to the main.cpp : call function printBF() on BST after it calls printHeight(). Make sure there is endl printed after printHeight() and after pringBF().




