/*
 * @Description: ����ָ��
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-07-05 10:22:27
 * @LastEditors: szq
 * @LastEditTime: 2020-07-05 11:14:09
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\C++Language\smartPointer.cpp
 */ 
#include<iostream>
#include<memory>//����ָ����Ҫ���memoryͷ�ļ�
using namespace std;

/**
 * @destription: ����unique_ptr����ָ��
 * @param {type} 
 * @return: û�з���ֵ
 */
void test_unique_ptr(){
    cout << "---------------------------����unique_ptr����ָ��------------------------------" << endl;
    unique_ptr<string> a(new string("hello world!"));
    // unique_ptr<int> b = a;�ᱨ����������Ϊ�ǷǷ��ģ���Ϊb������a������Ȩ��������a����ָ����Ч���ݵ�����
    unique_ptr<string> b = unique_ptr<string>(new string("hello world!"));//���ᱨ����Ϊ�ұߵ�uniqueָ��ֻ��һ����ʱ�������ڸ�ֵ
                                                        //�������������

    cout << (*a).c_str() << endl;
    cout << (*b).c_str() << endl;

    
    //ʹ��move����
    unique_ptr<string> c;
    c = move(a);//move�����ǽ���������Ȩ��һ������ת�Ƶ���һ������ֻ��ת�ƣ�û���ڴ�İ�Ǩ�����ڴ濽��
                //���Կ����������Ч�ʣ��������ܣ����Ա��ⲻ��Ҫ�Ŀ�������
    cout << "ʹ��move������cָ������Ϊ��" << (*c).c_str() << endl;
    // cout << "ʹ��move������aָ������Ϊ��" << (*a).c_str() << endl;//�����ٷ���aָ����

}

void test_shared_ptr(){
    cout << "---------------------------����shared_ptr����ָ��------------------------------" << endl;
    shared_ptr<int> a(new int(10));
    shared_ptr<int> b(new int(20));
    shared_ptr<int> c = a;
    shared_ptr<int> d = b;
    shared_ptr<int> e = d;


    //�鿴��������ü���
    cout << "����ָ��a�����ü���Ϊ��" << a.use_count() << endl;
    cout << "����ָ��b�����ü���Ϊ��" << b.use_count() << endl;

    //�鿴ָ���Ƿ��ռ����Ȩ
    cout << "����ָ��c�Ƿ��ռ��������Ȩ��" << c.unique() << endl;
    cout << "����ָ��e�Ƿ��ռ��������Ȩ��" << e.unique() << endl;
    
    //����c��eָ��Ķ���
    cout << "����ǰ��" << endl;
    cout << "����ָ��c��ֵΪ��" << *c << endl;
    cout << "����ָ��e��ֵΪ��" << *e << endl;
    swap(c,e);
    cout << "������" << endl;
    cout << "����ָ��c��ֵΪ��" << *c << endl;
    cout << "����ָ��e��ֵΪ��" << *e << endl;

    //reset���������ڲ����������Ȩ��������ԭ�ж�������ü�������
    c.reset();
    cout << "reset������ָ��a�����ü���Ϊ��" << a.use_count() << endl;

}
int main(){
    //����unique����ָ��
    test_unique_ptr();

    //����shared����ָ��
    test_shared_ptr();
}