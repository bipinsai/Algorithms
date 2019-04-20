int size(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
        return(size(node->left) + 1 + size(node->right));  
}  