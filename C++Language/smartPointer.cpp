/*
 * @Description: 智能指针
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-07-05 10:22:27
 * @LastEditors: szq
 * @LastEditTime: 2020-07-05 11:14:09
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\C++Language\smartPointer.cpp
 */ 
#include<iostream>
#include<memory>//智能指针需要添加memory头文件
using namespace std;

/**
 * @destription: 测试unique_ptr智能指针
 * @param {type} 
 * @return: 没有返回值
 */
void test_unique_ptr(){
    cout << "---------------------------测试unique_ptr智能指针------------------------------" << endl;
    unique_ptr<string> a(new string("hello world!"));
    // unique_ptr<int> b = a;会报错，编译器认为是非法的，因为b剥夺了a的所有权，避免了a不再指向有效数据的问题
    unique_ptr<string> b = unique_ptr<string>(new string("hello world!"));//不会报错，因为右边的unique指针只是一个临时变量，在赋值
                                                        //结束后就销毁了

    cout << (*a).c_str() << endl;
    cout << (*b).c_str() << endl;

    
    //使用move函数
    unique_ptr<string> c;
    c = move(a);//move函数是将对象所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝
                //所以可以提高利用效率，改善性能，可以避免不必要的拷贝操作
    cout << "使用move函数后，c指针内容为：" << (*c).c_str() << endl;
    // cout << "使用move函数后，a指针内容为：" << (*a).c_str() << endl;//不能再访问a指针了

}

void test_shared_ptr(){
    cout << "---------------------------测试shared_ptr智能指针------------------------------" << endl;
    shared_ptr<int> a(new int(10));
    shared_ptr<int> b(new int(20));
    shared_ptr<int> c = a;
    shared_ptr<int> d = b;
    shared_ptr<int> e = d;


    //查看对象的引用计数
    cout << "智能指针a的引用计数为：" << a.use_count() << endl;
    cout << "智能指针b的引用计数为：" << b.use_count() << endl;

    //查看指针是否独占所有权
    cout << "智能指针c是否独占对象所有权？" << c.unique() << endl;
    cout << "智能指针e是否独占对象所有权？" << e.unique() << endl;
    
    //交换c、e指针的对象
    cout << "交换前：" << endl;
    cout << "智能指针c的值为：" << *c << endl;
    cout << "智能指针e的值为：" << *e << endl;
    swap(c,e);
    cout << "交换后：" << endl;
    cout << "智能指针c的值为：" << *c << endl;
    cout << "智能指针e的值为：" << *e << endl;

    //reset函数放弃内部对象的所有权，会引起原有对象的引用计数减少
    c.reset();
    cout << "reset后智能指针a的引用计数为：" << a.use_count() << endl;

}
int main(){
    //测试unique智能指针
    test_unique_ptr();

    //测试shared智能指针
    test_shared_ptr();
}