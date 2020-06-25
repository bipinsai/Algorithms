#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 26; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
int main() {
	//code
	int q;
	cin>>q;
	struct TrieNode *root = getNode();
	for (int j =0 ;j<q;j++ )
	{
	    int n;
	    cin>>n;
	    for( int i =0;i<n;i++ )
	    {
	        string s;
	        cin>>s;
	        insert( root, s);
	        
	    }
	    string s1;
    	cin>>s1;
    	cout<<search(root,s1)<<endl;
	    
	}
	
	return 0;
}


// NOTES On Tries  :: 

/*. 
Using Trie, search complexities can be 
brought to optimal limit (key length). 
If we store keys in binary search tree,
 a well balanced BST will need time 
proportional to M * log N, where M is maximum string 
length and N is number of keys in tree. 
Using Trie, we can search the key in O(M) time
*/