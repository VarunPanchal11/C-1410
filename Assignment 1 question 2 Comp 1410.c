#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
int num_divisors_up_to_k(int n, int k);
int num_divisors_up_to_k(int n, int k){
    if(k==0)
      return 0;
    else if(n%k==0)
        return num_divisors_up_to_k(n,k-1)+1;
    else
    return num_divisors_up_to_k(n,k-1);
}
bool is_prime(int n,int num) {
    if(num==n)
    return 0;
    else
      if(num%n==0)
      return 1;
    else{
        return is_prime(n+1, num);
    }
int main(void){
     int n,k,num;
    printf("%d num_divisors_up_to_k\n",num_divisors_up_to_k(n,k));
    assert(num_divisors_up_to_k(1,3&&9)==9);
    printf("Enter your Number:");
    scanf("%d",&num);

    if(is_prime(2,num)==0)
        printf("It is a Prime Number.");
    else
        printf("It is not a Prime Number.");
}
    
}