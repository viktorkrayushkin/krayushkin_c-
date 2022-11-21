#include <iostream>

struct DateTime
{
    unsigned int Day : 5;
    unsigned int Month : 4;
    unsigned int Year : 17;
    unsigned short Hour : 5;
    unsigned short Minute : 6;
    unsigned short Second : 6;
};

int main()
{
    DateTime d;
    int i;

    std::cout << "Введите день (1-31):" << '\t';
    std::cin >> i; d.Day = i;

    std::cout << "Введите месяц (1-12):" << '\t';
    std::cin >> i; d.Month = i;

    std::cout << "Введите год (0-3000) :" << '\t';
    std::cin >> i; d.Year = i;


    std::cout << "\n" << "Введите разряд часов времени (0-24):" << '\t';
    std::cin >> i; d.Hour = i;

    std::cout << "Введите разряд минут времени (0-60):" << '\t';
    std::cin >> i; d.Minute = i;

    std::cout << "Введите разряд секунд времени (0-60):" << '\t';
    std::cin >> i; d.Second = i;


    std::cout << "\n" << "Дата: " << d.Day << "." << d.Month << "."<< d.Year << " \n";
    std::cout << "Время: "<< d.Hour << ":" << d.Minute << ":" << d.Second << "\n";
    std::cout << sizeof(d) << "\n";
}