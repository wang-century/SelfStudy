/**
 * 第五章程序设计题
 */
#include <iostream>
#include <string>
using namespace std;


/**
 * 设计一个几何图形类，并派生若干个具体的几何图形，包括三角形、正方形和圆形。
 * 为各类定义必要的成员变量，添加构造函数、析构函数和成员函数，成员函数包括计算周长、面积和显示图形信息
 */
class Shape{
public:
    double perimeter,area;  // 图形包括周长和面积

    /* 计算周长 */
    virtual double getPerimeter()=0;

    /* 计算面积 */
    virtual double getArea()=0;

    /* 显示图形信息 */
    virtual void showInfo()=0;

};

/** 三角形 */
class Triangle: public Shape{
private:
    double
};

/** 正方形 */
class Square: public Shape{

};

/** 圆形 */
class Circle: public Shape{

};
