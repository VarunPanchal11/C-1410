#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool order(int * const a, int * const b, int * const diff)
{
if ( *a<=*b ) 
{
    *diff = *b - *a;
    return false;
  } 
        int temp = *a;
        * a = *b;
        *b = temp;
        *diff = *b - *a;
        return true;
    
}

    

int main(void) 
{
  int p=40;
  int q=20;
  int k; 
  int *p1 = &p;
  int *q1 = &q;
  int *k1 = &k;
  assert (order(p1,q1,k1)== true);
  assert(*k1==20);
  p=12;
  q=14;
  assert(order(p1,q1,k1)==false);
  assert(*k1==2);
  p=11;
  q=11;
  assert(order(p1,q1,k1)==false);
  assert(*k1==0);
 
}