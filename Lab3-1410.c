#include <stdio.h>    
#include <assert.h>  
#include <stdbool.h>   

// matrix_equals(n, m, a, b) returns true exactly when the n x m matrices
//   pointed to by a and b are equal
// requires: n >= 1, m >= 1
//           a and b point to the (0, 0) element of an n x m matrix

bool matrix_equals(const int n, const int m, const int * a, const int * b){
  //const int * const end_of_a = a+m*n;
  const int * end_of_a = a+m*n;
  while(a < end_of_a) {
  if(*a != *b){
      return false;
    }
    a++;
    b++;
  }
  return true;
}


// matrix_add(n, m, a, b, c) computes the sum of the matrices a and b;
//   the result is stored in the matrix c
// requires: n >= 1, m >= 1
//           a, b, and c point to the (0, 0) element of an n x m matrix
//           the memory c points to can be modified

void matrix_add(const int n, 
const int m, const int * a, const int * b, int * c) 
{

  const int * end_of_a = a+m*n;
  while(a < end_of_a) 
  {
      
    *c = *a + *b;
    a++;
    b++;
    c++;
  }
}


int main(void)

{   
    
    int a1[2][3] = {{5,2,4},{0,0,3}};       
    int a2[2][3] = {{0,4,3},{2,5,3}};
    int a3[2][3] = {{5,6,7},{2,5,6}};
    int c[2][3];
    
   matrix_add(2,3, &a1[0][0], &a2[0][0], &c[0][0]);
   assert(matrix_equals(2,3,&c[0][0],&a3[0][0])==true);
   
    int b1[2][2] = {{1,2},{3,6}};       
    int b2[2][2] = {{0,1},{2,2}};
    int b3[2][2] = {{1,3},{5,8}};
    int d[2][2];
    
   matrix_add(2,2, &b1[0][0], &b2[0][0], &d[0][0]);
   assert(matrix_equals(2,2,&d[0][0],&b3[0][0])==true);
   
    int e1[1][2] = {1,2};       
    int e2[1][2] = {0,1};
    int e3[1][2] = {3,5};
    int f[1][2];
    
   matrix_add(1,2, &e1[0][0], &e2[0][0], &f[0][0]);
   assert(matrix_equals(1,2,&f[0][0],&e3[0][0])==false);
   
  
    int g1[1][1] = {1};       
    int g2[1][1] = {1};
    int g3[1][1] = {2};
    int h[1][1];
    
   matrix_add(1,1, &g1[0][0], &g2[0][0], &h[0][0]);
   assert(matrix_equals(1,1,&h[0][0],&g3[0][0])==true);
    
   printf("All the test have passed successfully,\n");
   return 0;
}


    
