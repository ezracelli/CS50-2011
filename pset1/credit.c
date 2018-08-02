/******************************************************************
 * credit.c
 * (c) 2018 Ezra Celli
 *
 * Checks to see if an inputted number is a systemically valid
 * credit card number via Luhn's Algorithm. If so, checks to see
 * if it is Visa, AmEx, or MasterCard.
 ******************************************************************/

#import <stdio.h>

int main(void) {
    
    // Get a credit card number from the user (assuming numeric input)
    long long cc_num = 0;
    int len = 0;
    do {
        printf("Number: ");
        scanf("%lli", &cc_num);
        len = snprintf(0, 0, "%+lli", cc_num) - 1;
    // Verify that it's the length of a possible credit card number
    } while (len != 13 && len != 15 && len != 16);
    
    // Copy each digit into an int array
    int digits[len];
    for (int i = len - 1; i >= 0; i--) {
        digits[i] = cc_num % 10;
        cc_num /= 10;
    }
    
    // Multiply every other digit by 2, starting from the credit card
    // number's second-to-last digit, then sum the products' digits
    int sum = 0;
    for (int i = len - 2; i >= 0; i -= 2) {
        if (digits[i] * 2 >= 10) {
            sum += (digits[i] * 2) % 10;
            sum += (digits[i] * 2) / 10;
        }
        else
            sum += digits[i] * 2;
    }
    
    // Add to the sum the sum of the rest of the cc num's digits
    for (int i = len - 1; i >= 0; i -= 2) {
        sum += digits[i];
    }
    
    // If the sum's last digit is not 0, the card number is invalid
    if (sum % 10 != 0) {
        printf("INVALID\n");
        return 0;
    }
    
    // Check a valid card's network
    if (digits[0] == 4)
        // Visa cards start with 4
        printf("VISA\n");
    else if (digits[0] == 3 && (digits[1] == 4 || digits[1] == 7))
        // American Express card start with 34 or 37
        printf("AMEX\n");
    else if (digits[0] == 5 && (digits[1] == 1 || digits[1] == 2 ||
            digits[1] == 3 || digits[1] == 4 || digits[1] == 5 ))
        // MasterCard cards start with 51 thru 55
        printf("MASTERCARD\n");
    else
        // Card is not Visa, American Express, or MasterCard
        printf("INVALID\n");
}