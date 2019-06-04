
#include <iostream>

using namespace std;

int operator&(const int &a, const int &b)
{
  cout << "Hi, I'm operator &!" << endl;
  return 0;
}

int main()
{
  int x,y,z;
    
  x = 11;
  y = 22;
  
  z = 11&22;   // z = 1122;
  
  cout << "x=" << x << endl;
  cout << "y=" << y << endl;
  cout << "z=" << z << endl;
  
  return 0;
}

