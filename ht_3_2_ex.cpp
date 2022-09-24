#include <iostream>
using std::cout;
using std::cin;


void fusing(float *a, int begin, int end, int n) {
    int middle_number, left, right;
    float *massive = new float[n];
    middle_number = (begin + end) / 2;
    left = begin;
    right = middle_number + 1;

    for (int j = begin; j <= end; j++)
        if ((left <= middle_number) && ((right > end) || (a[left] < a[right]))) {
            massive[j] = a[left];
            left++;}
        else{
            massive[j] = a[right];
            right++;
        }
    for (int j = begin; j <= end; j++)
        a[j] = massive[j];
    delete[] massive;
}

void recursive_sort(float *a, int begin, int end, int n) {
    if (begin < end) {
        recursive_sort(a, begin, (begin + end) / 2, n);
        recursive_sort(a, (begin + end) / 2 + 1, end, n);
        fusing(a, begin, end, n);
    }
}

 int main() {
    int n = 0;
    cout << "Введите длину массива: ";
    cin >> n;
    float *a = new float[n];

    for (int i = 0; i < n; i++)
    {cout << "Введите значение " << i <<"-го элемента массива: \n";
        cin >> a[i];
    }

    recursive_sort(a, 1, n, n);
    cout << "упорядоченный массив: ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    delete[] a;
}
