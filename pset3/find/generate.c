/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int
main(int argc, char *argv[])
{
    // Ensure the number of command-line arguments is exactly one or two
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Parse an int n from the first command-line argumen
    int n = atoi(argv[1]);

    // If there exists a second command-line argument, parse it for an int
    // and use that for the seed to srand(). Otherwise, use the current time
    if (argc == 3)
        srand((unsigned int) atoi(argv[2]));
    else
        srand((unsigned int) time(NULL));

    // Print out n ints, each being a rand() from 0..LIMIT
    for (int i = 0; i < n; i++)
        printf("%d\n", rand() % LIMIT);

    // that's all folks
    return 0;
}
