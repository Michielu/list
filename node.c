#include <stdio.h>
#include <string.h>

struct Node{
    int pid;
    char *command;
    struct Node *next;
};

void push(struct Node *head, int pid, char *command){
    struct Node n;
    n.pid = pid;
    n.command =  command;
    printf("Added node: pid: %d command: %s\n", n.pid, n.command);
}

int main(){
    printf("Hell0\n");
    struct Node node;
    node.next = NULL;
    push(&node, 1000, "ahh");
    

}