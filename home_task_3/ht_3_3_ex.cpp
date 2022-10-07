#include <iostream>
#include <iomanip>
#include <algorithm>

void arr_print(int* array, int size);

int main() {
    int n;
    std::cout << "Введите размер массива: \n";
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Введите элементы массива: \n";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::cout << "Чтобы отсортировать массива по возрастанию введите знак: ' > '  , если по убыванию, то знак ' < '  : \n";
    char ch;
    std::cin >> ch;
    bool is_decrease = (ch == '<');

    std::cout << "Неотсортированный массив: \n";
    arr_print(arr, n);

    std::cout << "Массив отортированный по " << (is_decrease ? "убыванию:\n" : "возрастанию:\n");
    std::sort(arr, arr + n, [is_decrease](int a, int b) { return(is_decrease ? a > b : a < b); });
    arr_print(arr, n);
    std::cout << "\n";
}

void arr_print(int* array, int size) {
    for (int i = 0; i < size; i++)
        std::cout << std::setfill(' ') << std::setw(10) << array[i];
    std::cout <<"\n";
}