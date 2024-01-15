#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

                       // Question #1

void clearboard(char setboard[][7]) 
{
 for(int i=0;i<6;i++) 
 {
  for(int j=0;j<7;j++)
  {
    setboard[i][j] = ' ';
  }
 }
 
 printf("  0   1   2   3   4   5   6  \n"); 
 printf("|---|---|---|---|---|---|---|\n");
 for(int i=0;i<6;i++)
 {
  for(int j=0;j<7;j++)
  {
    printf("| %c ", setboard[i][j]);  
  }
  printf("|\n");
  printf("|---|---|---|---|---|---|---|\n");
 }
}

bool make_move(char board[6][7] , int column , char player) 
{                                                         
  if(column<0 || column>6)
  {
   return false;
  }                                       
  while(board[0][column]==' ') 
  {
  for(int i = 5;i>=0;i--) 
  {
   if(board[i][column] == ' ')
   {
    board[i][column] = player; 
	  break; 
   }
  }
  
  printf("  0   1   2   3   4   5   6  \n"); 
  printf("|---|---|---|---|---|---|---|\n");
  for(int i=0;i<6;i++)
  {
  for(int j=0;j<7;j++)
  {
    printf("| %c ", board[i][j]); 
  }
  printf("|\n");
  printf("|---|---|---|---|---|---|---|\n");
 }
 return true; 
 break;
 }
 return false; 
}

bool check_win(char board[6][7] , char player) 
{
 
 for(int i=0;i<6;i++)
 {
  for(int j=0;j<4;j++) 
  {
   int count = 0; 
   for(int k=0;k<4;k++)
   {
    if(board[i][j+k]==player)  
	count++;                  
   }
   if(count==4) 
   {
   return 1;
   }
  }
 }
 
 for(int i=0;i<7;i++)
 {
  for(int j=0;j<3;j++) 
  {
   int count = 0;
   for(int k=0;k<4;k++)          
   {                            
    if(board[j+k][i]==player)
	count++;
   }
   if(count==4) 
   {
   return 1;
   }
  }
 }
 
 for(int i=3;i<7;i++)
 {
  for(int j=0;j<6;j++)
  {
   if(board[i][j]==player && board[i-1][j+1]==player && board[i-2][j+2]==player && board[i-3][j+3]==player)
   {
    return 1;
   }
  }
 }
 
 for(int i=3;i<7;i++)
 {
  for(int j=3;j<6;j++)
  {
   if(board[i][j]==player && board[i-1][j-1]==player && board[i-2][j-2]==player && board[i-3][j-3]==player)
   {
    return 1;
   }
  }
 }
  return 0;
}

bool check_board(char board[6][7]) 
{
 int count = 0;
 for(int i=0;i<6;i++)
 {
  for(int j=0;j<7;j++)
  {
   if(board[i][j]!= ' ')
   {
    count++;
   }
  }
 }
 if(count==42)
 {
  return true; 
 }
 return false;
}
                        // Question#2

char first_capital(const char str[], int n)
{
  int i=0,j=0,temp;
  if(str[n-1]>'Z') 
  {                         
    return 0;               
  }                         
  
  while(i<=n)
  {
  j = (i+n)/2; 
  if(str[j]>='A' && str[j]<='Z') 
  {                              
    n = j-1;
    temp = j; 
  }
  if(str[j]>'Z')
  {
    i = j+1; 
  }	 
  }
  return str[temp]; 
}
                     
                        //Question#3

void deepest_substring(const char str[], char out[])
{
 int n = strlen(str); 
 int x=0,y=0;
 for(int i=0;i<n;i++) 
 {
  if(str[i] == '(') 
  {
	x = i+1; 
  
  }
  else if(str[i]==')') 
  {
   if(y<x) 
   {
    y = i-1; 
   } 
  }
 }
 strncpy(out,str+x,y-x+1); 
}



int main(void)
{
                        // Question#1
						 
 int rows = 6;
 int column = 7;
 char stage[6][7] = {};
 //int m,n;
 char p1 = 'X', p2 = 'O'; 
 
 
  clearboard(stage); 
  
  assert(make_move(stage,-1,p1)==false);
  assert(make_move(stage,5,p1)==true);
  assert(make_move(stage,8,p2)==false);
  assert(make_move(stage,6,p2)==true);
 
  
  assert(make_move(stage,1,p1)==true);
  assert(make_move(stage,1,p2)==true);
  assert(make_move(stage,1,p1)==true);
  assert(make_move(stage,1,p2)==true);
  assert(make_move(stage,1,p1)==true);
  assert(make_move(stage,1,p2)==true);
  assert(make_move(stage,1,p1)==false); 
  assert(make_move(stage,1,p1)!=true); 
  

  assert(make_move(stage,2,p1)==true);
  assert(make_move(stage,3,p2)==true);
  assert(make_move(stage,2,p1)==true);
  assert(make_move(stage,3,p2)==true);
  assert(make_move(stage,2,p1)==true);
  assert(make_move(stage,3,p2)==true);
  assert(make_move(stage,2,p1)==true);
  assert(check_win(stage,p1)==true);
  
  
  clearboard(stage); 
  
  
  assert(make_move(stage,3,p1)==true);
  assert(make_move(stage,4,p2)==true);
  assert(make_move(stage,5,p1)==true);
  assert(make_move(stage,3,p2)==true);
  assert(make_move(stage,2,p1)==true);
  assert(make_move(stage,4,p2)==true);
  assert(make_move(stage,0,p1)==true);
  assert(make_move(stage,5,p2)==true);
  assert(make_move(stage,5,p1)==true);
  assert(make_move(stage,2,p2)==true);
  assert(check_win(stage,p2)==true); 
  
  clearboard(stage); 
  
	
  assert(make_move(stage,5,p1)==true);
  assert(make_move(stage,4,p2)==true);
  assert(make_move(stage,4,p1)==true);
  assert(make_move(stage,3,p2)==true);
  assert(make_move(stage,3,p1)==true);
  assert(make_move(stage,2,p2)==true);
  assert(make_move(stage,3,p1)==true);
  assert(make_move(stage,2,p2)==true);
  assert(make_move(stage,2,p1)==true);
  assert(make_move(stage,0,p2)==true);
  assert(make_move(stage,2,p1)==true);
  assert(check_win(stage,p1)==true);
  
  clearboard(stage); 
  
  
  assert(make_move(stage,1,p1)==true);
  assert(make_move(stage,2,p2)==true);
  assert(make_move(stage,2,p1)==true);
  assert(make_move(stage,3,p2)==true);
  assert(make_move(stage,3,p1)==true);
  assert(make_move(stage,4,p2)==true);
  assert(make_move(stage,3,p1)==true);
  assert(make_move(stage,4,p2)==true);
  assert(make_move(stage,4,p1)==true);
  assert(make_move(stage,5,p2)==true);
  assert(make_move(stage,4,p1)==true);
  assert(check_win(stage,p1)==true);
  
  clearboard(stage); 
  
  
  assert(make_move(stage,0,p1)==true && make_move(stage,1,p2)==true);
  assert(make_move(stage,1,p1)==true && make_move(stage,0,p2)==true);
  assert(make_move(stage,1,p1)==true && make_move(stage,1,p2)==true);
  assert(make_move(stage,0,p1)==true && make_move(stage,0,p2)==true);
  assert(make_move(stage,0,p1)==true && make_move(stage,1,p2)==true);
  assert(make_move(stage,1,p1)==true && make_move(stage,0,p2)==true);
  assert(make_move(stage,2,p1)==true && make_move(stage,3,p2)==true);
  assert(make_move(stage,2,p1)==true && make_move(stage,3,p2)==true);
  assert(make_move(stage,3,p1)==true && make_move(stage,2,p2)==true);
  assert(make_move(stage,2,p1)==true && make_move(stage,3,p2)==true);
  assert(make_move(stage,2,p1)==true && make_move(stage,2,p2)==true);
  assert(make_move(stage,4,p1)==true && make_move(stage,3,p2)==true);
  assert(make_move(stage,3,p1)==true && make_move(stage,4,p2)==true);
  assert(make_move(stage,5,p1)==true && make_move(stage,5,p2)==true);
  assert(make_move(stage,4,p1)==true && make_move(stage,4,p2)==true);
  assert(make_move(stage,5,p1)==true && make_move(stage,5,p2)==true);
  assert(make_move(stage,4,p1)==true && make_move(stage,4,p2)==true);
  assert(make_move(stage,5,p1)==true && make_move(stage,6,p2)==true);
  assert(make_move(stage,6,p1)==true && make_move(stage,6,p2)==true);
  assert(make_move(stage,6,p1)==true && make_move(stage,6,p2)==true);
  assert(make_move(stage,5,p1)==true && make_move(stage,6,p2)==true);

  assert(check_win(stage,p2)!=true); 
  assert(check_win(stage,p1)!=true); 
  assert(check_board(stage)==true); 
  
  printf("Question 1: All tests have passed successfully!!!\n");
 
                        // Question#2
 
 char str1[] = "heigHT";
 int n1 = strlen(str1);

 assert(first_capital(str1,n1)=='H');
 

 char str2[] = "baseball";
 int n2 = strlen(str2);
 assert(first_capital(str2,n2)=='\0');
 

 char str3[] = "chILDREN";
 int n3 = strlen(str3);
 assert(first_capital(str3,n3)=='I');
 

 char str4[] = "FESTIVAL";
 int n4 = strlen(str4);
 assert(first_capital(str4,n4)=='F');
 

 char str5[] = "island";
 int n5 = strlen(str5);
 assert(first_capital(str5,n5)=='\0');
 
 printf("Question 2: All tests have passed successfully!!!\n");
 
                       //  Question#3
 
 char str_1[] = "(a+(c,b)+d)";
 char bin[20] = {};
 
 deepest_substring(str_1,bin);
 assert(strcmp(bin,"c,b")==0);

 char str_2[] = "(a+(b+(c+d)))";
 deepest_substring(str_2,bin);
 assert(strcmp(bin,"c+d")==0);

 char str_3[] = "((((a+b)-w+z)+e-f)";
 deepest_substring(str_3,bin);
 assert(strcmp(bin,"a+b")==0);

 char str_4[] = "(x/y(w%z)-x)";
 deepest_substring(str_4,bin);
 assert(strcmp(bin,"w%z")==0);

 char str_5[] = "((((x+y))))";
 deepest_substring(str_5,bin);
 assert(strcmp(bin,"x+y")==0);
 
 printf("Question 3: All tests have passed successfully!!!\n");
 
 return 0;
}
	
 