#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;

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
    friend ostream &operator<<(ostream &, const Complex &);

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

ostream& operator<<(ostream &out, const Complex &comp){
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
    while(cin >> real1 >> imag1 >> real2 >> imag2) {
        Complex comp1(real1, imag1);
        Complex comp2(real2, imag2);

        Complex add = comp1 + comp2;
        Complex sub = comp1 - comp2;
        Complex mul = comp1 * comp2;
        Complex div = comp1 / comp2;

        cout << comp1 << " + " << comp2 << " = " << add << endl;
        cout << add << " - " << comp2 << " = " << (add -= comp2) << endl;
        cout << endl;
        cout << comp1 << " - " << comp2 << " = " << sub << endl;
        cout << sub << " + " << comp2 << " = " << (sub += comp2) << endl;
        cout << endl;
        cout << comp1 << " * " << comp2 << " = " << mul << endl;
        cout << mul << " / " << comp2 << " = " << (mul /= comp2) << endl;
        cout << endl;
        cout << comp1 << " / " << comp2 << " = " << div << endl;
        cout << div << " * " << comp2 << " = " << (div *= comp2) << endl;
        cout << endl;
        
        cout << "----------------" << endl;
    }

    return 0;
}