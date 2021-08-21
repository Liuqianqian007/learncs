/*************************************************************************
	> File Name: football.c
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 23 Apr 2021 08:31:20 PM CST
 ************************************************************************/

#include <ncurses.h>

void draw_rectangular(int starty, int startx, int height, int width);
int main(int argc, char *argv[]) {
    //keypad(stdscr, TRUE);
    //cbreak();


    initscr();
    curs_set(FALSE);


    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    printw("Hello world");
    refresh();

    draw_rectangular(3, 3, 15, 15);

    attroff(COLOR_PAIR(1));


    WINDOW *win_1;
    win_1 = newwin(5, 5, 5, 5);
    wborder(win_1, '|', '|', '_','_', '.', '.', '.', '.');
    wrefresh(win_1);


    getch();
    endwin();
    return 0;

}

void draw_rectangular(int starty, int startx, int height, int width) {
    
    mvaddch(starty, startx, ACS_ULCORNER);
    mvaddch(starty + height - 1, startx + width - 1, ACS_LRCORNER);
    mvaddch(starty + height - 1, startx, ACS_LLCORNER);

    for(int i = 1; i < width - 1; i++) {
        addch(ACS_HLINE);
        mvaddch(starty, startx + i, ACS_HLINE);
        mvaddch(starty + height - 1, startx + i, ACS_HLINE);
    }
    //mvhline(starty, startx + 1, '-', width - 1);
    mvaddch(starty, startx + width - 1, ACS_URCORNER);

    
    for(int i = 1; i < height - 1; i++) {
        mvaddch(starty + i, startx, ACS_VLINE);
        mvaddch(starty + i, startx + width - 1, ACS_VLINE);
    }
    

    return;
}
