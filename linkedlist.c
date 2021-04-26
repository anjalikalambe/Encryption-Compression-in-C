  
/*void make_linked_list(node_t* nodes, int length){
  int i;
  for (i = 0; i < length; i++){
    if(i==(length-1)){
      nodes[i].next = NULL;
    } else {
      nodes[i].next = &nodes[i + 1];
    }
  }
}*/

  
  
  /*receives a linked list, from which it needs to remmove 2 nodes from the front and create an internal node*/
  /*
  node_t* head = &nodes[0];
  node_t nodes[1000];
  int position = 0;

  printf("\n%p\n",head);
  while(head->next!=NULL){
    node_t internal_node;
    internal_node.left = head;
    internal_node.right = head->next;
    internal_node.frequency = head->frequency + head->next->frequency;
    nodes[position] = internal_node;
    position++;

    printf("address stored at internal nodes left: %p\n", head);
    printf("address stored at internal nodes right: %p\n",head->next);
    printf("frequency of internal node: %d\n",head->frequency);

    /*Before deciding which node is head-find which where it fits in terms of frequency sort
    head = head->next->next;
    printf("%p\n",head);
  }
    node_t *tree = head;
    return tree;
  */
  /*receives an array, from which it needs to remmove 2 nodes from the front, create an internal node, then sort, then repeatm */
