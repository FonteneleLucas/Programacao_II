
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "list.h"

using namespace std;

int random(int n)
{
  return rand() % n;
}

int random(int a, int b)
{
  return a + random(b - a + 1);
}

ostream &operator<<(ostream &os, List &list)
{
  return os << list.toString();
}

int main()
{
  List a("A"),
       b("B"),
       c("C");
  
  srand(time(NULL));
  
  a.random(random(3,10),100);
  cout << "Gerando " << a.getCount() << " para a lista " << a.getName() << endl;
  a.show();

  b.random(random(3,10),100);
  cout << "Gerando " << b.getCount() << " para a lista " << b.getName() << endl;
  b.show();

  cout << "----------------------" << endl;
  
  c = a;
  
  a.show();
  b.show();
  c.show();
  
  c += 10;
  c += 20;
  c += 30;

  c.show();

  c = a + b;
  c.show();
   
  cout << "=========================" << endl;
  cout << a << endl;

  cout << "=========================" << endl;
  a.show();
  b.show();  
  (a << 2).show();
      
  return 0;
}

