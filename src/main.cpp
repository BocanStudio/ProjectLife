// 
// MAIN.CPP [PROJECT LIFE]
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

#include <array>

#include "./printer/printer.hpp"
#include "./cell/cell.hpp"


int main(int argc, char** argv) {

    // initialize the Printer
    bocan::life::Printer printer;
    printer.SetupScreen();
   
    const int k_game_space_h = 35;
    const int k_game_space_w = 106;

    // initialize game seed
    bocan::life::Cell main_grid[k_game_space_h * k_game_space_w];
    bocan::life::Cell temp_grid[k_game_space_h * k_game_space_w];
   
    

    //  WIDTH = 4
    //  HEIGHT = 3
    //  ARRAY[3*4]
    //  HHHH -> ARRAY[I(0)*WIDTH + J]
    //  HHHH -> ARRAY[1(1)*WIDTH + J]
    //  HHHH -> ARRAY[I(2)*WIDTH + J]
    //
    

    main_grid[(20 * k_game_space_w) + 50].MakeLive();
    main_grid[(20 * k_game_space_w) + 51].MakeLive();
    main_grid[(21 * k_game_space_w) + 51].MakeLive();
    main_grid[(21 * k_game_space_w) + 49].MakeLive();

    // print the start seed
    printer.RefreshGameSpace(main_grid, k_game_space_h, k_game_space_w);

    // scan main array against rule set
    // rule 1: any live cell with fewer than two live neighbors dies, as if by underpopulation
    // rule 2: any live cell with two or three live neighbors lives on to the next generation
    // rule 3: any live cell with more than three live neighbors dies, as if by overpopulation
    // rule 4: any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction
    
    // algorithm strategy
    // scan every cell in the array
    // if cell is dead, scan neighbors to determine against rule 4
    // if cell is live, scan neighbors to determine against rules 1-3
    
    
    for(int i = 0; i < k_game_space_h; i++) {
        for(int j = 0; j < k_game_space_w; j++) {
            // now looking at each Cell individually
            
            int count = 0;

            // left top corner
            if(i == 0 && j == 0) {
                
                // check east neighbor
                count += main_grid[(i * k_game_space_w) + (j+1)].IsLive();
                
                // check southeast neighbor
                count += main_grid[((i+1) * k_game_space_w) + (j+1)].IsLive();

                // check south neighbor
                count += main_grid[((i+1) * k_game_space_w) + j].IsLive();
                
            // right top corner
            } else if(i == 0 && j == k_game_space_w -1) {

                // check west neighbor
                count += main_grid[(i * k_game_space_w) + (j-1)].IsLive();

                // check southwest neighbor
                count += main_grid[((i+1) * k_game_space_w) + (j-1)].IsLive();

                // check south neighbor
                count += main_grid[((i+1) * k_game_space_w) + j].IsLive();

            // left bottom corner
            } else if(i == k_game_space_h && j == 0) {

                // check north neighbor
                count += main_grid[((i-1) * k_game_space_w) + j].IsLive();

                // check northeast neighbor
                count += main_grid[((i-1) * k_game_space_w) + (j+1)].IsLive();

                // check east neighbor
                count += main_grid[(i * k_game_space_w) + (j+1)].IsLive();

            // right bottom corner
            } else if(i == k_game_space_h && j == k_game_space_w) {

                // check north neighbor
                count += main_grid[((i-1) * k_game_space_w) + j].IsLive();

                // check northwest neighbor
                count += main_grid[((i-1) * k_game_space_w) + (j-1)].IsLive();

                // check west neighbor
                count += main_grid[(i * k_game_space_w) + (j-1)].IsLive();

            // top row
            } else if(i == 0) {

                // check west neighbor
                count += main_grid[(i * k_game_space_w) + (j-1)].IsLive();

                // check southwest neighbor
                count += main_grid[((i+1) * k_game_space_w) + (j-1)].IsLive();

                // check south neighbor
                count += main_grid[((i+1) * k_game_space_w) + j].IsLive();

                // check southeast neighbor
                count += main_grid[((i+1) * k_game_space_w) + (j+1)].IsLive();
                
                // check east neighbor
                count += main_grid[(i * k_game_space_w) + (j+1)].IsLive();
                

            // bottom row
            } else if(i == k_game_space_h) {

                // check west neighbor
                count += main_grid[(i * k_game_space_w) + (j-1)].IsLive();

                // check northwest neighbor
                count += main_grid[((i-1) * k_game_space_w) + (j-1)].IsLive();

                // check north neighbor
                count += main_grid[((i-1) * k_game_space_w) + j].IsLive();

                // check northeast neighbor
                count += main_grid[((i-1) * k_game_space_w) + (j+1)].IsLive();

                // check east neighbor
                count += main_grid[(i * k_game_space_w) + (j+1)].IsLive();

            // left column
            } else if (j == 0) {

                // check north neighbor
                count += main_grid[((i-1) * k_game_space_w) + j].IsLive();

                // check northeast neighbor
                count += main_grid[((i-1) * k_game_space_w) + (j+1)].IsLive();

                // check east neighbor
                count += main_grid[(i * k_game_space_w) + (j+1)].IsLive();

                // check southeast neighbor
                count += main_grid[((i+1) * k_game_space_w) + (j+1)].IsLive();
                
                // check south neighbor
                count += main_grid[((i+1) * k_game_space_w) + j].IsLive();

            // right column
            } else if (j == k_game_space_w) {

                // check north neighbor
                count += main_grid[((i-1) * k_game_space_w) + j].IsLive();
                
                // check northwest neighbor
                count += main_grid[((i-1) * k_game_space_w) + (j-1)].IsLive();

                // check west neighbor
                count += main_grid[(i * k_game_space_w) + (j-1)].IsLive();

                // check southwest neighbor
                count += main_grid[((i+1) * k_game_space_w) + (j-1)].IsLive();

                // check south neighbor
                count += main_grid[((i+1) * k_game_space_w) + j].IsLive();


            // array body
            } else {

                // check north neighbor
                count += main_grid[((i-1) * k_game_space_w) + j].IsLive();
                
                // check northwest neighbor
                count += main_grid[((i-1) * k_game_space_w) + (j-1)].IsLive();

                // check west neighbor
                count += main_grid[(i * k_game_space_w) + (j-1)].IsLive();

                // check southwest neighbor
                count += main_grid[((i+1) * k_game_space_w) + (j-1)].IsLive();

                // check south neighbor
                count += main_grid[((i+1) * k_game_space_w) + j].IsLive();

                // check southeast neighbor
                count += main_grid[((i+1) * k_game_space_w) + (j+1)].IsLive();
                
                // check east neighbor
                count += main_grid[(i * k_game_space_w) + (j+1)].IsLive();

                // check northeast neighbor
                count += main_grid[((i-1) * k_game_space_w) + (j+1)].IsLive();
            }
            
            // all cell neighbors have been checked, count reflects number of live neighbors
            
            // rules for live cell
            if(main_grid[(i * k_game_space_w) + j].IsLive()) {
                    if(count == 2 || count == 3) 
                        temp_grid[(i * k_game_space_w) + j].MakeLive();
                    if(count < 2 || count > 3)
                        temp_grid[(i * k_game_space_w) + j].MakeDead();
            // rules for dead cell
            } else {
                    if(count == 3)
                        temp_grid[(i * k_game_space_w) + j].MakeLive();
            }
        }
    }
    

    printer.EndScreen();

//    std::array<std::array<bocan::life::Cell, 115>, 35> grid;
    
    // import seed (initial state) from file
    //
    // game loop

    return 0;
}
