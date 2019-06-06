
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

using namespace std;

int main()
{
  Matrix  a(5),
          b(4);

  srand(time(NULL));
            
  a.random();
  b.random(1000);
           
  a.show();
  cout << endl;
  b.show(4);
  cout << endl;

  a.assign(b);
  a.show(4);
  
  cout << endl;
               
  return 0;
}

