/**
 * 第三章程序设计题
 */
#include <iostream>
#include <string>
using namespace std;

class MyComplex{
private:
    double real,imag;
public:
    MyComplex():real(0),imag(0){}
    MyComplex(double srcReal,double srcImag){
        real = srcReal;
        imag = srcImag;
    }

    /* 重载加法运算符 */
    friend MyComplex operator+(MyComplex &myComplex1,MyComplex &myComplex2);
    /* 重载减法运算符 */
    friend MyComplex operator-(MyComplex &myComplex1,MyComplex &myComplex2);
    /* 重载乘法运算符 */
    friend MyComplex operator*(MyComplex &myComplex1,MyComplex &myComplex2);

    /* 重载输出流 */
    friend ostream & operator<<(ostream &os,MyComplex &myComplex);






};


ostream & operator<<(ostream &os,MyComplex &myComplex){
    if (myComplex.imag>0){
        os << myComplex.real << "+" << myComplex.imag << "i";
    } else{
        os << myComplex.real << myComplex.imag << "i";
    }
    return os;
}

MyComplex operator+(MyComplex &myComplex1,MyComplex &myComplex2){
    double real = myComplex1.real + myComplex2.real;
    double imag = myComplex1.imag + myComplex2.imag;
    return MyComplex(real,imag);
}

MyComplex operator-(MyComplex &myComplex1,MyComplex &myComplex2){
    double real = myComplex1.real - myComplex2.real;
    double imag = myComplex1.imag - myComplex2.imag;
    return MyComplex(real,imag);
}

MyComplex operator*(MyComplex &myComplex1,MyComplex &myComplex2){
    double real = (myComplex1.real*myComplex2.real)-(myComplex1.imag*myComplex2.imag);
    double imag = (myComplex1.real*myComplex2.imag)+(myComplex1.imag*myComplex2.real);
    return MyComplex(real,imag);
}



#include "chapter2.hpp"

void chapter3_main(){
    // 测试自定义复数类
    MyComplex complex1(1,2),complex2(3,4);
    MyComplex complex3 = complex1+complex2;
    MyComplex complex4 = complex1-complex2;
    MyComplex complex5(2,1);
    MyComplex complex6 = complex1*complex5;
            cout << complex3 << endl;
    cout << complex4 << endl;
    cout << complex6 << endl;
    // 测试重载流插入提取
    Point point;
    cout << "请输入坐标(x y):";
    cin >> point;
    cout << point;
}
