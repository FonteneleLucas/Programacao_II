
#include <stdio.h>

int  x = 100,
     y = 200,
     v[3] = { 10, 20, 30 };
int *p, 
    *q;

void show()
{
  printf("&x = %p\n",&x);
  printf(" x = %d\t%x\n\n",x,x);

  printf("&y = %p\n",&y);
  printf(" y = %d\t%x\n\n",y,y);
  
  printf("&v = %p\n",v);
  printf(" v = ");
  for(int i=0;i < sizeof(v)/sizeof(v[0]);i++)
    printf("%d,",v[i]);
  printf("\b \n     ");
  for(int i=0;i < sizeof(v)/sizeof(v[0]);i++)
    printf("%x,",v[i]);
  printf("\b \n");

  printf("&p = %p\n",&p);
  printf(" p = %p\n", p);
  printf("*p = %d\t%x\n",*p,*p);

  printf("&q = %p\n",&q);
  printf(" q = %p\n", q);
  printf("*q = %d\t%x\n",*q,*q);
  
  printf("------------------------------------------------\n");
}

int main()
{
  p = &x;
  q = &y;
  
  show();
  
  p++;
  q--;
  
  show();

  for(int i=0;i < 5;i++) {
    q[i] = i + 1;
  }

  show();

  return 0;
}

