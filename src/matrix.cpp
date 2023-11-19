#include <matrix.hpp>

matrix::matrix(int row, int column)
{
    this->row = row;
    this->column = column;
    this->data.reserve(0);
}
bool matrix::empty()
{
    if (row == 0 || column == 0)
    {
        return true;
    }
    return false;
}

void matrix::print()
{
    cout << "printing matrix:" << endl;
    if (row == 0)
    {
        cout << "Empty matrix";
        return;
    }
    for (auto i : data)
    {
        cout << "| ";
        for (auto j : i)
        {
            printf("%10.2lf ", j);
        }
        cout << "|\n";
    }
}
void matrix::scan()
{
    cout << "rows=" << this->row << endl
         << "column=" << this->column << endl;

    for (int i = 0; i < row; i++)
    {
        cout << "line" << i + 1 << ":\n";
        this->data.push_back(vector<double>{});
        for (int j = 0; j < column; j++)
        {
            double t;
            cin >> t;
            this->data[i].push_back(t);
        }
    }
}
matrix matrix::operator-()
{
    if(empty()){
        cout << ("empty") <<endl;
        exit(0);
    }
    matrix *ret = new matrix(row, column);
    for (int i = 0; i < this->row; i++)
    {
        ret->data.push_back(vector<double>{});
        for (int j = 0; j < this->column; j++)
        {
            ret->data[i].push_back(-this->data[i][j]);
        }
    }
    return *ret;
}
matrix matrix::operator+(const matrix &m)
{
    if (m.row != this->row || m.column != this->column)
    {
        cout << ("bad obj");
        exit(0);
    }
    matrix *ret = new matrix(row, column);
    for (int i = 0; i < this->row; i++)
    {
        ret->data.push_back(vector<double>{});
        for (int j = 0; j < this->column; j++)
        {
            ret->data[i].push_back(this->data[i][j] + m.data[i][j]);
        }
    }
    return *ret;
}
matrix matrix::operator-(matrix m)
{
    return *this+-m;
}
matrix matrix::operator*(const matrix &m)
{
    if (m.row != this->column)
    {
        cout << ("bad obj");
        exit(0);
    }
    matrix *ret = new matrix(this->row, m.column);
    for (int i = 0; i < this->row; i++)
    {
        ret->data.push_back(vector<double>{});
        for (int j = 0; j < m.column; j++)
        {
            int sum = 0;
            for (int k = 0; k < this->column; k++)
            {
                sum += this->data[i][k] * m.data[k][j];
            }
            ret->data[i].push_back(sum);
        }
    }
    return *ret;
}
matrix matrix::operator/(double n)
{
    return matrix::operator*(1 / n);
}
matrix matrix::operator*(double n)
{
    if (empty())
    {
        cout << ("bad obj");
        exit(0);
    }
    matrix *ret = new matrix(row, column);
    for (int i = 0; i < this->row; i++)
    {
        ret->data.push_back(vector<double>{});
        for (int j = 0; j < this->column; j++)
        {
            ret->data[i].push_back(this->data[i][j] * n);
        }
    }
    return *ret;
}
matrix matrix::transpose()
{
    matrix *ret = new matrix(this->column, this->row);
    for (int i = 0; i < column; i++)
    {
        ret->data.push_back(vector<double>{});
        for (int j = 0; j < row; j++)
        {
            ret->data[i].push_back(this->data[j][i]);
        }
    }
    return *ret;
}

std::ostream &operator<<(std::ostream &output, const matrix &m)
{
    if (m.row == 0 || m.column == 0)
    {
        output << "empty matrix" << endl;
        return output;
    }
    else
    {
        output << "printing matrix:" << '\n';
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.column; j++)
            {
                output << m.data[i][j] << ' ';
            }
            output << '\n';
        }
        return output;
    }
}