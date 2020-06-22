/*
 * @Description: 求一个二叉树的深度（分治法）
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-22 13:49:56
 * @LastEditors: szq
 * @LastEditTime: 2020-06-22 14:02:36
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\DevideAndConquer\maxDepth.cpp
 */ 

#include<iostream>
#include<vector>
using namespace std;

//二叉树节点的定义
struct TreeNode {
     int val;//节点值
     TreeNode *left;//节点的左孩子节点
     TreeNode *right;//节点的右孩子节点

	 //二叉树节点的构造函数
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int maxDepth(TreeNode* root){
    //如果根节点为空，则深度为空
    if(root == NULL){
        return 0;
    }
    //分别求左右子树的深度
    int maxDepth_left = maxDepth(root->left);
    int maxDepth_right = maxDepth(root->right);
    //二叉树的深度为左右子树深度中最大值再加1
    return maxDepth_left >= maxDepth_right ? maxDepth_left + 1 : maxDepth_right + 1;
}

int main(int argc,char *argv[]){
    //构造二叉树
	TreeNode *root = new TreeNode(1);
	TreeNode *childnode1 = new TreeNode(2);
	TreeNode *childnode2 = new TreeNode(3);
	root->right = childnode2;
	childnode2->left = childnode1;

    //求二叉树的深度
    int depth = maxDepth(root);
    cout << "二叉树的深度为：" << depth << endl;

}