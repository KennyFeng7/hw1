#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("7");
  dat.push_back("9");
  dat.push_back("9");
  dat.push_back("9");
  dat.push_back("8");
  dat.push_back("7");
  dat.push_back("9");

  std::cout << dat.get(0)  << dat.get(1)  << dat.get(2) << dat.get(3) << dat.get(4) << dat.get(5) 
  << dat.get(6)<< dat.get(7) << dat.get(8) <<std::endl;
  // prints: 8 7 9
  std::cout << dat.size() << std::endl;  // prints 3 since there are 3 strings stored
  dat.pop_back();
  std::cout << dat.get(0) << " " << dat.get(1) << std::endl;
  std::cout << dat.size() << std::endl;
  dat.pop_front();
  std::cout << dat.get(0) << std::endl;
  std::cout << dat.size() << std::endl;
  ULListStr list;
	list.push_front("fred");
	list.push_front("bob");
  list.push_back("dixi");
  list.push_back("juxi");
  std::cout <<list.get(0) << list.get(1) << list.get(2) << list.get(3) << std::endl;
  // prints: 8 7 9
  std::cout << list.size() << std::endl;
}
