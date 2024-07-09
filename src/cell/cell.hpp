// 
// CELL.HPP [PROJECT LIFE]
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

#ifndef CELL_HPP
#define CELL_HPP

namespace bocan {

namespace life {

enum {
    DEAD = 0,
    LIVE = 1 
};

class Cell {
public:
    Cell();
    ~Cell();

    void MakeLive();
    void MakeDead();
   
    bool IsLive();
    bool GetNextState();
    
    void AnalyzeNeighbors();

private:

    bool m_state;
    int  m_total_lives;

    // if I go this route, need to figure out how to initialize these pointers when creating the array.
    //Cell* m_cell_north;
    //Cell* m_cell_northeast;
    //Cell* m_cell_northwest;
    //Cell* m_cell_east;
    //Cell* m_cell_west;
    //Cell* m_cell_south;
    //Cell* m_cell_southeast;
    //Cell* m_cell_southwest;

};

} // NAMESPACE LIFE

} // NAMESPACE BOCAN

#endif // CELL_HPP
