/*
 * @Description: �����㷨�������һ��������
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

//�������ڵ�Ķ���
struct TreeNode {
     int val;//�ڵ�ֵ
     TreeNode *left;//�ڵ�����ӽڵ�
     TreeNode *right;//�ڵ���Һ��ӽڵ�

	 //�������ڵ�Ĺ��캯��
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
/**
 * @destription: ʹ�÷����㷨�������������
 * @param root:���ڵ�
 * @return: ��������Ľ������
 */
vector<int> preOrderTraversalByDevideAndConquer(TreeNode* root){
	vector<int> res;
	//�ݹ���ֹ����
	if(root == NULL){
		return res;
	}
	//�ֶδ���
	vector<int> left = preOrderTraversalByDevideAndConquer(root->left);
	vector<int> right = preOrderTraversalByDevideAndConquer(root->right);

	//�ϲ����
	res.push_back(root->val);//�ȷ��ʸ��ڵ�
	res.insert(res.end(),left.begin(),left.end());//�ϲ����������
	res.insert(res.end(),right.begin(),right.end());//�ϲ����������
	return res;
}

int main(int argc,char *argv[]){
    //���������
	TreeNode *root = new TreeNode(1);
	TreeNode *childnode1 = new TreeNode(2);
	TreeNode *childnode2 = new TreeNode(3);
	root->right = childnode2;
	childnode2->left = childnode1;

    //�����㷨�������
	vector<int> res = preOrderTraversalByDevideAndConquer(root);
	//��������㷨��������Ľ��
	cout << "�����㷨������������" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;
	return 0;
}