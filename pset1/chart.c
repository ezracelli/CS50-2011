/******************************************************************
 * chart.c
 * (c) 2018 Ezra Celli
 *
 * Prompts a user for four non-negative integers, after which it
 * generates a vertical bar chart depicting those values, with the
 * first value's bar on the left and the fourth value's bar on the
 * right.
 *
 * Assumes the user's terminal window is at least 18 x 30
 *
 * Example output:
 *
 *      ###
 *      ###
 * ###  ###
 * ###  ###
 * ###  ###       ###
 * ###  ###  ###  ###
 * M4F  F4M  F4F  M4M
 ******************************************************************/

#import <stdio.h>

int main(void) {
    printf("\n");
    
    // Get raw user values for M4F, F4M, F4F, and M4M
    int mf;
    do {
        printf("M spotting F: ");
        scanf("%d", &mf);
    } while (mf < 0);
    
    int fm;
    do {
        printf("F spotting M: ");
        scanf("%d", &fm);
    } while (mf < 0);
    
    int ff;
    do {
        printf("F spotting F: ");
        scanf("%d", &ff);
    } while (mf < 0);
    
    int mm;
    do {
        printf("M spotting M: ");
        scanf("%d", &mm);
    } while (mf < 0);
    
    printf("\nWho is spotting whom?\n\n");
    
    // Convert raw values to a percentage of 20 (the max height)
    int sum = mf + fm + ff + mm;
    int mf_height = (int)((float)mf/(float)sum * 20);
    int fm_height = (int)((float)fm/(float)sum * 20);
    int ff_height = (int)((float)ff/(float)sum * 20);
    int mm_height = (int)((float)mm/(float)sum * 20);
    
    // Find the maximum possible height for given values
    int max_height = mf_height;
    if (fm_height > max_height) max_height = fm_height;
    if (ff_height > max_height) max_height = ff_height;
    if (mm_height > max_height) max_height = mm_height;
    
    // Print the chart
    for (int row = 0; row < max_height; row++){
        for (int col = 0; col < 18; col++){
            if (col == 0 || col == 1 || col == 2) {
                // M4F
                if ((max_height - mf_height) <= row)
                    printf("#");
                else
                    printf(" ");
            } else if (col == 5 || col == 6 || col == 7) {
                // F4M
                if ((max_height - fm_height) <= row)
                    printf("#");
                else
                    printf(" ");
            } else if (col == 10 || col == 11 || col == 12) {
                // F4F
                if ((max_height - ff_height) <= row)
                    printf("#");
                else
                    printf(" ");
            } else if (col == 15 || col == 16 || col == 17) {
                // M4M
                if ((max_height - mm_height) <= row)
                    printf("#");
                else
                    printf(" ");
            } else
                // Guaranteed whitespace
                printf(" ");
        }
        printf("\n");
    }
    
    printf("M4F  F4M  F4F  M4M\n\n");
}