#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");

    float value_si, value_sgse;
    std::string choice;

    const float c_f = pow(10, 5);
    const float c_e = pow(10, 7);
    const float c_q = 3 * pow(10, 9);

    std::cout << "Введите значение в СИ: ";
    std::cin >> value_si;

    std::cout << "Напишите название величины(E, F or q): ";
    std::cin >> choice;

    if (choice == "F") {
        value_sgse = value_si * c_f;
    }

    else if (choice == "E") {
        value_sgse = value_si * c_e;
    }

    else if (choice == "q") {
        value_sgse = value_si * c_q;
    }

    std::cout << "Значение в СГСЭ: " << value_sgse;

    return 0;
}