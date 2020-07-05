/*
 * @Description: C++四种cast转换
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-25 14:10:00
 * @LastEditors: szq
 * @LastEditTime: 2020-06-25 15:07:54
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\C++Language\cast.cpp
 */ 


#include<iostream>
using namespace std;


void testConst_cast(){

    char c = 'c';
    const char *pc = &c;//如果没有初始化，则后面会报错，使用了未被定义的变量pc
    //常量指针转换为普通指针
    char *p = const_cast<char*>(pc);
    
    *p = 'a';
    cout << *pc << endl;
}

void testStatic_cast(){
    int a = 10;

    //隐式转换
    double a_d = static_cast<double>(a);
    cout << a_d / 3 << endl;
}
int main(){
    //测试const_cast，将const对象转换为非const对象
    testConst_cast();

    //测试static_cast，将int类型转换为double
    testStatic_cast();
}