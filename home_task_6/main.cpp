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
    a.Input();
    cout<<"Вторая дробь: \n ";
    b.Input();

    cout<<"Первая дробь: \n " ;
    a.Print(); cout <<"\n";
    cout<<"Вторая дробь: \n ";
    b.Print(); cout <<"\n";

    Fraction multiplic = a * b;
    Fraction sum = a + b;
    Fraction reduce = a - 1.0;
    bool t;
    t = a < b;
    double c = 1.0 + double(a);
    double fraction = double(a / b);


    cout<<"Результат умножение первой на вторую дробь: ";
    multiplic.Print(); cout <<"\n";
    cout<<"Сумма первой и второй дроби: ";
    sum.Print(); cout <<"\n";
    cout<<"Уменьшение первой дроби на 1.0 результат в виде дроби: ";
    reduce.Print(); cout <<"\n";
    cout<<"Прибавление к первой дроби 1.0 результат в десятичном виде: ";
    cout << c << endl;
    cout<<"Результат в десятичном виде деления первой дроби на вторую ";
    cout << fraction << endl;
    a.Print(); cout << " < " ; b.Print(); cout <<" : " << booltostr(t);
}