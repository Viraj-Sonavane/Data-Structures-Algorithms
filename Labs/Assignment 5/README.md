# Assignment 5

Overview:
1. Command line arguments.
2. Read from a file and write to a file.
3. How to test a program that has *.out and *.cmd files.
4. How to measure time in seconds inside a C++ program.
5. ASCII character representation and how to convert characters to lower case in constant time.

----------------------------------------------------------------------------------

### Compile your program by running the command: make
### To test your function, run the following command using correct test files: ./main text1.txt 10 20 > t01.my
### To better visualize the difference of the two outputs run this command: vimdiff t01.my tests/t01.out
----------------------------------------------------------------------------------

#### Problem 1. Function readFromFile will take as a parameter an empty string S by reference, and a string, name of a file. This function will open the given file, and will read all the lines from the file and concatenate the lines into S. At the end of the function, S will be the concatenation of all lines from the given file.

> void readFromFile(string &S, string filename)

#### Problem 2.Function convertToLower will take a string S passed by reference as a parameter and will convert all the characters in S to lower case (you may use std function tolower).

> void convertToLower(string &S)

#### Problem 3. Function lessThan will take as parameters a constant string passed by reference S, and two integers, first and second, the starting indices of two suffixes in S. This function will compare the two suffixes of S starting at their starting positions and to the end of S one character at a time. The function will return true if the suffix starting at first is less than the suffix starting at position second.

> bool lessThan(const string &S, int first, int second)

#### Problem 4. Function partition that takes as parameters (1) string S of size n, passed constant by reference (2) vector indices of integers of size n, where each integer is the starting position of a suffix in S; indices are passed by reference (3) integers low and high, the start and the end indices of a given range; and (4) an integer pivotIndex, which is an arbitrary index of the vector indices.

> int partition(const string &S, vector<int> &indices, int low, int high, int pivotIndex)

#### Problem 5.

- Call readFromFile to read S from the file.
- Call convertToLower to convert characters of S to lower case.
- If argc is equal to 2 (e.g., command line is: ./main text1.txt), then print out S using cout and endl at the end.
- If argc is 4 (e.g., command line is: ./main text1.txt 10 20), then print out S using cout and endl at the end, and call function lessThan on indices 10 and 20 (from the command line arguments), if    function returns true, print out "True."; otherwise, print out "False.", and endl at the end.
- If argc is 3 (e.g., command line is: ./main text1.txt 30), then use the argument 30 as a pivot index to pass to function partition, call partition on S and this pivot index and print out the resulting indices, with a space after each index, and endl at the end.
- If argc is not 2, 3 or 4, return -1, and do nothing.





