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

    double trace() const
    {
        if (rows != cols)
        {
            throw invalid_argument("Trace is only defined for square matrices");
        }

        double sum = 0.0;
        for (int i = 0; i < rows; i++)
        {
            sum += data[i][i];
        }
        return sum;
    }
};

int main()
{
    Matrix m(3, 3);

    int counter = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m.setValue(i, j, counter);
            counter++;
        }
    }

    cout << "Matrix:" << endl;
    m.print();

    try
    {
        double result = m.trace();
        cout << "Trace = " << result << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
