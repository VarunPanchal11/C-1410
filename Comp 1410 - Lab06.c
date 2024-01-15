#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

struct student {
  int id;
  char * name;
};

struct student * create_student(int id, char * name);

bool change_name(struct student * s, char * new_name);

void free_student(struct student * s);

int main (void) {
   struct student *inspection_first = create_student(110071802, "Varun");
   change_name(inspection_first, "Panchal");
   assert(strcmp(inspection_first->name, "Panchal") == 0);
   free_student(inspection_first);
    
   struct student *inspection_second = create_student(101002020, "Bruce");
   change_name(inspection_second, "Lee");
   assert(strcmp(inspection_second->name, "Lee") == 0);
   free_student(inspection_second);
    
   struct student *inspection_third = create_student(210101101, "Muhammad");
   change_name(inspection_third, "Ali");
   assert(strcmp(inspection_third->name, "Ali") == 0);
   free_student(inspection_third);
    
   printf("All tests have passed successfully!\n");
}

struct student * create_student(int id, char * name) {
    
   struct student* current_student = (struct student*) malloc(sizeof(struct student*));
    if(current_student == NULL) {
      printf("Error there is memory leak\n");
      return NULL;
    }
   current_student->id = id;
   current_student->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    if(current_student->name == NULL) {
       printf("Error there is memory leak\n");
       return NULL;
    }
     strcpy(current_student->name, name);
     return current_student;
}

bool change_name(struct student * s, char * new_name) {
   char* str = (char*) realloc(s->name, sizeof(char) * (strlen(new_name) + 1) );
     if(str == NULL) 
        return false;
     strcpy(s->name, new_name);
        return true;
}

void free_student(struct student * s) {
  free(s->name);
  free(s);
}