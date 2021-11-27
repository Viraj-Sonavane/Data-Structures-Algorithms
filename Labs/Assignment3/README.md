# Assignment 3

----------------------------------------------------------------------------------

### Compile your program by running the command: make
### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
### To better visualize the difference of the two outputs run this command: vimdiff tests/t01.out t01.my

----------------------------------------------------------------------------------

#### Problem 1. Given a vector A of integers, write a recursive function that finds the minimum number in A. Your function must have two recursive calls and must return an integer (there is no output).

int recMin(const vector<int> &A, int start, int fin);

#### Problem 2. Given a vector A of integers of size n, write a recursive function that calculates the sums of all subarrays A[0…i], 0 ≤ i ≤ n-1. Your function must have one recursive call.

void subarraySums(const vector<int> &A, vector<int> &B, int fin);

#### Problem 3. Given a vector A of integers, write a recursive function that returns true if A is a palindrome; and false, otherwise. Your function must have one recursive call.

bool recPal(const vector<int> &A, int first, int last);

#### Problem 4. Given a vector A of distinct integers in increasing order and an integer k. Write a recursive function that returns true if k occurs in A. Your function must have one recursive call.

bool recFindSorted(const vector<int> &A, int k, int start, int fin);

#### Problem 5. Given a vector A with distinct integers in increasing order. Write a recursive function that returns an integer index such that index = A[index]. If no such index exists, your function will return -1. Your function must have one recursive call.

int findIndex(const vector<int> &A, int start, int fin);

#### Problem 6. Given a vector A of integers (in any order) and an integer k. Write a recursive function that returns true if k is in A. Your function must have two recursive calls.

bool recFind(const vector<int> &A, int k, int start, int fin);

#### Problem 7. Power Set. Given a set of integers (i.e. a vector of distinct integers – sets do not have repeats). Find and print the Power Set of the given set (except for an empty subset). There is one recursive call.

void powerSet(const vector<int> &A, vector< vector<int> > &P, int last);

#### Problem 8. Print All Permutations. Given a string s of size n. Write a function that prints all permutations of s. Your function must have one recursive call.

void findPerms(const string &s, queue<string> &p, int first);

