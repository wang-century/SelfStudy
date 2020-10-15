/**
 * 第八章程序设计题
 */
#include <iostream>
#include <string>

using namespace std;

/**
 * 输入三角形的3条边，判断是否合理，不合理给出信息并要求重新输入，合理计算面积并将结果存入文件
 */
#include <cmath>
#include <fstream>

void demo1() {
    double a, b, c;
    int area;
    cout << "请输入三条边的变长:";
    cin >> a >> b >> c;
    // 合理的条件
    if (a + b > c && a + c > b && b + c > a) {
        cout << "三条边可以组成三角形" << endl;
        freopen("triangle_area.txt", "w", stdout);
        // 计算三角形半周长 small_s
        double small_s = (a + b + c) / double(2);
        // 通过半周长计算面积
        area = sqrt(small_s * (small_s - a) * (small_s - b) * (small_s - c));
        cout << "三角形三边长:" << a << "," << b << "," << c << "  面积:" << area << endl;
    } else {
        cout << "三条边不能组成三角形!" << endl;
    }

}

/**
 * 打开指定的文本文件，在每行前面加上行号后再输出到另一个文本文件中
 */
void demo2() {
    fstream src_file, dest_file;
    src_file.open("triangle_area.txt", ios::in);
    dest_file.open("copy_triangle_area.txt", ios::out);
    char str_line[50];
    int count = 1;
    while (src_file.getline(str_line, 50)) {
        dest_file << count << " " << str_line << endl;
        count++;
    }
}

/**
 * 读入一个源程序文件，删除全部注释内容，产生新的源程序文件
 */
void demo3() {
    string line;
    char ch;
    // 读取源程序文件
    ifstream in_file("chapter1.hpp", ios::in);
    freopen("copy_chapter1.hpp","w",stdout);
    //freopen("copy_chapter1.hpp","w",stdout);
    // 遍历文件内容，遇到 "//" 和 "/* */" 删除
    while (in_file.get(ch)) {
        if (ch == '/') {
            in_file.get(ch);
            if (ch == '/') {
                while (in_file.get(ch)) {
                    if (ch == '\n') {
                        break;
                    }
                }
            } else if (ch == '*') {
                while (in_file.get(ch)) {
                    if (ch == '*') {
                        in_file.get(ch);
                        if (ch == '/') {
                            in_file.get(ch);
                            break;
                        }
                    }
                }
            } else {
                cout << '/';
            }
        }
        cout << ch;
    }
    in_file.close();
}

/**
 * 有两个文本文件data.txt和data2.txt，每个文件中包含若干个整数，请编写程序，将两个文件合并成一个按升序排列的新文件res_data.txt
 */
#include <vector>
#include <algorithm>

int MyCompare(int &a,int &b){
    return a<b;
}
void demo4() {
    // 读取两个文件并将数据保存到vector容器
    vector<int>numberAry;
    ifstream is1("data.txt",ios::in);
    ifstream is2("data2.txt",ios::in);
    int number;
    while (is1>>number){
        numberAry.push_back(number);
    }
    while (is2>>number){
        numberAry.push_back(number);
    }
    is1.close();
    is2.close();
    // 对vector中数据进行排序并写入文件
    freopen("res_data.txt","w",stdout);
    sort(numberAry.begin(),numberAry.end(),MyCompare);
    for(vector<int>::iterator it=numberAry.begin();it!=numberAry.end();it++){
        cout << *it << endl;
    }
}