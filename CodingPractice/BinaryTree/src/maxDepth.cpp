/*
 * @Description: ��һ������������ȣ����η���
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

//�������ڵ�Ķ���
struct TreeNode {
     int val;//�ڵ�ֵ
     TreeNode *left;//�ڵ�����ӽڵ�
     TreeNode *right;//�ڵ���Һ��ӽڵ�

	 //�������ڵ�Ĺ��캯��
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int maxDepth(TreeNode* root){
    //������ڵ�Ϊ�գ������Ϊ��
    if(root == NULL){
        return 0;
    }
    //�ֱ����������������
    int maxDepth_left = maxDepth(root->left);
    int maxDepth_right = maxDepth(root->right);
    //�����������Ϊ����������������ֵ�ټ�1
    return maxDepth_left >= maxDepth_right ? maxDepth_left + 1 : maxDepth_right + 1;
}

int main(int argc,char *argv[]){
    //���������
	TreeNode *root = new TreeNode(1);
	TreeNode *childnode1 = new TreeNode(2);
	TreeNode *childnode2 = new TreeNode(3);
	root->right = childnode2;
	childnode2->left = childnode1;

    //������������
    int depth = maxDepth(root);
    cout << "�����������Ϊ��" << depth << endl;

}