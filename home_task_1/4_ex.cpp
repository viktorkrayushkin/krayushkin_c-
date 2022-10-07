#include <iostream>

int main()
{   int a,b;
    std::cout <<"Введите переменную a: \n";
    std::cin >> a;
    std:: cout <<"Введите переменную b: \n";
    std::cin >> b;

    a = a + b;
    b = a - b;
    a = a - b;

std::cout << "Переменная a: "<< a <<"\n";
std::cout << "Переменная b: "<< b <<"\n";
    return 0;
}