#include <iostream>

#include "Node.h"

//Constructor
Node::Node() {
  key = 0;
  order = 0;
  parent = nullptr;
}

Node::Node(int value) {
  key = value;
  order = 0;
  parent = nullptr;
}
