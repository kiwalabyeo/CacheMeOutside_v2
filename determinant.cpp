#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
private:
    int size;
    vector<vector<double>> data;

public:
    Matrix(int size) : size(size)
    {
        data.assign(size, vector<double>(size, 0.0));
    }

    void setValue(int r, int c, double value)
    {
        data[r][c] = value;
    }

    double getValue(int r, int c) const
    {
        return data[r][c];
    }

    int getSize() const { return size; }

    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix minor(int excludeRow, int excludeCol) const
    {
        Matrix result(size - 1);
        int r = 0;
        for (int i = 0; i < size; i++)
        {
            if (i == excludeRow)
                continue;

            int c = 0;
            for (int j = 0; j < size; j++)
            {
                if (j == excludeCol)
                    continue;

                result.setValue(r, c, data[i][j]);
                c++;
            }
            r++;
        }
        return result;
    }

    double determinant() const
    {
        if (size == 1)
        {
            return data[0][0];
        }

        if (size == 2)
        {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }

        double result = 0.0;
        int sign = 1;
        for (int j = 0; j < size; j++)
        {
            Matrix sub = minor(0, j);
            result += sign * data[0][j] * sub.determinant();
            sign = -sign;
        }
        return result;
    }
};

int main()
{
    Matrix m(3);
    double values[3][3] = {
        {6, 1, 1},
        {4, -2, 5},
        {2, 8, 7}};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m.setValue(i, j, values[i][j]);

    cout << "Matrix:" << endl;
    m.print();

    cout << "Determinant = " << m.determinant() << endl;

    return 0;
}
