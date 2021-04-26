// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>

// /*tree node*/
// struct node
// {
//   char letter;
//   int frequency;
//   struct node* left;
//   struct node* right;
//   int visited; /*node hasnt been visited in traversal*/
// };
// typedef struct node node_t;

// struct huffman_element
// {
//   char letter;
//   int code;
// };

// typedef struct huffman_element huffman_table_t;

// /*void readFile();                               /*reads each char in a file into array of chars */
// node_t* make_leaf_nodes(char char_array[], int length);    /*for each unique element creates leaf node, assigns frequency and stores in array*/
// void sort_nodes_ascending(node_t* nodes, int length); /*gets array and arranges it in ascending order*/
// /*void make_linked_list(node_t *nodes, int length);     /* transforms internal array into a linkedlist */
// node_t* make_tree(node_t *nodes, int length);                     /*removes 2 nodes from the front of the array and creates internal node, which is then added to queue after traversing.*/
// /*void generate_huffman_table();                 /*would create table to make code to char
// void compress_content();                       /*would use table to concatenate binary codes and save file
// void convert_tree_to_array();                  /*convert the linked list to an array
// void save_tree_array_in_file();                /* append the array responsible for translation
// void convert_array_to_tree();                  /*convert the array to a linked list
// void decompress_content();                    /*use linked list in file, along with another file to decompress file*/

// int main(void)
// {
//   printf("Hi, this is assignment 3 Huffman Coding! \n");

//   char chars[] = {'a', 'c', 'c', 'a', 'x', 'f', 'j', 'a', 'e', 'e', 'm'};
//   printf("size of chars array %d\n", (int)sizeof(chars));
//   int length = (int)sizeof(chars);
//   node_t* nodes_array = make_leaf_nodes(chars, length);
//   printf("\n");
//   /*printf("address of the nodes array: %p\n",nodes_array);
//   printf("address of first element in nodes arrray: %p\n", &nodes_array[0]);*/
//   return 0;
// }

// /*for each unique element create a leaf node, assign frequency and store in an ascending order*/
// node_t* make_leaf_nodes(char chars[], int length)
// {
//   node_t nodes_array[1000];
//   node_t* array_ptr = nodes_array;
//   int unique_chars = 0;
//   /*printf("size of chars array %d\n", length);*/

//   int i;
//   for (i = 0; i < length; i++)
//   {
//     node_t newNode;
//     char character = chars[i];
//     /*printf("%c \n", character);*/
//     int frequency = 1;

//     int duplicates = 0; /*false - no duplicates*/
//     int k;
//     for (k = 0; k < i; k++)
//     {
//       if (character==chars[k])
//       {
//         duplicates = 1; /*true - duplicate exists*/
//       }
//     }

//     if (duplicates == 0)
//     {
//       int j;
//       for (j = i + 1; j < length; j++)
//       {
//         if (character == chars[j])
//         {
//           frequency++;
//         }
//       }

//       newNode.letter = character;
//       newNode.frequency = frequency;      
//       nodes_array[unique_chars] = newNode;
//       printf("position in array:  %d, ", unique_chars);
//       printf("letter in array node:  %c, ", array_ptr[unique_chars].letter);
//       printf("frequency in array node %d\n", array_ptr[unique_chars].frequency);
//       unique_chars++;
//     }
//   }
//   printf("%p\n", array_ptr);

//   sort_nodes_ascending(array_ptr, unique_chars);

//   /*make_linked_list(array_ptr, unique_chars);*/

//   printf("\n");
//   int z;
//   for (z = 0; z < unique_chars; z++)
//   {
//     printf("own address: %p\n", &array_ptr[z]);
//   }

//   node_t* tree = make_tree(nodes_array, unique_chars);

//   int k;
//   for (k = 0; k < unique_chars; k++)
//   {
//       printf("position in array:  %d, ", k);
//       printf("letter in array node:  %c, ", nodes_array[k].letter);
//       printf("frequency in array node %d\n", nodes_array[k].frequency);
//   }
//   printf("\n");

//   return array_ptr;
// }

// /*get linked list and arrange in ascending order*/
// void sort_nodes_ascending(node_t* nodes, int length)
// {
//   printf("%d\n", length);
//   int i;
//   for (i = 0; i < length; i++)
//   {
//     int j;
//     for (j = i + 1; j < length; j++)
//     {
//       if ((nodes[j].frequency) < nodes[i].frequency)
//       {
//         node_t temp = nodes[i];
//         nodes[i] = nodes[j];
//         nodes[j] = temp;
//       }
//     }
//   }

//     printf("After sorting\n");
//     int k;
//     for (k = 0; k < length; k++){
//       printf("new array position: %d ",k );
//       printf("letter: %c ",nodes[k].letter);
//       printf("frequency of node: %d ", nodes[k].frequency);
//       printf("address of node: %p\n", &nodes[k]);
//     }
//     printf("\n");
// }


// node_t* make_tree(node_t* nodes, int length){
//   printf("%d\n", length);

//   node_t nodes_array[1000];/*need to make dynamic becuase c cant allocate memory at runtime*/
//   node_t* tree_nodes = nodes_array;

//   while(length!=1){
//     int position = 0;
//     node_t internal_node;
//     internal_node.left = &nodes[0];
//     internal_node.right = &nodes[1];
//     internal_node.frequency = nodes[0].frequency + nodes[1].frequency;
//     internal_node.letter = 'z';

//     printf("address stored at internal nodes left: %p\n", internal_node.left);
//     printf("address stored at internal nodes right: %p\n",internal_node.right);
//     printf("frequency of internal node: %d\n", internal_node.frequency);

//     tree_nodes[position] = internal_node;
//     position++;
//     int i;
//     for (i = position; i < length-1; i++){
//       tree_nodes[i] = nodes[i + 1];
//     }
//     length--;

//     printf("Before sorting\n");
//     int j;
//     for (j = 0; j < length; j++){
//       printf("new array position: %d ",j );
//       printf("letter: %c ",tree_nodes[j].letter);
//       printf("frequency of node: %d\n", tree_nodes[j].frequency);
//     }

//     sort_nodes_ascending(tree_nodes, length);
//     nodes = tree_nodes;
//   }

//   return tree_nodes;
// }



void create_huffman_table(node_t* tree, char char_arr[], int length){
    /*have a method which can return an array which only contains unique characters*/

    printf("HII");

    char characters[50];
    int position=0;

    int i;
    for (i = 0; i < length; i++)
    {
        char unique_char;
        char character = char_arr[i];
        int frequency = 1;

        int duplicates = 0; /*false - no duplicates*/
        int k;
        for (k = 0; k < i; k++)
        {
            if (character == char_arr[k])
            {
                duplicates = 1; /*true - duplicate exists*/
            }
        }

        if (duplicates == 0)
        {
            characters[position] = character;
            position++;
        }
    }

    printf("\n");
    for (i = 0; i < position; i++)
    {
        printf("position in array:  %d, ", i);
        printf("letter in array node:  %c \n", characters[i]);
    }
    /*ABOVE CODE SHOULD HAVE ITS OWN METHOD!!!*/

    node_t *node = tree;
    node_t *root = tree;

    node_t stack[100];
    int currentPos = 0;
    int headPos = 0;

    while(currentPos!=length){
        printf("hi\n");
        if(node->visited==0 && node->left!=NULL && node->right!=NULL){
            stack[headPos] = *node; /*imitate stack push*/
            headPos++;
            node = node->left;
        }else if(node->visited==0 && node->left==NULL && node->right==NULL){
            printf("%c",node->letter);
            headPos--;
            node = &stack[headPos];
            node->visited = node->visited+1; /*mark as 1 child visited*/
        } else if(node->visited==1){
            /* node->visited = 2; mark as 2 children visited*/
            node = node->right;
        }

    }

}

