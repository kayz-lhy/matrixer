#include <vector>
#include <iostream>
#include "matrix.hpp"
#include <cstdlib>
using std::cout,std::cin,std::endl,std::vector;

int main(){
    matrix m = *new matrix(2,3);
    m.scan();
    m.print();
    cout<<m;
    auto trans = -m;
    trans.print();

    system("ll");
}

