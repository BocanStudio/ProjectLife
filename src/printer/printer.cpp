// 
// PRINTER.CPP [PROJECT LIFE]
// C++ VERSION GNU++14
// macOS 11.7.10
// DUAL-CORE INTEL CORE i5 @ 2.8 GHZ
//
// GITHUB REPOSITORY https://github.com/buchananmatt/ProjectLife.git
//
// THIS PROJECT IS DOCUMENTED WITH DOXYGEN. SEE DOCUMENTATION AT BELOW SITE.
// https://htmlpreview.github.io/?https://github.com/buchananmatt/ProjectLife/blob/master/doc/html/index.html
//
// COPYRIGHT [2023] [MATTHEW T. BUCHANAN] [BOCAN SOFTWARE]
//
// LICENSED UNDER THE APACHE LICENSE, VERSION 2.0 (THE "LICENSE");
// YOU MAY NOT USE THIS FILE EXCEPT IN COMPLIANCE WITH THE LICENSE.
// YOU MAY OBTAIN A COPY OF THE LICENSE AT 
//
// http://www.apacher.org/licenses.LICENSE-2.0
//
// UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING, SOFTWARE
// DISTRIBUTED UNDER THE LICENSE IS DISTRIBUTED ON AN "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
// SEE THE LICENSE FOR THE SPECIFIC LANGUAGE GOVERNING PERMISSIONS AND
// LIMITATIONS UNDER THE LICENSE.


#include "../cell/cell.hpp"
#include "../printer/printer.hpp"

using bocan::life::Printer;
using bocan::life::Cell;

Printer::Printer() {

}

Printer::~Printer() {

}

void Printer::SetupScreen() {

    // ncurses window setup
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, false);
    nodelay(stdscr, false);

    // total screen size ... columns x ... rows
    // screen begins on column ... and row ...
    win_title = newwin(5, 50, 1, 30);
    win_1 = newwin(5, 24, 1, 2);
    win_2 = newwin(5, 24, 1, 84);
    win_game_space = newwin(35, 106, 6, 2);

    // draw borders around each window
    wborder(win_title, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(win_1, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(win_2, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(win_game_space, 0, 0, 0, 0, 0, 0, 0, 0);

    // print each window
    PrintTitle();
    PrintWin1();
    PrintWin2();

}

void Printer::EndScreen() {

    delwin(win_title);
    delwin(win_1);
    delwin(win_2);
    delwin(win_game_space);
    endwin();
}

void Printer::RefreshScreen() {

    PrintTitle();
    PrintWin1();
    PrintWin2();
}

void Printer::RefreshGameSpace(Cell grid[], int rows, int cols) {
    
    PrintGameSpace(grid, rows, cols);
}

bool Printer::StartGame() {

    return true;
}

bool Printer::EndGame() {

    return true;
}

void Printer::Pause() {

}

void Printer::Exit() {

}

void Printer::PrintTitle() {

    // clear the window
    werase(win_title); 
    wborder(win_title, 0, 0, 0, 0, 0, 0, 0, 0);

    // print the game title
    wmove(win_title, 1, 19);
    static_cast<void> ( waddstr(win_title, "PROJECT LIFE") );

    wmove(win_title, 3, 4);
    static_cast<void> ( waddstr(win_title, "[2023] [MATTHEW BUCHANAN] [BOCAN SOFTWARE]") );

    wrefresh(win_title);
}

void Printer::PrintWin1() {

    wrefresh(win_1);
}

void Printer::PrintWin2() {

    wrefresh(win_2);
}

void Printer::PrintGameSpace(Cell grid[], int rows, int cols) {

    int counter = 1;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[(i * cols) + j].IsAlive()) {
                wmove(win_game_space, i, j);
                static_cast<void> ( waddch(win_game_space, '#') );
            
                //wmove(win_game_space, 33, counter);
                //static_cast<void> ( waddch(win_game_space, j) );
                //counter += 5;
                //wmove(win_game_space, 33, counter);
                //static_cast<void> ( waddch(win_game_space, i) );
                //counter += 5;
            }
        }
    }
    
    wrefresh(win_game_space);

    wmove(win_game_space, 33, 1);
    static_cast<void> ( flushinp() );
    int ch =  wgetch(win_game_space);
}

