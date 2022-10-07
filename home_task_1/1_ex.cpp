#include <iostream>
#include <string>


int main()
{
    std::string a[6] = { "A", "B", "C", "D", "E", "F"};
    int price,k,t;

    std::string answer,name,cashback,sign;
    std::cout << "Product's name: ";
    std:: cin >> name;
    std::cout <<"Product's price: ";
    std::cin  >> price;
    std::string st = ("");
    std::cout <<"Is cash-back available for this product?(true/false): ";
    std::cin >> cashback;
    std::cout <<"Maximum storing temperature: ";
    std::cin >> t ;
    std::string temperature = ("");
    int ost = 0;
    while (price != 0) {
        ost = price % 16;
        if (ost >= 10) {
            st = (a[ost - 10]) + st;
        }
        else {
            st = std::to_string(ost) + st;
        }
        price = price / 16;
    }

    k = 8-st.length();
    if (st.length() <= 8) {
        for(int j = 0; j < k; j++) {
            st = '0' + st;
        }
    }


    if (t > 0) sign = "+";
    if (t < 0) sign = "-";
    temperature = sign + std::to_string(t);

    std::cout << name << "\n" ;
    std::cout << "Price: " << st << "\n" ;
    std::cout << "Has cash-back: " << cashback << "\n";
    std:: cout << "Max temperature: " << temperature ;

}