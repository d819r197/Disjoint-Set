#ifndef DISJOINT_SET
#define DISJOINT_SET

#include <iostream>

#include "Node.h"

class DisjointSet {
  public:
    //Constructor
    DisjointSet();

    //New Class Methods
    void MakeSet();
    int Union(int e1, int e2);
    double Find_Timer(int e);
    void PathCompression(int e);
    void Print();

    //Helper Functions
    Node* FindElem(int elemVal);

    void incNumElems() { numOfSetElems++; }
    void incNumDataSets() { numOfDataSets++; }
    void decNumElems() { numOfSetElems--; }
    void decNumDataSets() { numOfDataSets--; }

    void setNumElems(int val) { numOfSetElems = val; }
    void setNumDataSets(int val) { numOfDataSets = val; }
    int getNumElems() { return numOfSetElems; }
    int getNumDataSets() { return numOfDataSets; }

    //Adds an element to the set that is used with MakeSet()
    void addElemToSet(int element) { set[numOfSetElems] = element; incNumElems(); }

  private:
    int numOfSetElems;
    int numOfDataSets;

    Node ** elem_arr = new Node*[100];
    Node * set = new Node[50];



};

#endif
