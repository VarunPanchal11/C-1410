#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
int collatz(int n);
int collatz(int n){
    int count =0;
    while(n!=1){
        if(n%2==0){
             n=n/2;
       count+=1;
       printf(" -> ");
    }
    else  
    {
       n=3*n+1;
       count+=1;
       printf(" -> ");
    }
    printf("%d",n);
    }
    return count;
}
int main(void){
    
     int a;
     char b;
     printf("Enter an integer:\n");
  while(scanf("%d",&a)==1)
  {
    while(a<1) 
    {
      printf("Invalid Integer\n");
      scanf("%d",&a);
    }
    printf("\nTotal step to reach 1 is %d\n",collatz(a));
    printf("\nEnter an integer:\n");
  
  while(scanf("%c",&b)==1) 
  {
    break;
  }
  }
    assert(collatz(14)==17);
    assert(collatz(9)==19);
    assert(collatz(3)==7);
    assert(collatz(5)==5);
}


