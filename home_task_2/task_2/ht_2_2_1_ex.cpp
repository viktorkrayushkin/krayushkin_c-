#include <iostream>
using std::cin;
using std::cout;
using std::swap;


void inSort(float b[], int m)
{
    for (int i = 1; i < m; i++)
    {
        int j = i - 1;
        while (j >= 0 && b[j] > b[j + 1])
        {
            swap(b[j], b[j + 1]);
            j--;
        }
    }
}

int main()
{
    int n = 0;
    cout << "Введите длину массива: ";
    cin >> n;
    float* a = new float[n];
    cout << "Введите значения: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    inSort(a, n);

    cout << "\n\nОтсортированный массив методом вставки по возрастанию: \n";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }

    return 0;
}