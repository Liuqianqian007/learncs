/*************************************************************************
	> File Name: complex.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 04 Mar 2021 07:05:20 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
#include<assert.h>

class Complex{
public:
    Complex() = default;
    Complex(double _real, double _imag);

    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    Complex operator*(const Complex &);
    Complex operator/(const Complex &);

    Complex& operator+=(const Complex &);
    Complex& operator-=(const Complex &);
    Complex& operator*=(const Complex &);
    Complex& operator/=(const Complex &);

    Complex &operator=(const Complex&);
    friend std::ostream &operator<<(std::ostream &, const Complex &);

private:
    double real = 0, imag = 0;
};

Complex::Complex(double _real, double _imag):real(_real), imag(_imag){};

Complex Complex::operator+(const Complex &comp){
    return Complex(real + comp.real, imag + comp.imag);
} 

Complex Complex::operator-(const Complex &comp){
    return Complex(real - comp.real, imag - comp.imag);
}

Complex Complex::operator*(const Complex &comp){
    double _real = real * comp.real - imag * comp.imag;
    double _imag = imag * comp.real + real * comp.imag;
    return Complex(_real, _imag);
}

Complex Complex::operator/(const Complex &comp){
    assert(fabs(comp.real) > 1e-6 || fabs(comp.imag) > 1e-6);
    double divid = comp.real * comp.real + comp.imag * comp.imag;
    double _real = (real * comp.real + imag * comp.imag) / divid;
    double _imag = (imag * comp.real - real * comp.imag) / divid;
    return Complex(_real, _imag);
}

Complex& Complex::operator+=(const Complex & comp){
    return (*this) = (*this) + comp;
}

Complex& Complex::operator-=(const Complex & comp) {
    return (*this) = (*this) - comp;
    
}
Complex& Complex::operator*=(const Complex & comp) {
    return (*this) = (*this) * comp;

}
Complex& Complex::operator/=(const Complex & comp) {
    return (*this) = (*this) / comp;
}

Complex& Complex::operator=(const Complex & comp) {
    real = comp.real;
    imag = comp.imag;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Complex &comp){
    if ((fabs(comp.real) < 1e-6) && (fabs(comp.imag) < 1e-6)) return out << "0";    
    if (fabs(comp.real) < 1e-6) return out << comp.imag << "i";
    if (fabs(comp.imag) < 1e-6) return out << comp.real;
    
    out << "(" << comp.real;

    if (comp.imag > 0) out << " + ";
    else out << " - ";

    if (fabs(fabs(comp.imag) - 1) > 1e-6) out << fabs(comp.imag);

    out << "i)";
    
    return out;
}


int main() {
    double real1, imag1, real2, imag2;
    while(std::cin >> real1 >> imag1 >> real2 >> imag2) {
        Complex comp1(real1, imag1);
        Complex comp2(real2, imag2);

        Complex add = comp1 + comp2;
        Complex sub = comp1 - comp2;
        Complex mul = comp1 * comp2;
        Complex div = comp1 / comp2;

        std::cout << comp1 << " + " << comp2 << " = " << add << std::endl;
        std::cout << add << " - " << comp2 << " = " << (add -= comp2) << std::endl;
        std::cout << std::endl;

        std::cout << comp1 << " - " << comp2 << " = " << sub << std::endl;
        std::cout << sub << " + " << comp2 << " = " << (sub += comp2) << std::endl;
        std::cout << std::endl;

        std::cout << comp1 << " * " << comp2 << " = " << mul << std::endl;
        std::cout << mul << " / " << comp2 << " = " << (mul /= comp2) << std::endl;
        std::cout << std::endl;

        std::cout << comp1 << " / " << comp2 << " = " << div << std::endl;
        std::cout << div << " * " << comp2 << " = " << (div *= comp2) << std::endl;
        std::cout << std::endl;

        std::cout << "----------------" << std::endl;
    }


    return 0;
}
