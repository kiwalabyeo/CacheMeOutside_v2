#include <iostream>
#include <vector>
using namespace std;

class Dataset
{
private:
    int rows;
    int cols;
    vector<vector<double>> data;

public:
    Dataset(int rows, int cols) : rows(rows), cols(cols)
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

    double columnMean(int col) const
    {
        double sum = 0.0;
        for (int i = 0; i < rows; i++)
        {
            sum += data[i][col];
        }
        return sum / rows;
    }

    vector<vector<double>> covariance_matrix() const
    {
        vector<double> means(cols);
        for (int j = 0; j < cols; j++)
        {
            means[j] = columnMean(j);
        }

        vector<vector<double>> cov(cols, vector<double>(cols, 0.0));

        for (int a = 0; a < cols; a++)
        {
            for (int b = 0; b < cols; b++)
            {
                double sum = 0.0;
                for (int i = 0; i < rows; i++)
                {
                    sum += (data[i][a] - means[a]) * (data[i][b] - means[b]);
                }
                cov[a][b] = sum / (rows - 1);
            }
        }

        return cov;
    }
};

int main()
{
    Dataset d(5, 2);
    double values[5][2] = {
        {2, 10},
        {4, 12},
        {6, 13},
        {8, 15},
        {10, 20}};

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 2; j++)
            d.setValue(i, j, values[i][j]);

    cout << "Dataset:" << endl;
    d.print();

    vector<vector<double>> cov = d.covariance_matrix();

    cout << "Covariance Matrix:" << endl;
    for (int i = 0; i < (int)cov.size(); i++)
    {
        for (int j = 0; j < (int)cov[i].size(); j++)
        {
            cout << cov[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
