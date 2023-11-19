#pragma once

#include <vector>
#include <iostream>

using std::cout, std::cin, std::endl;
using std::vector;

class matrix
{
private:
    int row;
    int column;
    vector<vector<double>> data;

public:
    matrix() = default;
    matrix(int row, int column);

    bool empty();
    void print();
    void scan();
    matrix operator-();
    matrix operator+(const matrix &m);
    matrix operator-(matrix m);
    matrix operator*(const matrix &m);
    matrix operator/(double n);
    matrix operator*(double n);
    matrix transpose();

    friend std::ostream &operator<<(std::ostream &output, const matrix &m);
};
