
#include <stdio.h>
#include <stdlib.h>

void show(float *v, int n)
{
  printf("< ");
  for(int i=0;i < n;i++)
    printf("%f,",v[i]);
  printf("\b > \n");
}

int cmp1(const void *e1, const void *e2)
{
  int i1 = *((int *) e1),
      i2 = *((int *) e2);
  if(i1 < i2)
    return -1;
  else if(i1 > i2)
    return 1;
  return 0;
}

int cmp2(const void *e1, const void *e2)
{
  int i1 = *((int *) e1),
      i2 = *((int *) e2);
  return i1 - i2;
}

int main()
{
  float v[6] = { -1.30,90.5,-10.2,509,5.5,20 };
  
  show(v,6);
  qsort(v,6,sizeof(*v),cmp2);
  show(v,6);
   
  return 0;
}

