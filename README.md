# Disjoint-Set
Implementation of the disjoint set data structure by parent-pointer representation for EECS560 at the University of Kansas

## General Requirements:
Implement the disjoint set data structure by using the parent-pointer representation as
explained in lecture notes. The size of the disjoint set will be fixed once it is constructed.

Your data structure should use an array of pointers to point to the nodes containing the set
elements. Each node should have a pointer that points to its parent. The representative
element of the set should point to itself. This data structure should not allow duplicate
numbers.

For this lab, you should build the data structure using the samples which are in the data.txt file.
After that, your program should have a simple menu like this:

```
Please choose one of the following commands:
1- MakeSet
2- Union
3- Find_Timer
4- PathCompression
5- Print
6- Exit
```

## Disjoint Set operations:
The disjoint set methods should be implemented as follows:

- MakeSet() – In general, this function constructs n disjoint sets from n different
elements. In the case of this lab assignment, the data.txt file contains 8 elements, and
this function should create 8 disjoint sets with one element each. Each element’s value 
EECS 560 Lab 11 – Implementation of Disjoint Sets and Graphs
Prof.: Dr.Shontz, GTAs: Chiranjeevi Pippalla, Anubhav Ghosh
will be equal to its pointer array index. Consider Fig. 1 which shows a disjoint set of size
8. The values of each disjoint set should be read from data.txt.
- Union(X,Y) - Merges the disjoint set which contains the element X and the disjoint set
which contains Y into a single set by using the union by rank heuristic. For example,
refer to Figures 2 through 7. Every time this function is called on two disjoint sets, print
the elements which have been merged as well as the representative element of the
merged sets. For an example, refer to the second output illustration.
- Find_Timer(k): Finds an element k and prints the representative element of the set in
which the element was found. If k itself is a parent, then it should print the value of
itself. This function should also print the time taken to find the element.
- PathCompression(k): In general, this function should carry out the path compression
operation on the relevant disjoint set after each find operation, implicitly, as it has been
shown in your class notes. However, this lab includes experimental profiling, where you
will note the time taken to find an element before and after its path has been
compressed. Therefore, here the path compression is done explicitly on the path which
contains k. For example, refer to Fig. 8.

## Data file:
data.txt: 
```
1 2 3 4 5 6 7 8
```
