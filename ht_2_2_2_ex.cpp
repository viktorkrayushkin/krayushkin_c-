#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::swap;
using std::vector;

void inSort(vector <float> &b, int m)
{
    for (int i = 1; i < m; i++)
    {
        int j = i - 1;
        while (j >= 0 && b.at(j) > b.at(j + 1))
        {
            swap(b.at(j), b.at(j + 1));
            j--;
        }
    }
}

int main()
{

    int n = 0;
    cout << "Введите длину массива: ";
    cin >> n;
    vector <float> massiv(n);
    cout << "Введите значения: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> massiv[i];
    }

    inSort(massiv, n);

    cout << "\n\nОтсортированный массив методом вставки по возрастанию: \n";

    for (int i = 0; i < n; i++)
    {
        cout << massiv[i] << "\t";
    }

    return 0;
}