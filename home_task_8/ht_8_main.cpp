#include <iostream>
#include "figures.h"
#include <vector>

int main() {
    Ellipse e(2,5);
    Circle c(4);
    Quadrangle q(3,4,1,2);
    Triangle t(4,5,3);
    Rectangle r(2,6);
    Square s(6);
    std::vector<Figure*> list;
    list.push_back(&e);
    list.push_back(&c);
    list.push_back(&q);
    list.push_back(&t);
    list.push_back(&r);
    list.push_back(&s);
    for (auto& i:list){
        i->Figure_info();
        i->Perimeter();
        i->Area();
        std::cout << "__________________"<<std::endl;
    }
}