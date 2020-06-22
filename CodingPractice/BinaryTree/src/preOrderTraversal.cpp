/*
 * @Description: 分治算法先序遍历一个二叉树
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-22 02:43:35
 * @LastEditors: szq
 * @LastEditTime: 2020-06-22 02:46:25
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\DevideAndConquer\preOrderTraversal.cpp
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
/**
 * @destription: 使用分治算法先序遍历二叉树
 * @param root:根节点
 * @return: 先序遍历的结果数组
 */
vector<int> preOrderTraversalByDevideAndConquer(TreeNode* root){
	vector<int> res;
	//递归终止条件
	if(root == NULL){
		return res;
	}
	//分段处理
	vector<int> left = preOrderTraversalByDevideAndConquer(root->left);
	vector<int> right = preOrderTraversalByDevideAndConquer(root->right);

	//合并结果
	res.push_back(root->val);//先访问根节点
	res.insert(res.end(),left.begin(),left.end());//合并左子树结果
	res.insert(res.end(),right.begin(),right.end());//合并右子树结果
	return res;
}

int main(int argc,char *argv[]){
    //构造二叉树
	TreeNode *root = new TreeNode(1);
	TreeNode *childnode1 = new TreeNode(2);
	TreeNode *childnode2 = new TreeNode(3);
	root->right = childnode2;
	childnode2->left = childnode1;

    //分治算法先序遍历
	vector<int> res = preOrderTraversalByDevideAndConquer(root);
	//输出分治算法先序遍历的结果
	cout << "分治算法先序遍历结果：" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;
	return 0;
}