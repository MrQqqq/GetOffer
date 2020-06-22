/*
 * @Description: 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-23 01:07:28
 * @LastEditors: szq
 * @LastEditTime: 2020-06-23 01:27:19
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\DevideAndConquer\lowestCommonAncestor.cpp
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


TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    //如果根节点为空，直接返回NULL
    if(root == NULL){
        return NULL;
    }

    //如果指定的节点为根节点，直接返回根节点
    if(root == p || root == q){
        return root;
    }
    //处理子部分
    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);

    //左右都不为空，则根节点为祖先
    if(left != NULL && right != NULL){
        return root;
    }
    if(left != NULL){
        return left;
    }
    if(right != NULL){
        return right;
    }
    return NULL;
}