// CREATING TRIES : 

struct node{
	node * arr[26 ]
	// we use map also 
	bool exist ; 
	node ()
	{
		exist = false ;
		for(int i=0;i<26;i++)
			arr[i] = NULL;
	}
}
void add ( string s , node * trie )
{
	int n = s.length();
	for(int i=0 ; i<n;i++)
		if( trie -> arr[s[i] -'a'] == NULL )
		{
			trie -> arr[s[i]-'a']=new node();
			trie = trie->arr[s[i]-'a'];
		}
	trie->exist = true;
}
bool search( string s , node* trie )
{
	for(int i=0;i<s.length() ; i++)
	{
		if( trie -> arr[s[i] -'a'] == NULL )
			return false;
		trie= trie->arr[s[i]-'a'];
	}
	return trie->exist ;
}