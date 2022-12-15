#include "heap.h"
#include <iostream>

using namespace std;

int main() {
    cout << "  Куча с целыми значениями  " << endl;
    Heap<int> heap_int = {75, 33, -6, 28, -88, 10, -11 };
    cout << "Начальный максимальный элемент: " << heap_int.ExtractMax() << endl;
    cout << "Номер позиции элемента с значением 33 : " << heap_int.Add(33) << endl;
    cout << "Максимальный элемент: " << heap_int.ExtractMax() << endl;
    cout << "Размер кучи: " << heap_int.GetSize() << endl;

    cout << endl;

    cout << "  Куча с значениями с плавающей запятой " << endl;
    Heap<double> heap_double = {40.75, -27.33, 74.6, 36.28, -58, 81.10, -33 };
    cout << "Начальный максимальный элемент: " << heap_double.ExtractMax() << endl;
    cout << "Номер позиции элемента с значением  10: " << heap_double.Add(10) << endl;
    cout << "Максимальный элемент: " << heap_double.GetMax() << endl;
    cout << "Размер кучи: " << heap_double.GetSize() << endl;
}