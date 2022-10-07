#include <iostream>
#include <stdlib.h> // программа по бинарному поиску в известном массиве

using std::cin;
using std::cout;
using std::qsort;

int comp1(const void * x1, const void * x2)
{
    float fl_x1 = *(const float*) x1;
    float fl_x2 = *(const float*) x2;
    return (fl_x1 > fl_x2) - (fl_x1 < fl_x2);
}

int main()
{
    float a[]={1,2,32,32,323,4,1.0333,3459,5345.45433,35,55353,1.333};
    int n = sizeof(a)/sizeof(*a);
    qsort(a, n, sizeof(float),comp1);

    float unknown_number;
    cout << "Введите искомое число: ";
    cin >> unknown_number;

    int left_limit = 0;
    int right_limit = n-1;
    bool flag = false;
    int middle;


    while ((left_limit <= right_limit) && (flag != true)) {
        middle = (left_limit + right_limit) / 2;

        if (a[middle] == unknown_number) flag = true;
        if (a[middle] > unknown_number) right_limit = middle - 1;
        else left_limit = middle + 1;
    }

    if (flag) cout << "Такое число есть в массиве";
    else cout << "Такого числа в массиве нет";

    return 0;
}