#include <iostream>
#include <cmath>

int main()
{ float a,b,c,x1,x2,D;
    std::cout <<"Введите коэфициент a, b, c: ";
    std:: cin >> a >> b >> c ;

    D = b*b - 4*a*c;
    if (D > 0) {
        x1 = ((-b) + sqrt(D)) / (2 * a);
        x2 = ((-b) - sqrt(D)) / (2 * a);
        std::cout << "x1 = " << x1 << "\n";
        std::cout << "x2 = " << x2 << "\n";
    }
    if (D == 0){x1 = -(b / (2 * a));
        std::cout << "x1 = x2 = " << x1 << "\n";
    }
    if (D < 0){
        std:: cout << "Решения в действительных значениях уравнения не существует";
    }

    return 0;

}