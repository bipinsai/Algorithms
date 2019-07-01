// //Search in a row wise and column wise sorted matrix


// Input : mat[4][4] = { {10, 20, 30, 40},
//                       {15, 25, 35, 45},
//                       {27, 29, 37, 48},
//                       {32, 33, 39, 50}};
//               x = 29
// Output : Found at (2, 1)


// The number we are searching for is greater than the current number. This will ensure, that all the elements in the current row is smaller than the number we are searching for as we are already at the right-most element and the row is sorted. Thus, the entire row gets eliminated and we continue our search on the next row. Here elimination means we won’t search on that row again.
// The number we are searching for is smaller than the current number. This will ensure, that all the elements in the current column is greater than the number we are searching for. Thus, the entire column gets eliminated and we continue our search on the previous column i.e. the column at the immediate left.
// The number we are searching for is equal to the current number. This will end our search.

//Implementation :
int search(int mat[4][4], int n, int x) 
{ 
    if (n == 0) 
        return -1; 
    int smallest = a[0][0], largest = a[n - 1][n - 1]; 
    if (x < smallest || x > largest) 
        return -1; 
    // set indexes for top right element 
    int i = 0, j = n - 1;  
    while (i < n && j >= 0) { 
        if (mat[i][j] == x) { 
            cout << "n Found at "
                 << i << ", " << j; 
            return 1; 
        } 
        if (mat[i][j] > x) 
            j--; 
        else // if mat[i][j] < x 
            i++; 
    } 
  
    cout << "n Element not found"; 
    return 0; // if ( i==n || j== -1 ) 
} 