/***************************************************************************
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void god(void);


int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();
    
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        char *input_tile = GetString();
        int tile = atoi(input_tile);
        
        if (tile != 0) {

            // User inputted a number
            // move if possible, else report illegality
            if (!move(tile))
            {
                printf("\nIllegal move.\n");
                usleep(500000);
            }

            // sleep thread for animation's sake
            usleep(500000);
            
        } else if (strcmp(input_tile, "GOD") == 0) {
            
            // If user inputted "GOD", execute god mode
            god();
            
        } else if (strcmp(input_tile, "quit") == 0 ||
                   strcmp(input_tile, "q") == 0 || 
                   strcmp(input_tile, "QUIT") == 0 ||
                   strcmp(input_tile, "Q") == 0)
        {
            // User wants to quit the program
            return 0;
        } else {
            // User inputted "0" or a string other than "GOD"
            printf("\nIllegal move.\n");
            usleep(1000000);
        }
    }

    // that's all folks
    return 0;
}


/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * Greets player.
 */

void
greet(void)
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(500000);
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(void)
{
    int count = 1;
    
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            board[i][j] = count;
            count++;
        }
    }
    board[d-1][d-1] = 0;
    
    
    for (int i = 0; i < 10000; i++) {
        srand((unsigned int) i * time(NULL));
        move(rand() % (DIM_MAX * DIM_MAX));
    }
}


/* 
 * Prints the board in its current state.
 */

void
draw(void)
{
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (board[i][j] != 0)
                printf("%2d  ", board[i][j]);
            else printf("__  ");
        }
        printf("\n");
    }
}


/* 
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(int tile)
{
    if (tile > d*d - 1 || tile <= 0) return false;
    
    int i;
    int j;
    for (i = 0; i < d; i++) {
        for (j = 0; j < d; j++) {
            if (board[i][j] == tile)
                break;
        }
        if (board[i][j] == tile)
                break;
    }
    
    if (i > 0 && board[i - 1][j] == 0)
        board[i - 1][j] = board[i][j];
    else if (i < d - 1 && board[i + 1][j] == 0)
        board[i + 1][j] = board[i][j];
    else if (j > 0 && board[i][j - 1] == 0)
        board[i][j - 1] = board[i][j];
    else if (j < d - 1 && board[i][j + 1] == 0)
        board[i][j + 1] = board[i][j];
    else
        return false;
    
    board[i][j] = 0;
    return true;
}


/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won(void)
{
    if (board[d-1][d-1] != 0) return false;
    int count = 1;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (board[i][j] != count && count != d*d) return false;
            count++;
        }
    }
    
    return true;
}

void god(void) {
    int i = 0;
    int n = 0;
    while (!won()){
        srand((unsigned int) i * time(NULL));
        move(rand() % (DIM_MAX * DIM_MAX - n) + n);
        i++;
        
        clear();
        draw();
        usleep(100);
    }
    
}
