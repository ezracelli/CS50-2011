/*******************************************************************
  * pennies.c
  * (c) 2018 Ezra Celli
  *
  * Asks the user how many days there are in a month and how many
  * pennies they will receive on the first day of that month. 
  * Calculates the amount the use will have received in total by
  * the end of the month (not just on the last day) if that amount
  * is doulbed on every day but the first, expressed not as pennies
  * but as dollars and cents, with dollars formatted wtih commas
  * every three digits.
  *
  * If the user does not type in 28, 29, 30, or 31 for the number
  * of days in a month, the program will prompt the user to retry.
  * If the user does not input a positive integer for the first
  * day's number of pennies, the program will prompt the user to
  * retry.
  ******************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    // Get user input for number of days in the month
    int days;
    do {
        printf("Days in month: ");
        scanf("%d", &days);
    } while (days < 28 || days > 31);
    
    // Get user input for number of pennies for first day
    int pennies;
    do {
        printf("Pennies on first day: ");
        scanf("%d", &pennies);
    } while (pennies < 1);
    
    // Calculate result as a long long int
    long long result = pennies * pow(2, days) - 1;
    
    
    // Format result as currency by iterating over two strings, one for
    // the unformatted result and one for the formatted final product.
    
    // Set up formatting strings
    char n_format[27];
    char n_len[25];
    
    // Convert result to an unformatted string n_len and get the length
    sprintf(n_len, "%lli", result);
    int len = strlen(n_len);
    
    // Calculate the length of the to-be-formatted string
    int new_len;
    if (len <= 5) new_len = len + 1;
    else if (len <= 8) new_len = len + 2;
    else if (len <= 11) new_len = len + 3;
    else if (len <= 14) new_len = len + 4;
    else if (len <= 17) new_len = len + 5;
    else new_len = len + 6;
    
    // Set up iteration counters
    int i = 1;
    int j = 1;
    
    // Iterate over unformatted string
    while (i <= new_len) {
        if (i == 3) {
            // If we're at the location of the decimal point
            n_format[new_len - i] = '.';
        } else if (i == 7 || i == 11 || i == 15 || i == 19 || i == 23) {
            // If we're at the location of a comma
            n_format[new_len - i] = ',';
        } else {
            // Copy digit from unformatted string to formatted string
            n_format[new_len - i] = n_len[len - j];
            j++;
        }
        i++;
    }
    
    // Print result as a formatted string
    printf("$%s\n", n_format);
}