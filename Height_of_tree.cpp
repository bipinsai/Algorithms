#include <stdio.h>
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
//My Solution 
// int height(Node* node)
// {
//    // Your code here
//    if(node == NULL)
//    return 0;
//    int q = height(node->left);
//    int x = height(node -> right);
//    int h = max(q,x)+1;
//    return h;
   
// }
int main()
{
	
}