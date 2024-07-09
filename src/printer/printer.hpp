// 
// PRINTER.HPP [PROJECT LIFE]
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

#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <ncurses.h>

namespace bocan {

namespace life {

class Cell;

class Printer {
public:

    Printer();
    ~Printer();

    void SetupScreen();
    void EndScreen();
    void RefreshScreen();
    void RefreshGameSpace(Cell grid[], int, int);

    bool StartGame();
    bool EndGame();

    void Pause();
    void Exit();

private:

    WINDOW* win_title;
    WINDOW* win_1;
    WINDOW* win_2;
    WINDOW* win_game_space;

private:

    void PrintTitle();
    void PrintWin1();
    void PrintWin2();
    void PrintGameSpace(Cell grid[], int, int);

};

} // NAMESPACE LIFE

} // NAMESPACE BOCAN

#endif // PRINTER_HPP
