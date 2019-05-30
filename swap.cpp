
#include <stdio.h>

/* Versao C */
void swap(int *x, int *y)
{
  int t;
  
  t  = *x;
  *x = *y;
  *y = t;
}

/* Versao C++ */
void swap(int &x, int &y)
{
  int t;
  
  printf("swap C++\n");
  
  t = x;
  x = y;
  y = t;
}


int main()
{
  int a,b;
  
  a = 10;
  b = 20;

  printf("a=%d\nb=%d\n\n",a,b);
  swap(a,b);
  printf("a=%d\nb=%d\n\n",a,b);
   
  return 0;
}

