#include <stdio.h>
#include <string.h>
#include<stdlib.h>


struct Node{
    int pid;
    char *command;
    struct Node *next;
    int size;
};

void push(struct Node *head, int pid, char *command);
void print_list(struct Node *head);
struct Node init_list();


int main(){
    struct Node head = init_list();
    push(&head, 1000, "ahh");
    push(&head, 123, "ls -l");
    // printf("In main: %d\n", head.next->pid);
    print_list(&head);
}

struct Node init_list(){
    struct Node n;
    n.pid = -1;
    n.command = NULL;
    n.next = NULL;
    n.size = 0;
    return n;
}

void push(struct Node *head, int pid, char *command){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    struct Node *currN = head;
    head->size ++;
    n->pid = pid;
    n->command =  command;
    // printf("Added node: pid: %d command: %s\n", n->pid, n->command);
    // printf("Size in push: %d\n", head->size);
    int i;
    for(i=0; i < head->size -1; i++){
        currN = currN->next;
    }
    currN->next = n;
} 

void print_list(struct Node *head){
    int i;
    struct Node *t = (struct Node*)malloc(sizeof(struct Node)); 
    t = head;
    // printf("Size: %d\n", head->size);
    printf("Print list\n");

    for(i=0; i<head->size; i++){
        t= t->next; 
        printf("[%d] %s\n", t->pid, t->command );
    }
}

