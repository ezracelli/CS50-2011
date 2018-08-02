/**************************************************************************** 
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

#define LIMIT 65536

/*
 * Returns true if value is in array of n values, else false.
 * search() represents search initilization, binary_search()
 * represents the actual recursive process of searching.
 */

bool 
search(int value, int array[], int n)
{
    // Initialize l and r bounds values
    int l = 0;
    int r = n - 1;
    
    // Begin searching
    if(binary_search(value, array, n, l, r)) return true;
    else return false;
}

// Algorithm via Wikipedia, originally from:
// The Art of Computer Programming, The: Volume 3: Sorting and Searching
// (c) 1998 Donald Knuth
bool binary_search(int value, int array[], int n, int l, int r) {
    
    // Out of bounds means value was not found
    if (l > r) return false;
    
    // Calculate location of the middle value of array
    int m = (l + r) / 2;
    
    if (array[m] > value) {
        // If middle value is greater than target value, search left half
        r = m - 1;
        if (binary_search(value, array, n, l, r)) return true;
    } else if (array[m] < value) {
        // If middle value is less than target value, search right half
        l = m + 1;
        if (binary_search(value, array, n, l, r)) return true;
    } else
        // Else middle value must be equal to target value
        return true;
    
    // Catch-all for compiler
    return false;
}


/*
 * Sorts array of n values.  Returns true if
 * successful, else false.
 */

bool
sort(int values[], int n)
{
    // Bucket sort
    
    // Initialize buckets, one for each possible number from 0..LIMIT
    int buckets[LIMIT] = {0};
    
    // Increment the bucket corresponding to each number in values
    int i;
    for (i = 0; i < n; i++) {
        buckets[values[i]]++;
    }
    
    // Iterate through buckets, copying bucket[i] of each i into values
    int j;
    for (i = 0, j = 0; i < LIMIT; i++) {
        if (buckets[i] > 0) {
            values[j] = i;
            j++;
            buckets[i]--;
            i--;
        }
    }
    
    // If any value is less than the one before it, the list was not
    // sorted correctly, so return false
    for (i = 1; i < n; i++) {
        if (values[i] < values[i - 1]) return false;
    }
    
    // Success
    return true;
}
