void morris_traversal_inorder(Node * root)

{
	Node * current = root;
	while (current != NULL)
	{
		// left is null then print
		//node and go to the right 
		if( current->left == NULL)
		{
			cout<<current->data ;
			current = current->right;
			//current = current.right;
		}
		else
		{
			Node* predecessor = current.left ;
			while ( predecessor.right != current 
				 && predecessor.right !=NULL)
			{
				predecessor= predecessor.right;
			}
			if( predecessor->rigth == NULL)
			{
				predecessor->right = current;
				current = current->left;

			}
			else
			{
				predecessor->right = NULL;
				cout<<current->data;
				current = current->right;
			}
		}
	}
}

void _morris_traversal_preorder (Node* root )
{
	Node * current = root;
	while (current != NULL)
	{
		// left is null then print
		//node and go to the right 
		if( current->left == NULL)
		{
			cout<<current->data ;
			current = current->right;
			//current = current.right;
		}
		else
		{
			Node* predecessor = current.left ;
			while ( predecessor.right != current 
				 && predecessor.right !=NULL)
			{
				predecessor= predecessor.right;
			}
			if( predecessor->rigth == NULL)
			{
				predecessor->right = current;
				cout<<current->data;
				current = current->left;

			}
			else
			{
				predecessor->right = NULL;
				current = current->right;
			}
		}
	}
}