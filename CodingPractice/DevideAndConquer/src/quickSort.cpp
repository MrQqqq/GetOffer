/*
 * @Description: 快速排序
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-22 13:05:15
 * @LastEditors: szq
 * @LastEditTime: 2020-06-22 13:47:58
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\DevideAndConquer\quickSort.cpp
 */ 
#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &nums,int start,int end);
void quickSort(vector<int> &nums,int start,int end){
    if(start >= end){
        return;
    }
    int index = partition(nums,start,end);
    quickSort(nums,start,index-1);
    quickSort(nums,index+1,end);
}

int partition(vector<int> &nums,int start,int end){
    int cur = nums[start];
    while(start < end){
        while(start < end && nums[end] > cur){
            end--;
        }
        if(start < end){
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
        }
        while(start < end && nums[start] < cur){
            start++;
        }
        if(start < end){
            int tmp = nums[end];
            nums[end] = nums[start];
            nums[start] = tmp;
            end--;
        }
    }
    nums[start] = cur;
    return start;
}


//测试
int main(int argc,char *argv[]){
    vector<int> nums = {9,6,2,4,7,8,3,5,1};
    quickSort(nums,0,8);
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}