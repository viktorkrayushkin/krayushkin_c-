#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

template <typename T>
void sort_vectort(vector<T>& vec) {
    int size = vec.size();
    for (int i = 0; i < size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (vec[j + 1] >= vec[j])
                break;
            swap(vec[j], vec[j + 1]);
        }
    }
}

template <typename T>
void print_vector(vector<T> vec) {
    int size= vec.size();
    for (int i = 0; i < size; i++)
        cout << " " << setw(4) << vec[i];
    cout << endl;
}

int main() {
    cout << "Введите размер последовательности: ";
    int n;
    cin >> n;
    vector<double> arr(n);

    cout << "Введите элементы последовательности" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Исходный массив: ";
    print_vector(arr);
    sort_vectort(arr);
    cout << "Отсортированный массив:  ";
    print_vector(arr);
    arr.clear();
}