#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

int choose(int n, int m)
{
        if(m==0 || m==n)
          return 1;
        if(m>n)
          return 0;
         else {
            return choose(n-1,m-1) + choose(n-1,m);
          }
        
}
int main(void)
{
        assert(choose(4,2)==6);
        assert(choose(5,3)==10);
        assert(choose(10,3)==120);
        assert(choose(8,4)==70);
}



