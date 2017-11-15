#include <iostream>
#include "CAbase.h"


using namespace std;


int main () {
    CAbase ca;
    ca.set_raster(30,30);
    ca.get_raster();
    ca.set_cell(1,1);
    ca.print();
    evolve(ca.current_status);
    ca.print();
}
