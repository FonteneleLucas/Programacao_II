
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int random(int n)
{
  return rand() % n;
}

int random(int a, int b)
{
  return a + random(b - a + 1);
}

using namespace std;

int main()
{
  List a("A"),
       b("B");
  int  i1,i2,sum;
  
  srand(time(NULL));
  
  a.random(random(3,10),100);
  cout << "Gerando " << a.getCount() << " para a lista " << a.getName() << endl;
  a.show();

  b.random(random(3,10),100);
  cout << "Gerando " << b.getCount() << " para a lista " << b.getName() << endl;
  b.show();

  if(!a.empty() && !b.empty()) {
    i1 = random(a.getCount());
    i2 = random(b.getCount());
    
    sum = a.index(i1) + b.index(i2);
    
    cout << a.index(i1) << " + " << b.index(i2) << " = " << sum << endl;
  }

  a.setName("Prognosticos");

  cout << "Concatenando as duas listas" << endl;
  a.concat(b);
  a.show();

  cout << "Ordenando " << a.getName() << endl;
  a.sort();
  a.show();

  a.sort(false);
  a.show();
   
  return 0;
}

