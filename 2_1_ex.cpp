#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int n, m;
    cout << "Введите колличество уравнений: ";
    cin >> n;
    cout << "Введи сколько у Вас неизвестных: ";
    cin >> m;
    m=m+1;
    float **matrix = new float *[n];
    for (int i=0; i<n; i++)
        matrix[i] = new float [m];

    for (int i = 0; i<n; i++)

        for (int j = 0; j < m; j++)
        {
            cout << "Введите элемент " << "[" << i + 1 << " , " << j + 1 << "]: ";
            cin >> matrix[i][j];
        }

    cout << "Матрица: \n ";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout << matrix[i][j] << "  ";
            cout << "\n " ;
    }
    cout <<" \n ";

    for (int i=0; i<n; i++)
    {
        float element = matrix[i][i];
        for (int j=n; j>=i; j--)
            matrix[i][j] /= element;
        for (int j=i+1; j<n; j++)
        {
            element=matrix[j][i];
            for (int k=n; k>=i; k--)
                matrix[j][k]-= element * matrix[i][k];
        }
    }
    float  matrix_remainder[m];
    matrix_remainder[n-1] = matrix[n-1][n];
    for ( int i=n-2; i>=0; i--)
    {
        matrix_remainder[i] = matrix[i][n];
        for (int j=i+1; j<n; j++)  matrix_remainder[i]-=matrix[i][j]* matrix_remainder[j];
    }
    cout <<"Решение системы уравнеий: \n ";
    for (int i=0; i<n; i++)
        cout << i+1 <<"-ая неизвестная = " << matrix_remainder[i] << " ; \n ";

    delete[] matrix;

    return 0;

}
