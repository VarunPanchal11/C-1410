#include<stdio.h>
#include<string.h>
#include<assert.h>

char* select_max(char str[]);
void swap_to_front(char str[], char * c); 
void str_sort(char str[]);

void swap_to_front (char str[], char *c) {
    char temp = str[0];
    str[0] = *c;
    *c = temp;
}

char* select_max(char str[]) {
    char* n = &str[0];
    int v = strlen(str);

    for(int j = 1; j < v; j++) {
        if(str[j] > *n) {
            n = &str[j];
        }
    }
    return n;
}
void str_sort(char str[]) {
     int r = strlen(str);
     for(int i=0;i<r;i++) {
        swap_to_front(str, select_max(str));
        str++;
    }

}

int main() {
 char k[] = "happy";
 assert(select_max(k)==&k[4]);
 str_sort(k);
 assert(strcmp(k,"yppha")==0);
 assert(select_max(k)==&k[0]);

 char p[] = "baggy";
 assert(select_max(p)==&p[4]);
 str_sort(p);
 assert(strcmp(p,"yggba")==0);
 assert(select_max(p)==&p[0]);
 
 char o[] = "package";
 assert(select_max(o)==&o[0]);
 str_sort(o);
 assert(strcmp(o,"pckgeaa")!=0);
 assert(select_max(o)==&o[0]);
 
 char a[] = "theft";
 assert(select_max(a)==&a[0]);
 str_sort(a);
 assert(strcmp(a,"tthfe")==0);
 assert(select_max(a)==&a[0]);

 char q[] = "goal";
 assert(select_max(q)==&q[1]);
 str_sort(q);
 assert(strcmp(q,"olga")==0);
 assert(select_max(q)==&q[0]);
 printf("All tests have passed successfully\n");

 return 0;
}