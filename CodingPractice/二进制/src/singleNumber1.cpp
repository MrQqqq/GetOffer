/*
 * @Description: ����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-23 04:14:58
 * @LastEditors: szq
 * @LastEditTime: 2020-06-23 04:21:11
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\������\src\singleNumber.cpp
 */ 

#include<iostream>
#include<vector>
using namespace std;

/**
 * @destription: ���������� a = 0 ^ a��0 = a ^ a���
 * @param nums:ԭ���� 
 * @return: ������ֻ����һ�ε�Ԫ��
 */
int singleNumber(vector<int> &nums){
    int res = 0;
    //�����������ظ�Ԫ�س��ֵĴ����������Σ���˸��� a = a ^ b ^ b
    //���Եõ��г���һ�ε�Ԫ��
    for(int i = 0;i < nums.size();++i){
        res = res ^ nums[i];
    }
    return res;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,1,2,3,4,6};
    cout << "ֻ����һ�ε�Ԫ��Ϊ��" << singleNumber(nums) << endl;
}