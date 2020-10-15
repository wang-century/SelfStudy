/**
 * 第九章程序设计题
 */
#include <iostream>
#include <string>

using namespace std;

/**
 * 编写一个函数模板，返回两个数中的最大值
 */
template <class T>
T max(T &number1,T &number2){
    return number1>number2?number1:number2;
}

