# Assignment 8 : 

Write a new main() function in your main.cpp file. Your program will not use command line arguments for this assignment.
- Declare a BST tree inside main().
- Declare a string variable called command, and use
while(cin >> command)
loop to read input.
- Input file will contain lines, each starting with a specific word, command, that your program will use to call member functions of BST tree. The table below specifies what input in addition to command you need to read in dependent on the value of the command and what member function your program needs to call (on the declared BST tree).
- If command is not one of the commands listed in the table below, then print out the following message using cerr :
cerr << "ERROR: command " << command << " is not found." << endl;

----------------------------------------------------------------------------------

### Compile your program by running the command: make
### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
### To better visualize the difference of the two outputs run this command: vimdiff t01.my tests/t01.out
----------------------------------------------------------------------------------

#### Problem 1. If command equals to "print_inorder", then call member function: print_inorder()

#### Problem 2. heightPrint Call: heightPrint()

#### Problem 3. printBF Call: printBF

#### Problem 4. Using cin, read in a string akey, and use it as a parameter for the function findPrint, and call findPrint(akey) : findPrint

#### Problem 5. Using cin, read in a string word and an integer len. Next, take a substring of word at the beginning of word of length equal to len, and use this substring as a key when calling function insert. Call function: insert(akey, word)

#### Problem 6. Returns the leftmost node of the subtree rooted at the node pointed by cur: Tnode* getLeftmost(Tnode *cur)

#### Problem 7. Public and private member functions that remove a node whose key equals to akey, a parameter passed to this function. : void remove(string akey), Tnode* remove(Tnode* cur, string akey)





