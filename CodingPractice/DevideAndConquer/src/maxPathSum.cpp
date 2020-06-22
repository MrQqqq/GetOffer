/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-22 14:45:15
 * @LastEditors: szq
 * @LastEditTime: 2020-06-23 01:04:18
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\DevideAndConquer\maxPathSum.cpp
 */ 
#include<iostream>
using namespace std;

//二叉树节点的定义
struct TreeNode {
     int val;//节点值
     TreeNode *left;//节点的左孩子节点
     TreeNode *right;//节点的右孩子节点

	 //二叉树节点的构造函数
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


 struct ResultType{
     int singlePathSum;//单边最大值
     int maxSum;//最大值，单边或者两个单边+根的值
     ResultType(int x1,int x2):singlePathSum(x1),maxSum(x2){}
 }

ResultType helper(TreeNode *root){
    if(root == NULL){
        return ResultType(0,INT_MIN);
    }
    ResultType left = helper(root->left);
    ResultType right = helper(root->right);
    ResultType result;
    if(left.singlePathSum > right.singlePathSum){
        result.singlePathSum = max(left.singlePathSum + root->val,0);
    }
    else{
        result.singlePathSUm = max(right.singlePathSum + root->val,0);

    }
    
}
 int maxPathSum(TreeNode *root){
     ResultType result = helper(root);
     return result.maxSum;
 }