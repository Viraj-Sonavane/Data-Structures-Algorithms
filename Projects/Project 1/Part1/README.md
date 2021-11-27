# Part 1 

In this Project, you will implement the tree algorithms: QuickSort, Insertion and Selection. 

- Quicksort and Insertion will sort suffixes of a given string S in alphabetical order.   - Selection will find k-th smallest suffix in alphabetical order of a given string S. 

You are not allowed to store separate suffixes of S, instead, you will learn how to sort suffixes (or any strings) using indirect access to suffixes via pointers

----------------------------------------------------------------------------------

#### Compile your program by running the command: make
#### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
#### To better visualize the difference of the two outputs run this command: vimdiff tests/t01.out t01.my

----------------------------------------------------------------------------------

#### Problem 1: QuickSort must sort suffixes of the input string S in alphabetical order.Instead of storing each suffix separately, and swapping suffixes (strings), it will access suffixes of S indirectly via indices that are stored in indices. The indices of suffixes represent the starting positions of suffixes in S. Use partition function.

#### Problem 2: Insertion must sort suffixes of the input string S in alphabetical order.The function will sort the suffixes of S by calling lessThan function and swapping positions of the suffixes.

#### Problem 3: Selection, You will use Insertion sort that sorts suffixes using their indices and partition. Use cout to print out the index of the k-th smallest suffix of S in alphabetical order.
