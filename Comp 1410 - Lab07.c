#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct strnode {  
 char str[1000];
 struct strnode *next;
};

struct strnode * free_node(struct strnode * node);
void concat_nodes(struct strnode* head, char * str);
struct strnode *create_node(char str[], struct strnode *next);


struct strnode *create_node(char str[], struct strnode *next) {
    struct strnode *node = (struct strnode *)malloc(sizeof(struct strnode));

    if (node == NULL) {
        return NULL;
    }
    node->next = next;
    strcpy(node->str, str);
    return node;
}

struct strnode * free_node(struct strnode * node) {

    struct strnode * next = node->next;
    free(node);
    return next;
}

int main(void) {
    struct strnode *nodeI = create_node("sea", NULL);
    struct strnode *nodeII = create_node("bee", nodeI);
    struct strnode *nodeIII = create_node("eh", nodeII);
    assert(nodeI->next == NULL);
    assert(strcmp(nodeI->str, "sea") == 0);

    assert(nodeII->next == nodeI);
    assert(strcmp(nodeII->str, "bee") == 0);

    assert(nodeIII->next == nodeII);
    assert(strcmp(nodeIII->str, "eh") == 0);

    char str10 [100] = "";
    concat_nodes (nodeIII , str10);

    printf ("%s" , str10);

    assert (strcmp (str10 , "eh bee sea") == 0);

    printf ("\n");

    struct strnode *nodeIV = create_node("Willis", NULL);
    struct strnode *nodeV = create_node("Bruce", nodeIV);
    struct strnode *nodeVI = create_node("Walter", nodeV);  
    assert(nodeIV->next == NULL);
    assert(strcmp(nodeIV->str, "Willis") == 0);

    assert(nodeV->next == nodeIV);
    assert(strcmp(nodeV->str, "Bruce") == 0);

    assert(nodeVI->next == nodeV);
    assert(strcmp(nodeVI->str, "Walter") == 0);

    char str11 [100] = "";
    concat_nodes (nodeVI , str11);

    printf ("%s" , str11);

    assert (strcmp (str11 , "Walter Bruce Willis") == 0);

    printf ("\n");

    struct strnode *nodeVII = create_node("Bing", NULL);
    struct strnode *nodeVIII = create_node("Muriel", nodeVII);
    struct strnode *nodeIX = create_node("Chandler", nodeVIII);
  
    assert(nodeVII->next == NULL);
    assert(strcmp(nodeVII->str, "Bing") == 0);

    assert(nodeVIII->next == nodeVII);
    assert(strcmp(nodeVIII->str, "Muriel") == 0);

    assert(nodeIX->next == nodeVIII);
    assert(strcmp(nodeIX->str, "Chandler") == 0);
    char str12 [100] = "";
    concat_nodes (nodeIX , str12);

    printf ("%s" , str12);

    assert (strcmp (str12 , "Chandler Muriel Bing") == 0);

    printf ("\n");

    struct strnode *head = (struct strnode *)malloc(sizeof(struct strnode));
    struct strnode *current = head;

    for (char c = 'A'; c <= 'Y'; c++) {
        struct strnode *nxt = (struct strnode *)malloc(sizeof(struct strnode));
        char ch[1000];
        ch[0] = c;
        ch[1] = '\0';
        strcpy(current->str, ch);
        current->next = nxt;
        current = nxt;
    }
    char ch[] = "Z";
    strcpy(current->str, ch);

    char str[1000];
    str[0] = '\0';

    concat_nodes(head, str);
    printf("%s\n", str);

    char check[] = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    assert (strcmp(str, check) == 0);

    printf ("\n");

    assert(free_node(nodeIII) == nodeII);
    assert(free_node(nodeII) == nodeI);
    assert(free_node(nodeI) == NULL);

    printf("All tests have passed sucessfully!\n");
}

void concat_nodes(struct strnode* head, char * str) {
   struct strnode*  current = head;

   while( current) {
      strcat(str,  current->str);

      if( current->next) {
         strcat(str, " ");
      }
       current =  current->next;
   }

   return;
}