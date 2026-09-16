#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    vector<vector<double>> data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
        data.assign(rows, vector<double>(cols, 0.0));
    }

    void setValue(int r, int c, double value)
    {
        data[r][c] = value;
    }

    double getValue(int r, int c) const
    {
        return data[r][c];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void print() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix matrix_multiply(const Matrix &other) const
    {
        if (cols != other.rows)
        {
            throw invalid_argument("Columns of the first matrix must match rows of the second matrix");
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                double sum = 0.0;
                for (int k = 0; k < cols; k++)
                {
                    sum += data[i][k] * other.data[k][j];
                }
                result.setValue(i, j, sum);
            }
        }

        return result;
    }
};

int main()
{
    Matrix a(2, 3);
    Matrix b(3, 2);

    int counter = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            a.setValue(i, j, counter++);

    counter = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            b.setValue(i, j, counter++);

    cout << "Matrix A:" << endl;
    a.print();
    cout << "Matrix B:" << endl;
    b.print();

    try
    {
        Matrix c = a.matrix_multiply(b);
        cout << "A x B =" << endl;
        c.print();
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
