#include "ncurses.h"
#include "string.h"

int main() 
{
    initscr();
    echo();
    // echo() noecho()
    // raw() cbreak()
    // keypad()
    char buf[80];
    char bla[] = "Salut";
    int row, col;
    getmaxyx(stdscr, row, col);
    mvprintw(4, (col-strlen(bla)) / 2, "%s", bla);
    attron(A_REVERSE);
    mvprintw(row/2, 5, "Input: ");
    attroff(A_REVERSE);
    move(row/2, 12);
    do {
        getstr(buf);
        mvprintw(6, 20, "You entered: %s", buf);
    } while (strcmp(buf, "STOP"));
    refresh();
    endwin();
    return 0;    
}
