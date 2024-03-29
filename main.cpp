#include <iostream>

#include "Executive.h"

int main(int argc, char* argv[]) {
  if(argc == 2) {
    Executive exec(argv[1]);
    if(exec.parseInputFile()) {
        exec.run();
    }
    else {
      std::cout <<"Parse failed to complete on Disjoint Set. Please try again.\n";
      return 0;
    }
  }
  //Bad Input
  else {
    std::cout<<"Invalid input. Try again.\n";
  }

  return 0;
}
