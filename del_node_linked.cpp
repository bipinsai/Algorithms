
/* Deleting a node in linked list when the pointer to that
   node only is given
/*

/* Link list node 
struct Node
{
    int data;
    Node* next;
}*/

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
void deleteNode(Node *node)
{
    Node *p,*tmp;
    for(p=node;p->next->next!=NULL;p=p->next)
    {
        tmp = p->next;
        p->data=tmp->data;
    }
    tmp=p->next;
    p->data=tmp->data;
    p->next=NULL;
    free(tmp);

    /*while((node->next)->next != NULL)
      {
          node->data = (node->next)->data;
          node = node->next;
      }
      node->data = (node->next)->data;
        node->next=NULL;
  */
    
   // Your code here
}