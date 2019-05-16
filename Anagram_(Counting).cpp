// Method 2 (Count characters)
// This method assumes that the set of possible characters in both strings is small. In the following implementation, it is assumed that the characters are stored using 8 bit and there can be 256 possible characters.
// 1) Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.
// 2) Iterate through every character of both strings and increment the count of character in the corresponding count arrays.
// 3) Compare count arrays. If both count arrays are same, then return true.


bool areAnagram(char* str1, char* str2) 
{ 
    // Create 2 count arrays and initialize all values as 0 
    int count1[NO_OF_CHARS] = { 0 }; 
    int count2[NO_OF_CHARS] = { 0 }; 
    int i; 
  
    // For each character in input strings, increment count in 
    // the corresponding count array 
    for (i = 0; str1[i] && str2[i]; i++) { 
        count1[str1[i]]++; 
        count2[str2[i]]++; 
    } 
  
    // If both strings are of different length. Removing this 
    // condition will make the program fail for strings like 
    // "aaca" and "aca" 
    if (str1[i] || str2[i]) 
        return false; 
  
    // Compare count arrays 
    for (i = 0; i < NO_OF_CHARS; i++) 
        if (count1[i] != count2[i]) 
            return false; 
  
    return true; 
} 