//For Timing Find_Timer()
#include <chrono>
using namespace std::chrono;

#include "DisjointSet.h"

//Constructor
DisjointSet::DisjointSet() {
  numOfDataSets = 0;
  numOfSetElems = 0;

  for(int lcv = 0; lcv < 100; lcv++) {
      elem_arr[lcv] = nullptr;
  }
}

void DisjointSet::MakeSet() {
  const int bound = getNumElems();

  for(int lcv = 0; lcv < bound; lcv++) {
    Node * newNode = new Node(set[lcv]);
    newNode->setParent(newNode);

    elem_arr[lcv] = newNode;
    set[lcv] = 0;
  }
  setNumElems(getNumElems() - bound);
  setNumDataSets(getNumDataSets() + bound);
}

int DisjointSet::Union(int e1, int e2) {
  Node * elem1 = FindElem(e1);
  Node * elem2 = FindElem(e2);

  if(elem1 == nullptr || elem2 == nullptr) {
    std::cout << "Error: values can not be unioned because one does not exist in data set\n";
    return -1;
  }
  else if(elem1->getKey() >= elem2->getKey()) {
    elem1->setParent(elem2);
    return elem2->getKey();
  }
  else {
    elem2->setParent(elem1);
    return elem1->getKey();
  }
}

double DisjointSet::Find_Timer(int e){
  auto start = high_resolution_clock::now();
  Node* tempNode = FindElem(e);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);

  if(tempNode == nullptr) {
    return -1;
  }
  // std::cout <<"DURATION: " << duration.count() << std::endl;

  return duration.count();
}

Node* DisjointSet::FindElem(int elemVal) {
  for(int lcv = 0; lcv < getNumDataSets(); lcv++) {
    Node * tempNode = elem_arr[lcv];

    while(tempNode->getParent() != tempNode){
      if(tempNode->getKey() == elemVal) {
        // std::cout <<"Value found!\n";
        return tempNode;
      }
      tempNode = tempNode->getParent();
    }
    //Check Rep Node
    if(tempNode->getKey() == elemVal) {
      // std::cout <<"Value found!\n";
      return tempNode;
    }
  }
  // std::cout <<"Value not found.\n";
  return nullptr;
}

void DisjointSet::Print() {
  for(int lcv = 0; lcv < getNumDataSets(); lcv++) {
    Node * tempNode = elem_arr[lcv];

    while(tempNode->getParent() != tempNode){
      std::cout <<tempNode->getKey() <<", ";
      tempNode = tempNode->getParent();
    }

    //Output Rep Node
    std::cout <<tempNode->getKey() <<" \n";
  }
}
