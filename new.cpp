
#include <iostream>

using namespace std;

int main()
{
  int   *vetor;
  
  cout << "vetor=" << vetor << endl;
  
  vetor[0] = 3;
  vetor = new int[10];
  vetor[0] = 3;

  cout << "vetor=" << vetor << endl;
  
  cout << vetor[0] << endl;
  
  delete[] vetor;
  
  return 0;
}

