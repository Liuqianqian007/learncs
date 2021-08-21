
#include <ncurses.h>

WINDOW *create_win(int height, int width, int starty, int startx, int color);
void draw_gate(WINDOW *win);

int main(int argc, char *argv[]) {

    initscr();
    curs_set(FALSE);

    refresh();
    
    start_color();

    int playground_h = LINES * 0.65, playground_w = COLS * 0.8;
    int field_h = playground_h - 2, field_w = playground_w - 4;
    int help_h = LINES  * 0.65, help_w = COLS * 0.2;
    int notice_h = LINES * 0.2, notice_w = COLS * 0.8;
    int score_h = LINES * 0.2, score_w = COLS * 0.2;
    int control_h = LINES * 0.15, control_w = playground_w + help_w;

    WINDOW *playground = create_win(playground_h, playground_w, 0, 0, COLOR_RED);
    init_pair(1, COLOR_RED, use_default_colors());
    wbkgd(playground, COLOR_PAIR(1));
    wrefresh(playground);
    WINDOW *field = create_win(field_h, field_w, 1, 2, COLOR_WHITE);
    WINDOW *help = create_win(help_h, help_w, 0, playground_w , COLOR_WHITE);
    WINDOW *notice = create_win(notice_h, notice_w, playground_h, 0, COLOR_WHITE);
    WINDOW *score = create_win(score_h, score_w, playground_h, playground_w, COLOR_WHITE);
    WINDOW *control = create_win(control_h, control_w, playground_h + notice_h, 0, COLOR_WHITE);

    char help_title[] = "Help";
    char help_content1[] = "W/A/S/D - Move";
    char help_content2[] = "J - Stop ball";
    char help_content3[] = "K - Kick ball";
    char help_content4[] = "L - Carry ball";

    mvwprintw(help, 1, help_w / 2 - 2, help_title);
    mvwprintw(help, 3, help_w / 2 - 7, help_content1);
    mvwprintw(help, 4, help_w / 2 - 7, help_content2);
    mvwprintw(help, 5, help_w / 2 - 7, help_content3);
    mvwprintw(help, 6, help_w / 2 - 7, help_content4);
    wrefresh(help);

    char score_title[] = "Score";
    mvwprintw(score, 1, score_w / 2 - 2, score_title);
    wrefresh(score);

    char my_name[] = "Liu Q";
    mvwprintw(field, field_h / 2, field_w / 2 - 2, my_name);
    wrefresh(field);

    draw_gate(playground);

    getch();
    endwin();
    return 0;

}

WINDOW *create_win(int height, int width, int starty, int startx, int color) {

    init_pair(1, color, use_default_colors());
    WINDOW *win;
    win = newwin(height, width, starty, startx);
    attron(COLOR_PAIR(1));
    box(win, 0, 0);
    wrefresh(win);
    attroff(COLOR_PAIR(1));
    return win;

}

void draw_gate(WINDOW *win) {
    int height, width;
    getmaxyx(win, height, width);
    int mid_h = height / 2;

    init_pair(1, COLOR_BLUE, use_default_colors());
    init_pair(2, COLOR_RED, use_default_colors());

    wattron(win, COLOR_PAIR(2));
    for (int i = -3; i <= 3; ++i) {
        mvwaddch(win, mid_h + i, width - 2, 'x');
    }
    wattroff(win, COLOR_PAIR(2));
    wrefresh(win);

    wattron(win, COLOR_PAIR(1));
    for (int i = -3; i <= 3; ++i) {
        mvwaddch(win, mid_h + i, 1, 'x');
    }
    wattroff(win, COLOR_PAIR(1));
    wrefresh(win);
    return;

}
