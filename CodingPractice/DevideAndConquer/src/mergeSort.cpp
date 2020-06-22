/*
 * @Description: 归并排序（分治法）
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-22 02:46:52
 * @LastEditors: szq
 * @LastEditTime: 2020-06-22 13:04:20
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\DevideAndConquer\mergeSort.cpp
 */ 

#include<iostream>
#include<vector>

using namespace std;

/**
 * @destription: 归并排序
 * @param nums:待排序数组  reg:中间数组   start：开始索引  end:结束索引
 * @return: 没有返回值
 */
void mergeSort(vector<int> &nums, vector<int> &reg,int start,int end){
    //递归循环结束条件
    if(start == end){
        return;
    }

    //划分
    int len = end - start;
    int mid = (len >> 1) + start;
    int start1 = start;
    int end1 = mid;
    int start2 = mid+1;
    int end2 = end;

    //分段处理
    mergeSort(nums,reg,start1,end1);
    mergeSort(nums,reg,start2,end2);

    //合并结果
    int k = start;
    while(start1 <= end1 && start2 <= end2){
        reg[k++] = nums[start1] < nums[start2]?nums[start1++] : nums[start2++];
    }
    while(start1 <= end1){
        reg[k++] = nums[start1++];
    }
    while(start2 <= end2){
        reg[k++] = nums[start2++];
    }
    for(k = start;k <= end;++k){
        nums[k] = reg[k];
    }
}


//测试
int main(int argc,char *argv[]){
    vector<int> nums = {9,6,2,4,7,8,3,5,1};
    vector<int> reg(9);
    mergeSort(nums,reg,0,8);
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}