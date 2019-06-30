// Method 2 (Use temporary array)
// K largest elements from arr[0..n-1]

// 1) Store the first k elements in a temporary array temp[0..k-1].
// 2) Find the smallest element in temp[], let the smallest element be min.
// 3-a) For each element x in arr[k] to arr[n-1]. O(n-k)
// If x is greater than the min then remove min from temp[] and insert x.
// 3-b)Then, determine the new min from temp[]. O(k)
// 4) Print final k elements of temp[]

// Time Complexity: O((n-k)*k). If we want the output sorted then O((n-k)*k + klogk)


// Method 4 (Use Max Heap)
// 1) Build a Max Heap tree in O(n)
// 2) Use Extract Max k times to get k maximum elements from the Max Heap O(klogn)

// Time complexity: O(n + klogn)






// Method 5(Use Oder Statistics)
// 1) Use order statistic algorithm to find the kth largest element. Please see the topic selection in worst-case linear time O(n)
// 2) Use QuickSort Partition algorithm to partition around the kth largest number O(n).
// 3) Sort the k-1 elements (elements greater than the kth largest element) O(kLogk). This step is needed only if sorted output is required.

// Time complexity: O(n) if we don’t need the sorted output, otherwise O(n+kLogk)
// Following is complete algorithm.

// kthSmallest(arr[0..n-1], k)
// 1) Divide arr[] into ⌈n/5⌉ groups where size of each group is 5 
//    except possibly the last group which may have less than 5 elements.  

// 2) Sort the above created ⌈n/5⌉ groups and find median 
//    of all groups. Create an auxiliary array 'median[]' and store medians 
//    of all ⌈n/5⌉ groups in this median array.

// // Recursively call this method to find median of median[0..⌈n/5⌉-1]
// 3) medOfMed = kthSmallest(median[0..⌈n/5⌉-1], ⌈n/10⌉)

// 4) Partition arr[] around medOfMed and obtain its position.
//      pos = partition(arr, n, medOfMed)

// 5) If pos == k return medOfMed 
// 6) If pos > k return kthSmallest(arr[l..pos-1], k) 
// 7) If pos < k return kthSmallest(arr[pos+1..r], k-pos+l-1)
// In above algorithm, last 3 steps are same as algorithm in previous post. The first four steps are used to obtain a good point for partitioning the array (to make sure that there are not too many elements either side of pivot).

// Following is the implementation of above algorithm.
// filter_none
// edit
// play_arrow

// brightness_4
// iC++ implementation of worst case linear time algorithm 
// to find k'th smallest element 
// Implememntation . 

#include<iostream> 
#include<algorithm> 
#include<climits> 
  
using namespace std; 
  
int partition(int arr[], int l, int r, int k); 
  
// A simple function to find median of arr[].  This is called 
// only for an array of size 5 in this program. 
int findMedian(int arr[], int n) 
{ 
    sort(arr, arr+n);  // Sort the array 
    return arr[n/2];   // Return middle element 
} 
  
// Returns k'th smallest element in arr[l..r] in worst case 
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT 
int kthSmallest(int arr[], int l, int r, int k) 
{ 
    // If k is smaller than number of elements in array 
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; // Number of elements in arr[l..r] 
  
        // Divide arr[] in groups of size 5, calculate median 
        // of every group and store it in median[] array. 
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n) //For last group with less than 5 elements 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        // Find median of all medians using recursive call. 
        // If median[] has only one element, then no need 
        // of recursive call 
        int medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        // Partition the array around a random element and 
        // get position of pivot element in sorted array 
        int pos = partition(arr, l, r, medOfMed); 
  
        // If position is same as k 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  // If position is more, recur for left 
            return kthSmallest(arr, l, pos-1, k); 
  
        // Else recur for right subarray 
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    // If k is more than number of elements in array 
    return INT_MAX; 
} 
  
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
// It searches for x in arr[l..r], and partitions the array  
// around x. 
int partition(int arr[], int l, int r, int x) 
{ 
    // Search for x in arr[l..r] and move it to end 
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
    // Standard partition algorithm 
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 
  
// Driver program to test above methods 
int main() 
{ 
    int arr[] = {12, 3, 5, 7, 4, 19, 26}; 
    int n = sizeof(arr)/sizeof(arr[0]), k = 3; 
    cout << "K'th smallest element is "
         << kthSmallest(arr, 0, n-1, k); 
    return 0; 
}



// Usimg median of medians;







// Method 6 (Use Min Heap)
// This method is mainly an optimization of method 1. Instead of using temp[] array, use Min Heap.

// 1) Build a Min Heap MH of the first k elements (arr[0] to arr[k-1]) of the given array. O(k)

// 2) For each element, after the kth element (arr[k] to arr[n-1]), compare it with root of MH.
// ……a) If the element is greater than the root then make it root and call heapify for MH
// ……b) Else ignore it.
// // The step 2 is O((n-k)*logk)

// 3) Finally, MH has k largest elements and root of the MH is the kth largest element.

// Time Complexity: O(k + (n-k)Logk) without sorted output. If sorted output is needed then O(k + (n-k)Logk + kLogk)

// All of the above methods can also be used to find the kth largest (or smallest) element.


