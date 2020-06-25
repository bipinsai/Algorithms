// How to use lps[] to decide next positions 
// (or to know a number of characters to be skipped)?

// We start comparison of pat[j] with j = 0 
// with characters of current window of text.
// We keep matching characters txt[i] and pat[j] 
// and keep incrementing i and j while pat[j] and txt[i]
 // keep matching.
// When we see a mismatch
// We know that characters pat[0..j-1] match with txt[i-j…i-1] 
// (Note that j starts with 0 
// and increment it only when there is a match).
// We also know (from above definition) that 
// lps[j-1] is count of characters of pat[0…j-1]
// that are both proper prefix and suffix.
// From above two points, we can conclude 
// that we do not need to 
// match these lps[j-1] characters with txt[i-j…i-1] 
// because we know that these characters will anyway match. Let us consider above example to understand this.

// Just remember that the lps[i] stores the NUMBER of character
// that are prefix as well as suffix starting from the index 0
// to the i th index.

void computingLPS ( int pat , int txt ,int n ,int m )
{
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    int lps[M];
    lps[0] = 0 ;
    int i = 1 ;
    int len = 0;
    while (i < M )
    {
        if( pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if( i != 0 ) 
                len = lps[len-1];
            else
            {
                lps[i] = 0 ;
                i++;
            }
        }
    }
}   
void kmp ()
{
    int i = 0;
    while ( i < N )
    {
        if( pat[j] == text[i]) 
        {
            i++;
            j++;
        }
        if( j == M )
        {
            cout<<i-j;
            j = lps[j-1];

        }

        // mismatch after j matches 
        else if (i < N && pat[j] != txt[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    }
}
