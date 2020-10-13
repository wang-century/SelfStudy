#ifndef SELFSTUDY_CHAPTER1_HPP
#define SELFSTUDY_CHAPTER1_HPP
/**
 * 第一章程序设计题
 */
#include <iostream>
#include <string>
using namespace std;

/**
 * 编写一个程序，将从键盘输入的n个字符串保存在一个一维数组A中，在输入字符串之前先输入n的值。要求数组A需要动态申请空间，程序运行结束前再释放掉
 */
void chapter1_question1(){
    // 输入n
    int n;
    cout << "请输入n的值:";
    cin >> n;
    // 动态申请数组A
    string * str_ary = new string[n];
    // 输入字符串
    string *p = str_ary;
    for (int i = 0; i < n; ++i,p++) {
        cout << "请输入字符串(第" << i+1 << "行,共" << n << "行):";
        cin >> *p;
    }
    // 打印结果
    cout << "字符串输入结果:" << endl;
    p = str_ary;
    for (int i = 0; i < n; p++) {
        cout << *p << endl;
    }

    // 释放空间
    delete [] str_ary;
}


/**
 * 在题目1的基础上，输出n个字符串中最长和最短的串，计算n个串的平均长度并输出结果
 */
void chapter1_question2(){
    // 输入n
    int n;
    cout << "请输入n的值:";
    cin >> n;
    // 动态申请数组A
    string * str_ary = new string[n];
    // 输入字符串
    int total_string_count = 0;
    string *max_length_string = NULL,*min_length_string = NULL;
    string *p = str_ary;
    for (int i = 0; i < n; ++i,p++) {
        cout << "请输入字符串(第" << i+1 << "行,共" << n << "行):";
        cin >> *p;
        total_string_count+=p->length();
        if (i==0){
            max_length_string = p;
            min_length_string = p;
        } else{
            if (p->length() > max_length_string->length()){
                max_length_string = p;
            }
            if (p->length() < min_length_string->length()){
                min_length_string = p;
            }
        }
    }
    // 打印结果
    cout << "字符串输入结果:" << endl;
    p = str_ary;
    for (int i = 0; i < n; i++,p++) {
        cout << *p << endl;
    }
    cout << "最长的串:" << *max_length_string << endl;
    cout << "最短的串:" << *min_length_string << endl;
    cout << "平均长度:" << (double)total_string_count/n << endl;
    // 释放空间
    delete [] str_ary;
}

void chapter1_main(){
    chapter1_question2();
}


#endif //SELFSTUDY_CHAPTER1_HPP
