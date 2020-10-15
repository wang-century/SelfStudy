/**
 * 第七章程序设计题
 */
#include <iostream>
#include <string>

using namespace std;

/**
 * 利用流格式控制，从键盘输入成绩和名字，然后进行输出，要求名字左对齐，分数右对齐
 */
void demo1() {
    double score;
    string name;
    cout << "请输入成绩和姓名(空格分隔):";
    cin >> name >> score;
    // 输出 名字左对齐，分数右对齐
    cout << left << name << " " << right << score << endl;
}

/**
 * 编写程序，读取一行文字，将此行文字颠倒顺序后输出
 */
void demo2() {
    char str_line[20];
    cout << "请输入一行内容:";
    cin.getline(str_line, 20);
    for (int i = 20; i >= 0; --i) {
        cout << str_line[i];
    }
}

/**
 * 输入若干个实数，将每个实数分别以非科学计数法、小数点后保留5位有效数字、科学计数法、小数点后保留7位有效数字输出，输入按ctrl+z组合键结束
 */
#include <iomanip>
#include <cstdio>

void demo3() {
    double number = 0;
    cout << "请输入实数:";
    while (number != EOF) {
        cin >> number;
        cout << fixed << number << " " << setprecision(5) << number << " " << scientific << number << " "
             << setprecision(7) << number << endl;
    }
}


/**
 * 编写程序，输入若干个整数，对于每个整数分别以16进制、8进制输出，然后再以10个字符串宽度输出，宽度不足时在左边补0
 */
void demo4() {
    int number;
    while (cin >> number) {
        cout << hex << setw(10) << setfill('0') << right << number << " " << oct << setw(10) << number << " " << endl;
    }
}

/**
 * 通过设置标准输入重定向，对文件data.txt中保存的全部整数求平均值，文件data.txt中每一行保存一个整数，最后显示文件中保存的整数个数和计算结果
 */
void demo5() {
    int number;
    int count = 0;
    int sum = 0;
    freopen("data.txt", "r", stdin);
    while (cin >> number) {
        cout << number << " ";
        count++;
    }
    cout << "文件保存的整数个数:" << count << "  平均值:" << sum / count << endl;
}

/**
 * 编写程序，将美国格式的日期 May 28 2019转换为国际日期格式 28 May 2019
 */
void demo6() {
    string date = "May 28 2019";
    string day, month, year;
    // 转换
    int index1, index2;

    index1 = date.find(' ');
    string sub_date = date.substr(index1 + 1, date.length());
    index2 = sub_date.find(' ');
    month = date.substr(0, index1);
    day = sub_date.substr(0, index2);
    year = sub_date.substr(index2 + 1, sub_date.length());

    // 输出
    string new_date = day + " " + month + " " + year;
    cout << new_date << endl;
}