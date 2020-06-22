/*
 * @Description: 归并排序
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-22 02:46:52
 * @LastEditors: szq
 * @LastEditTime: 2020-06-22 12:51:09
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\DevideAndConquer\mergeSort.cpp
 */ 

#include<iostream>
#include<vector>

using namespace std;

void mergeSort(vector<int> &nums, vector<int> &reg,int start,int end){
    if(start == end){
        return;
    }
    int len = end - start;
    int mid = (len >> 1) + start;
    int start1 = start;
    int end1 = mid;
    int start2 = mid+1;
    int end2 = end;
    mergeSort(nums,reg,start1,end1);
    mergeSort(nums,reg,start2,end2);
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