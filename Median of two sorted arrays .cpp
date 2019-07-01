// Example in the case of even numbers. Suppose, partition is found. Because A[] and B[] are two sorted arrays, a1 is less than or equal to a2, and b2 is less than or equal to b3. Now, to check if a1 is less than or equal to b3, and if b2 is less than or equal to a2. If that’s the case, it means that every element in the first half is less than or equal to every element in the second half, because, a1 is greater than or equal to every element before it (a0) in A[], and b2 is greater than or equal to every element before it (b1 and b0) in B[]. In case of even numbers in total the median will be the average between max of a1, b2 and the min of a2, b3, but in case of odd numbers in total the median will be the max of a2, b2. But if it is not these two cases, there are two options (in referring to the even numbers example) :
// b2 > a2 or a1 > b3
// if, b2 > a2 it means that, search on the right side of the array, and if a1 > b3 it means that, search on the left side of the array, until desired condition is found.


//     The process of the partition :
// To make two halves, make the partition such that the index that partitioning array A[] + the index that partitioning array B[] are equal to the total number of elements plus one divided by 2, i.e. (n + m + 1) / 2 (+1 is, if the total number of elements is odd).
// First, define two variables : min_index and max_index, and initialize min_index to 0, and max_index to the length of the smaller array. In these below examples A[] is the smaller array.
// To partition A[], use the formula (min_index + max_index) / 2 and insert it to a variable i. To partition B[], use the formula (n + m + 1) / 2 – i and insert it to a variable j.
// the variable i means the number of elements to be inserted from A[] into the first half, and j means the number of elements to be inserted from B[] into the first half, the rest of the elements will be inserted into the second half.
// Take a look at the below examples :

// IMPLEMENtation:


double findMedianSortedArrays(int *a, int n,  
                              int *b, int m) 
{ 
      
    int min_index = 0, max_index = n, i, j, median; 
      
    while (min_index <= max_index) 
    { 
        i = (min_index + max_index) / 2; 
        j = ((n + m + 1) / 2) - i; 
      
        // if i = n, it means that Elements from a[] in 
        // the second half is an empty set. and if j = 0, 
        // it means that Elements from b[] in the first 
        // half is an empty set. so it is necessary to 
        // check that, because we compare elements from 
        // these two groups.  
        // Searching on right 
        if (i < n && j > 0 && b[j - 1] > a[i])         
            min_index = i + 1; 
                  
        // if i = 0, it means that Elements from a[] in 
        // the first half is an empty set and if j = m, 
        // it means that Elements from b[] in the second 
        // half is an empty set. so it is necessary to 
        // check that, because we compare elements  
        // from these two groups. 
        // searching on left 
        else if (i > 0 && j < m && b[j] < a[i - 1])         
            max_index = i - 1; 
  
        // we have found the desired halves. 
        else
        { 
            // this condition happens when we don't have any 
            // elements in the first half from a[] so we 
            // returning the last element in b[] from  
            // the first half. 
            if (i == 0)             
                median = b[j - 1];             
              
            // and this condition happens when we don't 
            // have any elements in the first half from 
            // b[] so we returning the last element in  
            // a[] from the first half. 
            else if (j == 0)             
                median = a[i - 1];             
            else            
                median = maximum(a[i - 1], b[j - 1]);             
            break; 
        } 
    } 
      
    // calculating the median. 
    // If number of elements is odd there is  
    // one middle element. 
    if ((n + m) % 2 == 1) 
        return (double)median; 
          
    // Elements from a[] in the second half is an empty set.     
    if (i == n) 
        return (median+b[j]) / 2.0; 
          
    // Elements from b[] in the second half is an empty set. 
    if (j == m) 
        return (median + a[i]) / 2.0; 
      
    return (median + minimum(a[i], b[j])) / 2.0; 
} 