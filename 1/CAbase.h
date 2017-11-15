#ifndef CABASE_H_INCLUDED
#define CABASE_H_INCLUDED
#include <iostream>
#include <algorithm>    // std::count
#include <vector>       // std::vector

class CAbase {
    public:
        CAbase();
        ~CAbase();
        int Nx;
        int Ny;
        char **current_status = new char*[Nx+2];
        char *following_status = new char[Nx*Ny];
        void get_raster();
        void set_raster(int, int);
        void set_cell(int, int);
        void print();
};

CAbase::CAbase() {
    std::cout << "Universe is being created" << std::endl;
}

CAbase::~CAbase() {
    std::cout << "Universe is being destroyed" << std::endl;
    // delete universe???
}

void CAbase::get_raster() {
    std::cout << "Width of universe: "<< Nx << std::endl;
    std::cout << "Length of universe: "<< Ny << std::endl;
}

void CAbase::set_raster(int x, int y) {
    Nx = x;
    Ny = y;
    for (int i = 0; i < Nx+3; ++i ) {
      current_status[i] = new char[Ny+2];
    }
    for (int i = 0; i < Nx+3; ++i ) {
        current_status[i][0] = '|';
        //current_status[0][i] = '-';
        current_status[i][Nx+1] = '|';
        //current_status[Nx+1][i] = '-';
      }
    for (int j = 0; j < Ny+3; ++j ) {
        //current_status[i][0] = '|';
        current_status[0][j] = '-';
        //current_status[5][Nx+1] = '|';
        current_status[Ny+1][j] = '-';
    }

}


void CAbase::set_cell(int x, int y) {
    current_status[x][y] = '*';
}

void CAbase::print() {
    for (int i = 0; i<Nx+2; i++) {
        for(int j = 0; j<Ny+2; j++) {
            std::cout << current_status[i][j];
        }
    std::cout << std::endl;
    }
}


void evolve(char cell[int x][int y]) {
    std::vector<char> neighbours [] = {cell[x-1][y-1],cell[x-1][y],cell[x-1][y+1],cell[x][y-1],cell[x][y+1],cell[x+1][y-1],cell[x+1][y],cell[x+1][y+1]};
}

#endif // CABASE_H_INCLUDED
