/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back(7);
  dat.push_front(8);
  dat.push_back(9);
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  // prints: 8 7 9
  cout << dat.size() << end;  // prints 3 since there are 3 strings stored
  dat.pop_back();
  cout << dat.get(0) << " " << dat.get(1) << endl;
  cout << dat.size() << end;
  dat.pop_front();
  cout << dat.get(0) << endl;
  cout << dat.size() << end;
}
