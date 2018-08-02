#include <ncurses.h>

int main(void) {
    int ch;
    
    initscr();
    raw();                          // Disable line buffering
    keypad(stdscr, TRUE);           // Get function, arrow, etc. keys
    noecho();                       // Don't echo getch()
    
    printw("Type any character to see it in bold:\n");
    ch = getch();
    
    if (ch == KEY_F(1))             // So F1 doesn't print random characters
        printw("F1 key pressed!");
    
    else {
        printw("The pressed key is: ");
        attron(A_BOLD);             // Bold attribute on
        printw("%c", ch);
        attroff(A_BOLD);            // Bold attribute off
    }
    
    refresh();
    getch();                        // Wait for user input
    endwin();
    
    return 0;
}