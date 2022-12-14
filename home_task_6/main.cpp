#include "frac.h"
#include <iostream>

using namespace std;

string booltostr(bool a){
    if (a == 0)
    {
        cout<<"Неравенство не верно \n";
    }
    else
    {
        cout<<"Неравнство верно \n";
    }
}

int main() {
    Fraction a, b;
    cout<<"Первая дробь: \n ";
    cin >> a;
    cout<<"Вторая дробь: \n ";
    cin >> b;

    cout<<"Первая дробь: \n " ;
    cout << a <<"\n";
    cout<<"Вторая дробь: \n ";
    cout <<b<<"\n";

    Fraction multiplic = a * b;
    Fraction sum = a + b;
    Fraction reduce = a - 1.0;
    bool t;
    t = a < b;
    double c = 1.0 + double(a);
    double fraction = double(a / b);

    cout<<"Результат умножение первой на вторую дробь: ";
    cout << multiplic <<"\n";
    cout<<"Сумма первой и второй дроби: ";
    cout << sum <<"\n";
    cout<<"Уменьшение первой дроби на 1.0 результат в виде дроби: ";
    cout << reduce <<"\n";
    cout<<"Прибавление к первой дроби 1.0 результат в десятичном виде: ";
    cout << c << endl;
    cout<<"Результат в десятичном виде деления первой дроби на вторую ";
    cout << fraction << endl;
    cout <<a<< " < "<< b <<" : " << booltostr(t);
}
