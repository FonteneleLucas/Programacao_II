
#include <stdio.h>
#include <iostream>
#include "ns.h"

namespace sample {
  
int x = 100;
  
int hello()
{
  printf("Hello, world!\n");
}

}

namespace test {
  float x = 10;
}

using namespace std;
using namespace sample;
using namespace test;

int main()
{
  hello();
  cout << "Hello, world!" << endl;
  
  cout << "x=" << sample::x << endl;
  cout << "f=" << sample::f << endl;
  
  return 0;
}

