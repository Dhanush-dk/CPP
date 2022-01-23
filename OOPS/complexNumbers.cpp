#include <iostream>
using namespace std;

class Complex{
private:
    int real;
    int imag;
public:
    Complex(int r, int i){
        real = r;
        imag = i;
    }
    int get_real(){
        return real;
    }
    int get_imag(){
        return imag;
    }
    void add(Complex c2){
        cout << c2.get_real()+real << "+i" << c2.get_imag()+imag << endl;
    }
    void difference(Complex c2){
        cout << real-c2.get_real() << "+i" << imag-c2.get_imag() << endl;
    }
    void multiply(Complex c2){
        cout << ((real*c2.get_real())-(imag*c2.get_imag())) << "+i" << ((real*c2.get_imag())+(imag*c2.get_real())) << endl;
    }
};

int main()
{
    Complex c1(2,4);
    Complex c2(3,5);
    c1.add(c2);
    c1.difference(c2);
    c1.multiply(c2);
    return 0;
}      
