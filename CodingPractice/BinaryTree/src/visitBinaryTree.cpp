/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-22 02:23:00
 * @LastEditors: szq
 * @LastEditTime: 2020-06-22 02:40:42
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\BinaryTree\src\visitBinaryTree.cpp
 */ 
/*
 * @Description: �����������Ĵ���
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-21 23:05:58
 * @LastEditors: szq
 * @LastEditTime: 2020-06-22 02:16:42
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\BinaryTree\src\visitBinaryTree.cpp
 */ 

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
 * @destription: �ݹ鷨�������һ��������
 * @param root:���������ڵ�    res���������
 * @return: û�з���ֵ
 */ 
void preOrderTraversal1(TreeNode *root,vector<int> &res){
	//����ڵ�Ϊ�գ�ֱ�ӷ���
	if(root == NULL){
		return ;
	}
	res.push_back(root->val);//�����ڵ��ֵ����������
	preOrderTraversal1(root->left,res);//�������������
	preOrderTraversal1(root->right,res);//�������������
}
/**
 * @destription: �ǵݹ鷨�������һ��������
 * @param root:���������ڵ�    res���������
 * @return: û�з���ֵ
 */
void preOrderTraversal2(TreeNode *root,vector<int> &res){
	//����ڵ�Ϊ�գ�ֱ�ӷ���
	if(root == NULL){
		return;
	}
	
	//����һ��ջ������ڵ�
	stack<TreeNode*> s;
	while(root != NULL || s.size() > 0){
		while(root != NULL){
			res.push_back(root->val);//���ڵ�ֵ����������
			s.push(root);//�ڵ����ջ
			root = root->left;//�ȱ���������
		}
		TreeNode *tmp = s.top();//ջ��Ԫ��
		s.pop();//��ջ
		root = tmp->right;//����������
	}
}

/**
 * @destription: �ݹ鷨�������������
 * @param root:���������ڵ�    res���������
 * @return: û�з���ֵ
 */
void inOrderTraversal1(TreeNode* root,vector<int> &res){
	//����ǿգ�ֱ�ӷ���
	if(root == NULL){
		return;
	}
	//�ȱ���������
	inOrderTraversal1(root->left,res);
	//�ٷ��ʸ��ڵ�
	res.push_back(root->val);
	//������������
	inOrderTraversal1(root->right,res);

}

/**
 * @destription: �ǵݹ鷨�������һ��������
 * @param root:���������ڵ�    res���������
 * @return: û�з���ֵ
 */
void inOrderTraversal2(TreeNode *root,vector<int> &res){
	//����ڵ�Ϊ�գ�ֱ�ӷ���
	if(root == NULL){
		return;
	}
	
	//����һ��ջ������ڵ�
	stack<TreeNode*> s;
	while(root != NULL || s.size() > 0){
		while(root != NULL){
			s.push(root);//�ڵ����ջ
			root = root->left;//�ȱ���������
		}
		TreeNode *tmp = s.top();//ջ��Ԫ��
		s.pop();//��ջ
		res.push_back(tmp->val);//���ڵ�ֵ����������
		root = tmp->right;//����������
	}
}

/**
 * @destription: �ݹ鷨�������������
 * @param root:���������ڵ�    res���������
 * @return: û�з���ֵ
 */
void postOrderTraversal1(TreeNode* root,vector<int> &res){
	//����ǿգ�ֱ�ӷ���
	if(root == NULL){
		return;
	}
	//�Ⱥ������������
	postOrderTraversal1(root->left,res);
	//�ٺ������������
	postOrderTraversal1(root->right,res);
	//�����ʸ��ڵ�
	res.push_back(root->val);
}

/**
 * @destription: �ǵݹ鷨�������һ��������
 * @param root:���������ڵ�    res���������
 * @return: û�з���ֵ
 */
void postOrderTraversal2(TreeNode *root,vector<int> &res){
	//����ǿգ�ֱ�ӷ���
	if(root == NULL){
		return;
	}
	TreeNode* lastVisited;
	//����һ��ջ������ڵ�
	stack<TreeNode*> s;
	while(root != NULL || s.size() > 0){
		while(root != NULL){
			s.push(root);//�ڵ����ջ
			root = root->left;//�ȱ���������
		}
		TreeNode *tmp = s.top();//ջ��Ԫ��
		//�Ȳ������ڵ㣬���ڵ�������ҽڵ㵯�����ٵ���
		if(tmp->right == NULL || tmp->right == lastVisited){
			s.pop();//����
			res.push_back(tmp->val);
			//��ǵ�ǰ�ڵ��Ѿ�������
			lastVisited = tmp;
		}
		else{
			root = tmp->right;
		}
	}
}

/**
 * @destription: ��α���һ��������
 * @param root:���������ڵ�    res:����ÿһ��ڵ�ֵ�Ķ�ά����
 * @return: û�з���ֵ
 */
void levelTraversal(TreeNode* root,vector<vector<int>> &res){
	//����ڵ�Ϊ�գ�ֱ�ӷ���
	if(root == NULL){
		return;
	}
	//����һ������
	queue<TreeNode*> q;

	//���ڵ����
	q.push(root);
	while(q.size() > 0){
		//����һ�����鱣��ÿһ��ڵ��ֵ
		vector<int> levelNodes;
		//�����б�������ÿһ������нڵ㣬����ÿ�γ��Ӷ�Ҫ����һ�����нڵ�
		//ȫ������
		for(int i = 0;i < q.size();++i){
			//��ȡ����Ԫ��
			TreeNode *top = q.front();
			//����
			q.pop();
			//����Ԫ�ص�ֵ������
			levelNodes.push_back(top->val);
			//���ӵ�ͬʱ��Ҫ����һ��Ľڵ����
			if(top->left != NULL){
				q.push(top->left);
			}
			if(top->right != NULL){
				q.push(top->right);
			}
		}
		//ÿһ�������������������
		res.push_back(levelNodes);
	}
}

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


	//�������
	//�ݹ鷨�������
	vector<int> res;
	preOrderTraversal1(root,res);
	//����ݹ鷨��������Ľ��
	cout << "�ݹ鷨������������" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;

	//���res
	res.clear();
	//�ǵݹ鷨�������
	preOrderTraversal2(root,res);
	//����ǵݹ鷨��������Ľ��
	cout << "�ǵݹ鷨������������" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;




	//�������
	//���res
	res.clear();
	//�ݹ鷨�������
	inOrderTraversal1(root,res);
	//����ݹ鷨��������Ľ��
	cout << "�ݹ鷨������������" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;

	//���res
	res.clear();
	//�ǵݹ鷨�������
	inOrderTraversal2(root,res);
	//����ǵݹ鷨��������Ľ��
	cout << "�ǵݹ鷨������������" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;


	//�������
	//���res
	res.clear();
	//�ݹ鷨�������
	postOrderTraversal1(root,res);
	//����ݹ鷨��������Ľ��
	cout << "�ݹ鷨������������" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;

	//���res
	res.clear();
	//�ǵݹ鷨�������
	postOrderTraversal2(root,res);
	//����ǵݹ鷨��������Ľ��
	cout << "�ǵݹ鷨������������" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;


	//��α������
	vector<vector<int>> res_levelTraversal;
	levelTraversal(root,res_levelTraversal);
	for(int i = 0;i < res_levelTraversal.size();++i){
		cout << "��" << i+1 << "��Ԫ��Ϊ��" << " ";
		for(int j = 0;j < res_levelTraversal[i].size();++j){
			cout << res_levelTraversal[i][j] <<" ";
		}
		cout << endl;
	}


	//�����㷨�������
	res = preOrderTraversalByDevideAndConquer(root);
	//��������㷨��������Ľ��
	cout << "�����㷨������������" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;
	return 0;
}