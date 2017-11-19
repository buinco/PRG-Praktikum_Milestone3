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
        char *current_status = new char[Nx*Ny];
        char *following_status = new char[Nx*Ny];
        void get_raster();
        void set_raster(int, int);
        void get_status(int, int);
        void get_status_following(int, int);
        void set_cell(int, int);
        void evolve(int, int);
        void call_evolve();
        void print();
};

CAbase::CAbase() {
    // hier Nx und Ny als Parameter
    std::cout << "Universe is being created\n\n" << std::endl;
}

CAbase::~CAbase() {
    std::cout << "Universe is being destroyed" << std::endl;
    delete[] current_status;
    delete[] following_status;
}

void CAbase::get_raster() {
    std::cout << "Width of universe: "<< Nx-2 << std::endl;
    std::cout << "Length of universe: "<< Ny-2 << std::endl;
}

void CAbase::set_raster(int x, int y) {
    Nx = x+2;
    Ny = y+2;


    for (int i = 0; i<Nx; ++i) {
        for(int j = 0; j<Ny; ++j) {
            current_status[Nx*i+j] = ' ';
            following_status[Nx*i+j] = ' ';
        }
    }


    for (int i = 0; i<Nx; ++i) {
        current_status[Nx*i] = '+';
        current_status[Nx*i+Ny-1] = '+';
        current_status[i] = '+';
        current_status[Nx*Ny-i] = '+';
        following_status[Nx*i] = '+';
        following_status[Nx*i+Ny-1] = '+';
        following_status[i] = '+';
        following_status[Nx*Ny-i] = '+';
    }
}

void CAbase::set_cell(int x, int y) {
    current_status[Nx*x+y] = '*';
}

void CAbase::get_status(int x, int y) {
    if (current_status[Nx*x+y] == '*') {
        std::cout << "Cell is alive" << std::endl;
    }
    else {
        std::cout << "Cell is dead" << std::endl;
    }

}

void CAbase::get_status_following(int x, int y) {
    evolve(x,y);
    if (following_status[Nx*x+y] == '*') {
        std::cout << "Cell will be alive" << std::endl;
    }
    else {
        std::cout << "Cell will be dead" << std::endl;
    }

}

void CAbase::print() {
    std::cout << "\n\n";
    for (int i = 0; i<Nx; ++i) {
        for(int j = 0; j<Ny; ++j) {
            std::cout << current_status[Nx*i+j];
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n";
}

void CAbase::evolve(int x, int y) {
    int counter = 0;

    for (int i=-1;i<=1;++i) {
        for (int j=-1;j<=1;++j) {
            if (current_status[Nx*(x+i)+(y+j)] == '*')
                counter += 1;
        }
    }
    if (current_status[Nx*x+y] == '*'){
        counter -= 1;        // cell itself
    }
    if (counter < 2) {
        following_status[Nx*x+y] = ' ';
    }
    else if (counter == 3) {
        following_status[Nx*x+y] = '*';
    }
    else if (counter == 3 || counter == 2) {
        following_status[Nx*x+y] = current_status[Nx*x+y];
    }
    else if (counter > 3) {
        following_status[Nx*x+y] = ' ';
    }
    if (counter == 3) {
        // std::cout << "Zelle" << x <<"," << y << "hat " << counter << "Nachbarn";
    }

    // kugelförmige fläche -> mod?


}

void CAbase::call_evolve() {
    for (int i = 1; i<Nx-1; ++i) {
        for(int j = 1; j<Ny-1; ++j) {
            evolve(i,j);
        }
}
    for (int i = 0; i<Nx; ++i) {
        for(int j = 0; j<Ny; ++j) {
            current_status[Nx*i+j] = following_status[Nx*i+j];
        }
    }
}

#endif // CABASE_H_INCLUDED
