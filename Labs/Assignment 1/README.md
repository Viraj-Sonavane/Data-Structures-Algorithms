# Assignment 1

----------------------------------------------------------------------------------

### Compile your program by running the command: make
### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
### To better visualize the difference of the two outputs run this command: vimdiff tests/t01.out t01.my

----------------------------------------------------------------------------------

#### Problem 1. Find min, max, average. Given a vector A of integers, find the statistics: min and max integer and calculate the average.

void printStat(const vector<int> &A);

#### Problem 2. Find a range. Given a vector A of integers and an integer k, write a function that returns true if k is greater than the range of integers in A.

bool findRange(const vector<int> &A, int k);

#### Problem 3. Count occurrences. Given a vector A of integers and a relatively small integer k such that the maximum integer in A is less than k. Write a function      that prints out each integer of A and the total number of occurrences of that integer in A. The function will print integers in increasing order.

void countOccurrences(const vector<int> &A, int k);

#### Problem 4. Count occurrences of large integers. Given a vector A of large integers and an integer k such that the range of integers in A is less than k, and k   relatively small. Write a function that prints out each integer of A and the total number of occurrences of that integer in A. The function will print integers      in decreasing order.

void countOccLarge(const vector<int> &A, int k);

#### Problem 5. Are identical? Given two vectors of integers A and B; in both, integers are ordered in non-decreasing order. Write a function that determines whether A and B are identical (have the same integers). If A and B are identical, your function will return true; otherwise, false.

bool areIdentical(const vector<int> &A, const vector<int> &B);

#### Problem 6. Is palindrome? Given an array of integers A, write a function that verifies if A is a palindrome. If A is a palindrome, then your function will return true; otherwise, it will return false.

bool isPalindrome(const vector<int> &A);

#### Problem 7. Is a subarray? Given two vectors A and B, write a function that returns true if A is a subarray of B.

bool isSubarray(const vector<int> &A, const vector<int> &B);

#### Problem 8. Partition around median. Given a vector A of distinct integers and given k, the median of A (the median might be a decimal number, e.g. 3.2).         Partition items of A so that all items in the first half of A are less than or equal to k and all items in the second half of A are greater than k. Write a          function that partitions integers of A in place (do not use any additional data structure) and does the fewest number of operations (such as comparisons,            assignments).

int partitionAround(vector<int> &A, double k);

#### Problem 9. Are identical not sorted? Given two vectors of integers A and B (not sorted). Write a function that determines whether A is a permutation of B (have  the same elements as B, but the items might be in a different order). Assume that maximum of A is a relatively small number. Your function will return true if A is a permutation of B; otherwise, it will return false.

bool areIdenticalNotSorted(const vector<int> &A, const vector<int> &B);

#### Problem 9. Merge K arrays (20 points). Given total of k queues of integers, each sorted in increasing order. Write a function that merges k queues into a single vector, in which all integers are in increasing order. Your function takes two parameters:- vector< queue<int> > containing k queues of sorted integers, and- vector<int> that is initially empty, and that would contain the merged result of 
integers in increasing order.You need to write the following function with the exact header as shown:void mergeKqueues(vector<queue<int> > &A, vector<int> &result);

