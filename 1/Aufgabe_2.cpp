#include <iostream>
#include "CAbase.h"

int main () {
    // Constructor mit Parametern
    // Kugelform?
    // Header nur Klassen
    // CAbase.cpp mit Klassenfunktionalität
    // main

    CAbase ca;
    ca.set_raster(30,30);
    int ran_row, ran_col;
    for (int i=0;i<100;++i) {
        ran_row = rand() % 30 + 1;
        ran_col = rand() % 30 + 1;
        ca.current_status[30*ran_row + ran_col] = '*';
    }

    ca.set_cell(15,15);
    ca.set_cell(15,16);
    ca.set_cell(17,17);
    ca.set_cell(1,20);
    ca.set_cell(4,16);

    ca.print();

    int entry;
    int row, col, rows, cols;
    do {
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. Evolve" << std::endl;
        std::cout << "2. Set Alive cell" << std::endl;
        std::cout << "3. Reprint" << std::endl;
        std::cout << "4. Resize\n\n" << std::endl;
        std::cin >> entry;
        switch (entry) {
            case 1:
                ca.call_evolve();
                break;
            case 2:
                std::cout << "Row: " << std::endl;
                std::cin >> row;
                std::cout << "Col: " << std::endl;
                std::cin >> col;
                ca.set_cell(row, col);
                break;
            case 3:
                ca.print();
                break;
            case 4:
                std::cout << "# of Rows: " << std::endl;
                std::cin >> rows;
                std::cout << "# of Cols: " << std::endl;
                std::cin >> cols;
                ca.~CAbase();
                ca.set_raster(rows, cols);
                break;
        }

    } while (entry != 0);


    // ca.get_raster();

    // ca.set_cell(3,3);

    /*ca.get_status(1,1);
    ca.get_status(1,3);
    ca.get_status(-2,2); */
    //ca.get_status_following(2,3);
    //ca.call_evolve();
    //ca.print();

    // ca.print();

}
