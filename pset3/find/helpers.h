/****************************************************************************
 * helpers.h
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
 
#include <cs50.h>


/*
 * Returns true if value is in array of n values, else false.
 * search() represents search initilization, binary_search()
 * represents the actual recursive process of searching.
 */

bool 
search(int value, int values[], int n);

bool
binary_search(int value, int values[], int n, int l, int r);

/*
 * Sorts array of n values.  Returns true if
 * successful, else false.
 */

bool
sort(int values[], int n);
