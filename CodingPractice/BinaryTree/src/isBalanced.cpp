/*
 * @Description: �ж�һ���������Ƿ�Ϊ�߶�ƽ��Ķ�����
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-22 14:21:05
 * @LastEditors: szq
 * @LastEditTime: 2020-06-22 14:34:07
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\DevideAndConquer\isBalanced.cpp
 */ 
#include<iostream>
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
 * @destription: ��������ĸ߶ȣ�����������߶�ƽ���򷵻ض������ĸ߶ȣ����򷵻�-1
 * @param root:���������ڵ�
 * @return: �������߶�ƽ�⣬���ض������߶ȣ����򷵻�-1
 */
int maxDepth(TreeNode *root){
    //������ڵ�Ϊ�գ��������ĸ߶�Ϊ0
    if(root ==  NULL){
        return 0;
    }
    //�ֱ������������������ĸ߶�
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    //�ؼ�����������������������߶Ȳ�ƽ��������������߶Ȳ����1����ô�������߶Ȳ�ƽ��
    if(left == -1 || right == -1 || left - right > 1 || right - left > 1){
        return -1;
    }
    //�߶�ƽ��Ļ������ض������ĸ߶�
    return left >= right ? left + 1 : right + 1;
}

 /**
  * @destription: �ж϶������Ƿ�߶�ƽ��
  * @param root:���������ڵ� 
  * @return: �������߶�ƽ�ⷵ��true,���򷵻�false
  */
 bool isBalanced(TreeNode *root){
     if(maxDepth(root) == -1){
         return false;
     }
     return true;
 }

 int main(int argc,char *argv[]){
    //���������
	TreeNode *root = new TreeNode(1);
	TreeNode *childnode1 = new TreeNode(2);
	TreeNode *childnode2 = new TreeNode(3);
	root->right = childnode2;
	childnode2->left = childnode1;

    bool res = isBalanced(root);
    if(res){
        cout << "�ö�������ƽ�������!" << endl;
    }
    else{
        cout << "�ö���������ƽ���������" << endl;
    }
    return 0;

}