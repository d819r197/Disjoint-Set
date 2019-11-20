#include <iostream>
#include <string>
#include <fstream>

#include "Executive.h"

#define MAXINPUT 6

Executive::Executive(std::string path) {
  ds = new DisjointSet();
  filePath = path;
}

int Executive::menuInput() {
  int choice;

  std::cout << "Please choose one of the following commands: \n";
  std::cout << "1. MakeSet \n";
  std::cout << "2. Union \n";
  std::cout << "3. Find_Timer \n";
  std::cout << "4. PathCompression \n";
  std::cout << "5. Print \n";
  std::cout << "6. Exit \n";

  std::cout << ">> ";
  std::cin >> choice;
  std::cout << std::endl;

  return(choice);
}

void Executive::run() {
  bool quit = false;
  while(!quit) {
    switch (menuInput()) {
      //MakeSet - Done
      case 1: {
        ds->MakeSet();
        std::cout << "Output: The disjoint sets have been constructed.\n";
        break;
      }
      //Union - done
      case 2: {
        int elem1, elem2 = 0;
        std::cout << "Output: Enter the representative elements for the two sets which you wish to union: \n";

        std::cout <<"> ";
        std::cin >> elem1;
        std::cout << std::endl;

        std::cout <<"> ";
        std::cin >> elem2;
        std::cout << std::endl;

        int repElem = ds->Union(elem1, elem2);

        std::cout << "Output: " <<elem1 <<" and " <<elem2 <<" have been merged. The representative element is: " <<repElem <<std::endl;
        break;
      }
      //Find_Timer - done
      case 3: {
        int elem = 0;
        std::cout << "Output: Enter the element you want to find: \n";

        std::cout <<"> ";
        std::cin >> elem;
        std::cout << std::endl;

        double dur = ds->Find_Timer(elem);
        if(dur == -1) {
          std::cout <<"Output: Sorry! 0 is not found!\n";
        }
        else {
          std::cout <<"Output: Time taken to find " <<elem <<" is " <<dur <<" nanoseconds\n";
        }
        break;
      }
      //PathCompression - TODO
      case 4: {
        int elem = 0;
        std::cout << "Output: Enter the element on whose set you would want to perform path compression: \n";

        std::cout <<"> ";
        std::cin >> elem;
        std::cout << std::endl;

        std::cout <<"Output: Path compression has been done successfully.\n";

        break;
      }
      //Print - TODO
      case 5: {
        std::cout << "Output: ";
        ds->Print();
        break;
      }
      //Exit
      case 6: {
        std::cout <<"Output: Bye!!!\n";
        quit = true;
        break;
      }
      //Invalid Input
      default: {
          std::cout << "Please input a number between 1 and " <<MAXINPUT <<".\n\n";
          break;
      }
    }
  }
}

bool Executive::parseInputFile() {
  // pq = *ds;
  std::ifstream inputFile(filePath);
  std::string input;
  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != '\n') {
        input += c;
        // std::cout <<"current input: " <<input <<std::endl;
      }
      else {
        // std::cout << "In loop, inserting: " <<input <<" into pq of size: " <<ds->GetHeap_Size() <<std::endl;
        int strInt = std::stoi(input);
        ds->addElemToSet(strInt);
        // ds->PrintHeap();
        input = "";
      }
    }
    inputFile.close();
    ds->MakeSet();
    return(true);
  }
  else {
    std::cout << "File Path: " <<filePath <<" is an invalid path.\n";
    return(false);
  }
}
