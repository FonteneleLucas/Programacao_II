
#include <iostream>

using namespace std;

const float PI = 3.1415927;


int counter(int n)
{ 
  static int c = 0;

  c += n;
  cout << c << endl;
  
  return c;
}

int main()
{  
  cout << "PI = " << PI << endl;
 
  /*  
  counter(1);
  counter(1);
  counter(1);
  counter(1);
  */
  
  return 0;
}

