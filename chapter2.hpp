#ifndef SELFSTUDY_CHAPTER2_HPP
#define SELFSTUDY_CHAPTER2_HPP
#include <iostream>
using namespace std;
/**
 * 第二章程序设计题
 */
class MyLine;

/**
 * 定义日期类
 */
class MyDate{
private:
    int year,month,day;
public:
    MyDate();
    MyDate(int,int,int);
    void setDate(int,int,int);
    void setDate(MyDate &);
    MyDate getDate();
    void setYear(int);
    int getMonth() const;
    void printDate() const;
};
MyDate::MyDate() {
    year = 1970;
    month = 1;
    day = 1;
}
MyDate::MyDate(int srcYear,int srcMonth,int srcDay) {
    year = srcYear;
    month = srcMonth;
    day = srcDay;
}
void MyDate::setDate(int srcYear,int srcMonth,int srcDay) {
    year = srcYear;
    month = srcMonth;
    day = srcDay;
}
void MyDate::setDate(MyDate &srcDate) {
    year = srcDate.year;
    month = srcDate.month;
    day = srcDate.day;
}
MyDate MyDate::getDate() {
    return *this;
}
void MyDate::setYear(int srcYear) {
    year = srcYear;
}
int MyDate::getMonth() const{
    return month;
}
void MyDate::printDate() const{
    cout << "日期:" << year <<"年, "<< month << "月, " << day << "日" << endl;
}

/**
 * 设计并实现二维坐标系下的点类Point，类的每个对象含有横纵坐标。
 * 为类添加必要的计算函数，如：计算给定点到(0,0)的距离，计算给定两点间的距离，
 * 判断给定的3个点是否能组成一个三角形
 */
#include <cmath>
class Point{
private:
    double x,y;     // 横纵坐标
public:
    Point():x(0),y(0){}
    Point(double srcX,double srcY){
        x = srcX;
        y = srcY;
    }
    Point(Point &point){
        x = point.x;
        y = point.y;
    }
    /* 计算点到(0,0)的距离 */
    double point_to_original_distance() const{
        return sqrt(pow(y,2)+pow(x,2));
    }

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    friend double p_p_distance(Point &point1,Point &point2);
    friend bool compositionTriangle(Point &point1,Point &point2,Point &point3);
    friend class MyLine;
    friend double point_to_line_distance(Point &point,MyLine &myLine);
};

/**
 * 计算两点间的距离
 * @param point1 点1
 * @param point2 点2
 * @return 两点间距离
 */
double p_p_distance(Point &point1,Point &point2){
    return sqrt(pow((point1.x-point2.x),2)+pow((point1.y-point2.y),2));
}


/**
 * 给定三点能否组成三角形
 * 条件:两边之和大于第三边
 * @param point1 点1
 * @param point2 点2
 * @param point3 点3
 * @return true或false
 */
bool compositionTriangle(Point &point1,Point &point2,Point &point3){
    // 计算每两点之间距离
    double a,b,c;
    a = p_p_distance(point1,point2);
    b = p_p_distance(point1,point3);
    c = p_p_distance(point2,point3);
    // 判断
    if (a+b>c && a+c>b && b+c>a){
        return true;
    } else{
        return false;
    }
}

double Point::getX() const {
    return x;
}

void Point::setX(double x) {
    Point::x = x;
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    Point::y = y;
}


/**
 * 设计并实现一个类MyLine，它表示直线，定义一些基本计算函数
 * 例如：求直线的斜率，判别给定点是否在线上，计算给定点到给定直线的距离
 */
class MyLine{
private:
    double a,b,c;   // 直线的属性为 ax + by + c = 0
public:
    MyLine():a(0),b(0),c(0){}
    MyLine(double srcA,double srcB,double srcC){
        a = srcA;
        b = srcB;
        c = srcC;
    }
    void set(double srcA,double srcB,double srcC){
        a = srcA;
        b = srcB;
        c = srcC;
    }
    /* 求直线斜率 */
    double getSlope() const{
        return -a/b;
    }
    /* 点在线上 */
    bool pointInLine(Point &point) const{
        if ((a*point.x + b*point.y + c) == 0){
            return true;
        }else{
            return false;
        }
    }
    friend double point_to_line_distance(Point &point,MyLine &myLine);

};

/**
 * 求点到直线的距离
 * @param point 点
 * @param myLine 直线
 * @return 距离
 */
double point_to_line_distance(Point &point,MyLine &myLine){
    double distance = (myLine.a * point.x + myLine.b * point.y + myLine.c)/sqrt(pow(myLine.a,2)+pow(myLine.b,2));
    if (distance>=0){
        return distance;
    }else{
        return -distance;
    }
}

#endif //SELFSTUDY_CHAPTER2_HPP
