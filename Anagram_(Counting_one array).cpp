 // We can increment the value in count array for characters in str1 and 
 // decrement for characters in str2. Finally, if all count values are 0, 
 // then the two strings are anagram of each other. 3) Compare count arrays. 
 // If both count arrays are same, then return true.

//O(n) complexity
bool areAnagram(char* str1, char* str2) 
{ 
    // Create a count array and initialize all values as 0 
    int count[NO_OF_CHARS] = { 0 }; 
    int i; 

    // For each character in input strings, increment count in 
    // the corresponding count array 
    for (i = 0; str1[i] && str2[i]; i++) { 
        count[str1[i]]++; 
        count[str2[i]]--; 
    } 

    // If both strings are of different length. Removing this condition 
    // will make the program fail for strings like "aaca" and "aca" 
    if (str1[i] || str2[i]) 
        return false; 

    // See if there is any non-zero value in count array 
    for (i = 0; i < NO_OF_CHARS; i++) 
        if (count[i]) 
            return false; 
    return true; 
} 
