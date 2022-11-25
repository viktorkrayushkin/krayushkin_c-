#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

const int kDefaultPrecision = 3;

class Complex {
private:
    double _Re_, _Im_;
    double _argument_, _modul_;

    void calcul_polarity(void) {
        _modul_ = sqrt(_Re_ * _Re_ + _Im_ * _Im_);
        if ((_Re_ < 0) and (_Im_ == 0))
            _argument_ = acos(-1);
        else
            _argument_ = 2 * atan(_Im_ / (_modul_ + _Re_));
    }
    void calcul_parts(void) {
        _Re_ = _modul_ * cos(_argument_);
        _Im_ = _modul_ * sin(_argument_);
    }

public:
    Complex(void){
        setting_parts(0, 0);

    };
    Complex(double real, double imaginary) {
        setting_parts(real, imaginary);

    }
    void setting_parts(double real, double imaginary) {
        _Re_ = real;
        _Im_ = imaginary;
        calcul_polarity();
    }
    void setting_polarity(double modulus, double argument) {
        _modul_ = modulus;
        _argument_ = argument;
        calcul_parts();
    }

    double get_Re(void) {
        return _Re_;
    }
    double get_Im(void) {
        return _Im_;
    }
    double get_modul(void) {
        return _modul_;
    }
    double get_argument(void) {
        return _argument_;
    }

    void print_algebr_form(int prec = kDefaultPrecision) {
        if (!_modul_)
            std::cout << 0 <<"\n";
        else
            std::cout << std::setprecision(prec) << _Re_ << " + "<< _Im_ << " * i"<<"\n " ;
    }
    void print_trig_form(int prec = kDefaultPrecision) {
        if (!_modul_)
            std::cout << 0 <<"\n";
        else
            std::cout << std::setprecision(prec) << _modul_ << " * (cos" << _argument_ << " + sin" << _argument_ << ')'<<"\n " ;
    }
    void print_exponent_form(int prec = kDefaultPrecision) {
        if (!_modul_)
            std::cout << 0 <<"\n";
        else
            std::cout << std::setprecision(prec) << _modul_ << " * exp(i*" << _argument_ << ')'<<"\n ";
    }



    Complex addition(double operand) {
        Complex result;
        result.setting_parts(this->get_Re() + operand, _Im_);
        return result;
    }
    Complex addition(Complex operand) {
        Complex result;
        result.setting_parts(this->get_Re() + operand.get_Re(), this->get_Im() + operand.get_Im());
        return result;
    }

    Complex subtraction(double operand) {
        Complex result;
        result.setting_parts(_Re_ - operand, _Im_);
        return result;
    }
    Complex subtraction(Complex operand) {
        Complex result;
        result.setting_parts(_Re_ - operand.get_Re(), _Im_ - operand.get_Im());
        return result;
    }

    Complex multiply(double operand) {
        Complex result;
        result.setting_polarity(_modul_ * operand, _argument_);
        return result;
    }
    Complex multiply(Complex operand) {
        Complex result;
        result.setting_polarity(_modul_ * operand.get_modul(), _argument_ + operand.get_argument());
        return result;
    }

    Complex division(double operand) {
        Complex result;
        result.setting_polarity(_modul_ / operand, _argument_);
        return result;
    }
    Complex division(Complex operand) {
        Complex result;
        result.setting_polarity(_modul_ / operand.get_modul(), _argument_ - operand.get_argument());
        return result;
    }

    Complex conjugate(void) {
        Complex result;
        result.setting_parts(_Re_, -_Im_);
        return result;
    }
    Complex exponentiation(double operand) {
        Complex result;
        result.setting_polarity(pow(_Re_, operand), _argument_ * operand);
        return result;
    }
    Complex Sqrt(void) {
        return exponentiation(0.5);
    }
};

int main() {
    Complex z1;
    Complex z2;
    Complex result;

    double re, im;
    std::cout << "Введите действительную часть комплексного числа z1: ";
    std::cin >> re;
    std::cout << "Введите мнимую часть комплексного числа z1: ";
    std::cin >> im;
    z1.setting_parts(re, im);

    std::cout << "Введите действительную часть комплексного числа z2: ";
    std::cin >> re;
    std::cout << "Введите мнимую часть комплексного числа z2: ";
    std::cin >> im;
    z2.setting_parts(re, im);
    std::cout<<"Введённые комплексные числа: "<<"\n ";
    std::cout << "z1 = ";
    z1.print_exponent_form(7);
    std::cout << "z2 = ";
    z2.print_exponent_form(7);
    std::cout << "\n";

    std::cout<<"Математические операции над введёнными комплексными числами: "<<"\n ";

    result = z1.addition(z2);
    std::cout<<"Сложение: "<<"\n  ";
    std::cout << "z1 + z2 = ";
    result.print_trig_form(7);

    result = z1.subtraction(z2);
    std::cout<<"Вычитание: "<<"\n  ";
    std::cout << "z1 - z2 = ";
    result.print_exponent_form();

    result = z1.multiply(z2);
    std::cout<<"Умножкние: "<<"\n  ";
    std::cout << "z1 * z2 = ";
    result.print_algebr_form();

    result = z1.division(z2);
    std::cout<<"Деление: "<<"\n  ";
    std::cout << "z1 / z2 = ";
    result.print_algebr_form();

    result = z1.exponentiation(2);
    std::cout<<"Возведение в квадрат: "<<"\n  ";
    std::cout << "z1^2 = ";
    result.print_algebr_form();

    result = z2.exponentiation(2);
    std::cout<<"Возведение в квадрат: "<<"\n  ";
    std::cout << "z2^2 = ";
    result.print_algebr_form();

    result = z1.conjugate();
    std::cout<<"Операция сопряжения: "<<"\n  ";
    std::cout << "z1* = ";
    result.print_algebr_form();

    result = z2.conjugate();
    std::cout<<"Операция сопряжения: "<<"\n  ";
    std::cout << "z2* = ";
    result.print_algebr_form();

    result = z1.Sqrt();
    std::cout<<"Взятие корня: "<<"\n  ";
    std::cout << "z1^(1/2) = ";
    result.print_algebr_form();

    result = z2.Sqrt();
    std::cout<<"Взятие корня: "<<"\n  ";
    std::cout << "z2^(1/2) = ";
    result.print_algebr_form();
}