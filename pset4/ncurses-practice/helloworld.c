#include <ncurses.h>

int main(void) {
    initscr();                      // Initialize the screen
    printw("Hello world !!!");      // Equivalent to printf, prints to a buffer
    refresh();                      // Flush the buffer to screen
    getch();                        // Wait for user input
    endwin();                       // Free memory allocated for screen
    
    return 0;
}