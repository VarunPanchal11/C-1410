#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


struct student {
int id;
char name[20];
};

bool find_id(int id, struct student arr[], int n, char * found_name);
int find_name(char * name, struct student arr[], int n, int ids[]);
void change_name(struct student * s, char * new_name);


bool find_id(int id, struct student arr[], int n, char * found_name){
 
    for (int i = 0; i<n; i++){
       if (id == arr[i].id) {     
           strcpy(found_name, arr[i].name);
           return true ;
       }
         

    }
    return false; 
}

int find_name(char * name, struct student arr[], int n, int ids[])
{
    int flag = 0;
    for (int i=0; i<n; i++)
    {
        if(strcmp(arr[i].name,name)==0)               
        {
          ids[flag] = arr[i].id;
          flag++;
        }
    }
  return flag;
}

void change_name(struct student *s, char * new_name)
{
  strcpy(s->name,new_name);
}



int main(void)
{
    struct student s1 = {1234567, "Bob the building"};
    struct student s2 = {1, "Juan"};
    struct student s3 = {222, "Ted"};
    struct student s4 = {78, "Robin"};
    struct student s5 = {31, "Juan"};  
    struct student s6 = {110071802, "Varun"};
    struct student s7 = {10, "John"};

    struct student students[7] = {s1,s2,s3,s4,s5,s6,s7};
    int id[20];
  
    assert(find_name("Ted", students, 7, id)==1);
    assert(id[0]==222);  
    change_name(&students[6],"Steve");
    assert(strcmp(students[6].name,"Steve")==0);

    assert(find_name("Juan", students, 7, id)==2);
    assert(id[0]==1);  
    assert(id[1]==31);
    change_name(&students[0],"Justin");
    assert(strcmp(students[0].name,"Justin")==0);
  
    assert(find_name("Varun", students, 7, id)==1);
    assert(id[0]==110071802);  
    change_name(&students[4],"Anu");
    assert(strcmp(students[1].name,"Anu")!=0);
    assert(strcmp(students[4].name,"Anu")==0);

    assert(find_name("Ben", students, 7, id)==0);  
    change_name(&students[3],"Ted");
    assert(strcmp(students[1].name,"Ted")!=0);
    assert(strcmp(students[3].name,"Ted")==0);

    puts("All Test Have Passed Successfully ");



return 0;
}

