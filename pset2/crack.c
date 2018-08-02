#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

// Initialize global variables needed by recursive functions
char guess[9] = {'\0'};
char salt[3] = {'\0'}; 
int place = 0;
bool solved = false;
bool end = false;
char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    

// Recursive function prototypes
bool first_right(char *hash);
bool second_right(char *hash);
bool third_right(char *hash);
bool fourth_right(char *hash);
bool fifth_right(char *hash);
bool sixth_right(char *hash);
bool seventh_right(char *hash);
bool eighth_right(char *hash);

int main(int argc, char *argv[]) {
    
    // Error checking command-line arguments
    if (argc != 2) {
        printf("Please provide exactly one command-line argument.\n");
        return 1;
    }
    
    // Parse for the salt
    char *hash = argv[1];
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    
    // Check first for a one-character password, then for a two-character
    // password, and so on. If at any point the password is found, return.
    if (first_right(hash)) return 0;
    place++;
    if(second_right(hash)) return 0;
    place++;
    if(third_right(hash)) return 0;
    place++;
    if(fourth_right(hash)) return 0;
    place++;
    if(fifth_right(hash)) return 0;
    place++;
    if(sixth_right(hash)) return 0;
    place++;
    if(seventh_right(hash)) return 0;
    place++;
    if(eighth_right(hash)) return 0;
    
    // There must have been an error
    printf("Sorry, error.\n");
    return 2;
}

bool first_right(char *hash) {
    // Iterate through from 'A' to 'z' in alphabet
    for (char c = 0; c < 52; c++) {
        guess[place] = alphabet[c];
        
        // For each iteration, check to see if guess is right
        if (strcmp(hash, crypt(guess, salt)) == 0) {
            printf("%s\n", guess);
            // If so, return true
            return true;
        }
    }
    
    // Otherwise, return false
    return false;
}

bool second_right(char *hash) {
    for (char c = 0; c < 52; c++) {
        guess[place - 1] = alphabet[c];
        
        // If at any point the lower function returns true, return true
        if(first_right(hash)) return true;
    }
    
    return false;
}

bool third_right(char *hash) {
    for (char c = 0; c < 52; c++) {
        guess[place - 2] = alphabet[c];
        if(second_right(hash)) return true;
    }
    
    return false;
}

bool fourth_right(char *hash) {
    for (char c = 0; c < 52; c++) {
        guess[place - 3] = alphabet[c];
        if(third_right(hash)) return true;
    }
    
    return false;
}

bool fifth_right(char *hash) {
    for (char c = 0; c < 52; c++) {
        guess[place - 4] = alphabet[c];
        if(fourth_right(hash)) return true;
    }
    
    return false;
}

bool sixth_right(char *hash) {
    for (char c = 0; c < 52; c++) {
        guess[place - 5] = alphabet[c];
        if(fifth_right(hash)) return true;
    }
    
    return false;
}

bool seventh_right(char *hash) {
    for (char c = 0; c < 52; c++) {
        guess[place - 6] = alphabet[c];
        if(sixth_right(hash)) return true;
    }
    
    return false;
}

bool eighth_right(char *hash) {
    for (char c = 0; c < 52; c++) {
        guess[place - 7] = alphabet[c];
        if(seventh_right(hash))return true;
    }
    
    return false;
}