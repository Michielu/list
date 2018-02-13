#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int pid;
    char command[20];
    struct Node *next;
};

struct List{
    struct Node * head;
    struct Node * tail;
};

void push(struct List *list, int pid, char *command);
void print_list(struct List *list);
char * pop(struct List *list, int pid);
struct List init_list();


int main(){
    struct List list = init_list();
    char * r;
    char command[20];
    strcpy(command, "ahh");
    print_list(&list);
    push(&list, 1000, command);
    print_list(&list);

    strcpy(command, "second one");
    push(&list, 123, command);
    print_list(&list);

    push(&list, 1234, "third");
    print_list(&list);

    r= pop(&list, 1234);
    printf("Removed %d %s \n", 1234, r);
    print_list(&list);  
};


struct List init_list(){
    struct List *l = malloc(sizeof(struct List));
    l->head = NULL;
    l->tail = NULL;
    return *l;
};

void push(struct List *list, int pid, char *prompt){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->pid = pid;

    strncpy(n->command, prompt, strlen(prompt));
    n->next = NULL;
    if(list->head == NULL){
        printf("Head is NULL\n");
        list->head = n;
    }
    else  {
        list->tail->next = n;
    }
    list->tail = n;
    printf("At end\n");
} ;

char * pop(struct List *list, int pid){
    char *dead_process;
    //Head needs to get removed
    if(list->head->pid == pid){
        dead_process = list->head->command;
        list->head = list->head->next;
        return dead_process;
    }   
    struct Node *n = list->head;
    while(n->next){
        if(n->next->pid == pid){
            dead_process = n->next->command;
            n->next = n->next->next;
            return dead_process;
        }
        n = n->next;
    } 
    return " ";
};

void print_list(struct List *list){
    printf("Printing List\n");
    if(list->head){
        struct Node *n = list->head;
        while(1){
            printf("Printing node: %d\n", n->pid);
            if(n->next == NULL) break;
            n = n->next;
        }
    } else {
        printf("List is empty\n");
    }
};

