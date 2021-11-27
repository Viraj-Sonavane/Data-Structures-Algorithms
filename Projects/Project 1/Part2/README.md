# Part 2 

In this part, you will run three experiments and will fill in a report

Direction: How to measure time in seconds inside a program:Include <ctime> header.Assume that you need to measure how long does it take to run function partition, then you need to declare two variables of type clock_t, place one before the function, and the other after the function:clock_t t1 = clock();
----------------------------------------------------------------------------------

### Compile your program by running the command: make
### To test your function, run the following command using correct test files: ./run < tests/t01.in > t01.my
### To better visualize the difference of the two outputs run this command: vimdiff tests/t01.out t01.my

----------------------------------------------------------------------------------


#### Experiment 1: You will compare the performance of the two sorting algorithms: QuickSort and Insertion.

- Read a test file, concatenate all lines into a single string S;- Then make a separate copy of a vector of integers with the suffix indices for each algorithm (the length of a vector equals to the length of S). In other words, you will have two vectors A and B, such that A[i] = B[i] = i. You will pass A to QuickSort and B to Insertion.- Measure time that it takes to run QuickSort;- Measure time that is required to run Insertion.- Output the results to the screen in the format: length of S, time for Quicksort, time for Insertion.- Record this information for all five input files.- Build a graph using Excel (or a similar tool) that shows the length of S on x-axis and time in seconds on y-axis.

#### Experiment 2: Next, you will compare the performance of QuickSort and Selection algorithms to accomplish the following task. Assume that we only need to know the starting position (index) of the k-th suffix of a given string S in alphabetical order of suffixes. Selection algorithm accomplishes this task in linear time. QuickSort can accomplish this task by first sorting the suffixes of a given S in alphabetical order, and then returning the index of the k-th suffix.- Read a test file, concatenate all lines into a single string S;- Then make a separate copy of a vector of integers with the suffix indices for each algorithm (the length of a vector equals to the length of S). In other words, you will have two vectors A and B, such that A[i] = B[i] = i. You will pass A to QuickSort and B to Selection.- Measure time that it takes to run QuickSort;- Measure time that is required to run Selection.- Output the results to the screen in the format: length of S, time for Quicksort, time for Selection.- Record this information for all five input files.- Build a graph using Excel (or a similar tool) that shows the length of S on x-axis and time in seconds on y-axis.


#### Experiment 3: Finally, you will compare the performance of Selection and Insertion to sort suffixes of a given string S in alphabetical order. To use Selection algorithm to sort suffixes, we can simply write a for loop that at each iteration calls Selection algorithm to find i-th suffix, and will write down the returned suffix:

- Read a test file, concatenate all lines into a single string S;- Then make a separate copy of a vector of integers with the suffix indices for each algorithm (the length of a vector equals to the length of S). In other words, you will have two vectors A and B, such that A[i] = B[i] = i. You will pass A to Inserrtion and B to Selection.- Measure time that it takes to run Insertion to sort all the suffixes of S;- Measure time that is required to run Selection to sort all the suffixes of S;- Output the results to the screen in the format: length of S, time for Insertion, time for Selection.- Record this information for all five input files.- Build a graph using Excel (or a similar tool) that shows the length of S on x-axis and time in seconds on y-axis.


 
