#include <iostream>
#include <cmath>

using namespace std;

float B[3][3], C[3];

float determinant(float mat[][3])
{

    float val = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]) - mat[0][1] * (mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]);
    return val;
}

float swap_col(float mat[][3], float c[], int col)
{
    float n[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            n[i][j] = mat[i][j];
        }
        n[i][col] = c[i];
    }

    return determinant(n);
}

int main()
{
    
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    float x[n], y[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float val[] = {1, x[j], x[j] * x[j]};
            C[i] += y[j] * val[i];
            B[i][0] += val[i];
            B[i][1] += x[j] * val[i];
            B[i][2] += x[j] * x[j] * val[i];
        }
    }

    float D, D1, D2, D3;

    D = determinant(B);
    D1 = swap_col(B, C, 0);
    D2 = swap_col(B, C, 1);
    D3 = swap_col(B, C, 2);

    cout << "A: " << D1 / D << "\t";
    cout << "B: " << D2 / D << "\t";
    cout << "C: " << D3 / D << "\n";

    cout << "Y = " << D1 / D << " + " << D2 / D << "x + " << D3 / D << "x^2";

    return 0;
}
