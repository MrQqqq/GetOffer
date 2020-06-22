/*
 * @Description: 判断一个二叉树是否为高度平衡的二叉树
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-22 14:21:05
 * @LastEditors: szq
 * @LastEditTime: 2020-06-22 14:34:07
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\DevideAndConquer\isBalanced.cpp
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

/**
 * @destription: 求二叉树的高度，如果二叉树高度平衡则返回二叉树的高度，否则返回-1
 * @param root:二叉树根节点
 * @return: 二叉树高度平衡，返回二叉树高度，否则返回-1
 */
int maxDepth(TreeNode *root){
    //如果根节点为空，二叉树的高度为0
    if(root ==  NULL){
        return 0;
    }
    //分别求左子树和右子树的高度
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    //关键：如果左子树或者右子树高度不平衡或者左右子树高度差大于1，那么二叉树高度不平衡
    if(left == -1 || right == -1 || left - right > 1 || right - left > 1){
        return -1;
    }
    //高度平衡的话，返回二叉树的高度
    return left >= right ? left + 1 : right + 1;
}

 /**
  * @destription: 判断二叉树是否高度平衡
  * @param root:二叉树根节点 
  * @return: 二叉树高度平衡返回true,否则返回false
  */
 bool isBalanced(TreeNode *root){
     if(maxDepth(root) == -1){
         return false;
     }
     return true;
 }

 int main(int argc,char *argv[]){
    //构造二叉树
	TreeNode *root = new TreeNode(1);
	TreeNode *childnode1 = new TreeNode(2);
	TreeNode *childnode2 = new TreeNode(3);
	root->right = childnode2;
	childnode2->left = childnode1;

    bool res = isBalanced(root);
    if(res){
        cout << "该二叉树是平衡二叉树!" << endl;
    }
    else{
        cout << "该二叉树不是平衡二叉树！" << endl;
    }
    return 0;

}