#ifndef UNTITLED6_DOP_H
#define UNTITLED6_DOP_H
#include <iostream>
#include <math.h>
class Figure{
public:
    virtual void Perimeter() = 0;
    virtual void Area() = 0;
    virtual void Figure_info() = 0;
};

class Ellipse: public Figure{
public:
    explicit Ellipse(const double& a, const double& b): a(a), b(b) {}

    virtual void Figure_info() override{
        std::cout << "Ellipse, equation: (x/"
                  << a << ")^2 + (y/" << b <<")^2 = 1" << std::endl;
    }
    virtual void Perimeter() override{
        std::cout << " perimeter: "<< 4 * (3.14 * a * b + a - b)/(a + b) << std::endl;
    }
    virtual void Area() override{
        std::cout << " area: " << 3.14 * a * b << std::endl;
    }
private:
    double a, b;
};

class Circle: public Ellipse{
public:
    explicit Circle(const double& r): r(r), Ellipse(r, r){}

    void Figure_info() final{
        std::cout << "Circle, equation: x^2 + y^2 = 1\n"
                                       " radius: "<< r << std::endl;
    }
    void Perimeter() final{
        std::cout<<" perimeter: "<<2 * 3.14 * r << std::endl;
    }
    void Area() final{
        std::cout << " area: "<<3.14 * r * r <<std::endl;
    }
private:
    double r;
};

class Polygon: public Figure{
public:
    explicit Polygon(const int& n): n(n){}

    virtual void Figure_info() override{
        std::cout << "Polygon: " << n << " sides" <<std::endl;
    }
private:
    int n;
};

class Triangle: public Polygon{
public:
    explicit Triangle(const double& a1, const double& a2, const double& a3
    ): a1(a1),a2(a2),a3(a3), Polygon(3){}

    void Figure_info() final{
        std::cout << "Triangle, sides are equal to "<<
                  a1 << " " << a2 << " " << a3 <<std::endl;
    }
    void Perimeter() final{
        std::cout << " perimeter: " << a1 + a2 + a3 << std::endl;
    }
    void Area() final{
        std::cout<< " area : "<< sqrt((a1+a2+a3)*(a1+a2-a3)*(a1-a2+a3)*(a2+a3-a1))/4 << std::endl;
    }
private:
    double a1, a2, a3;
};

class Quadrangle: public Polygon{
public:
    explicit Quadrangle(const double& a1, const double& a2,
                        const double& a3, const double& a4): a1(a1),a2(a2),a3(a3),a4(a4),
                                                                                      Polygon(4){}
    virtual void Figure_info() override{
        std::cout << "Quadrangle "
                                        " sides are equal to "<< a1 << ", "
                  << a2 << ", " << a3 << ", " << a4 << std::endl;
    }
    virtual void Perimeter() final{
        std::cout << " perimeter : " << a1 + a2 + a3 + a4 << std::endl;
    }
    virtual void Area() final{
        std::cout<<" area: "<< sqrt((-a1+a2+a3+a4)*(a1+a2+a3-a4)*(a1+a2-a3+a4)*(a1-a2+a3+a4))/4 <<std::endl;
    }
protected:
    double a1, a2, a3, a4;
};

class Rectangle: public Quadrangle{
public:
    explicit Rectangle(const double& a1, const double& a2):
            Quadrangle(a1, a2, a1, a2){}
    virtual void Figure_info() final{
        std::cout << "Rectangle"
                                        " sides are equal to "<< a1 << ", " << a2 << std::endl;
    }
};

class Square: public Quadrangle{
public:
    explicit Square(const double& a1): Quadrangle(a1, a1, a1, a1){}
    void Figure_info() final{
        std::cout << "Square, side is equal to " << a1 << std::endl;
    }
};
#endif //UNTITLED6_DOP_H