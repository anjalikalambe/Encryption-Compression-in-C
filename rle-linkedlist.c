#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct nodes /*fix logins to login*/
{
    char letter[1];
    struct node_t *next;
};

typedef struct nodes node_t;

void write_note();
void compress(char filename[]);
void decompress(char filename[]);

int main(void) {

    printf("Hi, this is assignment 3 Running Length Encoding using a linkedlist! \n");

    char filename[10] = "sample.txt";
    write_note(filename);
    compress(filename);
}


void compress(char filename[]){
    node_t *head = NULL;    
    
    /*create a linked list of nodes*/
    FILE *file_p = NULL;
    file_p = fopen(filename, "rb"); 

    if (file_p != NULL)
    {   
        fread(&head->letter, sizeof(node_t), 1, file_p);
        head->next = NULL;
        node_t *current = head;

        while (!feof(file_p)){
            node_t *new_node;
            new_node = (node_t *)malloc(1);
            /*make linked list of all characters in the file*/
            fread(&new_node->letter, sizeof(node_t), 1, file_p);
            current->next = new_node;
            current = new_node;
            free(new_node);
        }
    }
    else
    {
        printf("Read error\n");
    }
    fclose(file_p);

    /*now do the actual compression*/
    node_t *linked_list = head;
    node_t *current = head;

    char character = current->letter; /*first character*/
    current = current->next;
    int count = 1;

    while(current!=NULL){
        char x = current->letter; /*current character*/

        if(character == x){
            count++;
        }
    }
}