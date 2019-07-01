//Sort all even numbers in ascending order and then sort all odd numbers in descending order

// Method 1 (Using Partition)

// Partition the input array such that all odd elements are moved to left and all even elements on right. This step takes O(n).
// Once the array is partitioned, sort left and right parts individually. This step takes O(n Log n).




//Implementation 
void twoWaySort(int arr[], int n) 
{ 
    // Current indexes from left and right 
    int l = 0, r = n-1; 
  
    // Count of odd numbers 
    int k = 0; 
  
    while (l < r) 
    { 
        // Find first odd number from left side. 
        while (arr[l]%2 != 0) 
        { 
            l++; 
            k++; 
        } 
  
        // Find first even number from right side. 
        while (arr[r]%2 == 0  && l<r) 
            r--; 
  
        // Swap odd number present on left and even 
        // number right. 
        if (l < r) 
            swap(arr[l], arr[r]); 
    } 
  
    // Sort odd number in descending order 
    sort(arr, arr+k, greater<int>()); 
  
    // Sort even number in ascending order 
    sort(arr+k, arr+n); 
} 


// Method 2 (Using negative multiplication) :

// Make all odd numbers negative.
// Sort all numbers.
// Revert the changes made in step 1 to get original elements back.
// filter_none

//Implementation 

void twoWaySort(int arr[], int n) 
{ 
    // Make all odd numbers negative 
    for (int i=0 ; i<n ; i++) 
        if (arr[i] & 1) // Check for odd 
            arr[i] *= -1; 
  
    // Sort all numbers 
    sort(arr, arr+n); 
  
    // Retaining original array 
    for (int i=0 ; i<n ; i++) 
        if (arr[i] & 1) 
            arr[i] *= -1; 
} 
//
// Does not work  with - ve no already in the array

