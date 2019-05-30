
#include <stdio.h>

long max(long a, long b)
{
  printf("max(long,long)\n");
  return (a > b) ? a : b;
}

long max(long a, long b, long c)
{
  printf("max(long,long)\n");
  return (a > b) ? a : b;
}

double max(double a, double b)
{
  printf("max(double,double)\n");
  return (a > b) ? a : b;
}

int main()
{
  double x=10,y=20;
  
  printf("max(%ld,%ld) = %ld\n",10L,20L,max(10L,20L));
  printf("max(%lf,%lf) = %lf\n",x,y,max(x,y));
  
  return 0;
}

