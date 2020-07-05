/*
 * @Description: 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-23 04:14:58
 * @LastEditors: szq
 * @LastEditTime: 2020-06-23 04:21:11
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\二进制\src\singleNumber.cpp
 */ 

#include<iostream>
#include<vector>
using namespace std;

/**
 * @destription: 根据亦或操作 a = 0 ^ a和0 = a ^ a求解
 * @param nums:原数组 
 * @return: 数组中只出现一次的元素
 */
int singleNumber(vector<int> &nums){
    int res = 0;
    //由于数组中重复元素出现的次数都是两次，因此根据 a = a ^ b ^ b
    //可以得到中出现一次的元素
    for(int i = 0;i < nums.size();++i){
        res = res ^ nums[i];
    }
    return res;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,1,2,3,4,6};
    cout << "只出现一次的元素为：" << singleNumber(nums) << endl;
}