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
 * @Description: 二叉树遍历的代码
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

//二叉树节点的定义
struct TreeNode {
     int val;//节点值
     TreeNode *left;//节点的左孩子节点
     TreeNode *right;//节点的右孩子节点

	 //二叉树节点的构造函数
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * @destription: 递归法先序遍历一个二叉树
 * @param root:二叉树根节点    res：结果数组
 * @return: 没有返回值
 */ 
void preOrderTraversal1(TreeNode *root,vector<int> &res){
	//如果节点为空，直接返回
	if(root == NULL){
		return ;
	}
	res.push_back(root->val);//将根节点的值加入结果数组
	preOrderTraversal1(root->left,res);//先序遍历左子树
	preOrderTraversal1(root->right,res);//先序遍历右子树
}
/**
 * @destription: 非递归法先序遍历一个二叉树
 * @param root:二叉树根节点    res：结果数组
 * @return: 没有返回值
 */
void preOrderTraversal2(TreeNode *root,vector<int> &res){
	//如果节点为空，直接返回
	if(root == NULL){
		return;
	}
	
	//创建一个栈来保存节点
	stack<TreeNode*> s;
	while(root != NULL || s.size() > 0){
		while(root != NULL){
			res.push_back(root->val);//根节点值存入结果数组
			s.push(root);//节点存入栈
			root = root->left;//先遍历左子树
		}
		TreeNode *tmp = s.top();//栈顶元素
		s.pop();//出栈
		root = tmp->right;//遍历右子树
	}
}

/**
 * @destription: 递归法中序遍历二叉树
 * @param root:二叉树根节点    res：结果数组
 * @return: 没有返回值
 */
void inOrderTraversal1(TreeNode* root,vector<int> &res){
	//如果是空，直接返回
	if(root == NULL){
		return;
	}
	//先遍历左子树
	inOrderTraversal1(root->left,res);
	//再访问根节点
	res.push_back(root->val);
	//最后访问右子树
	inOrderTraversal1(root->right,res);

}

/**
 * @destription: 非递归法中序遍历一个二叉树
 * @param root:二叉树根节点    res：结果数组
 * @return: 没有返回值
 */
void inOrderTraversal2(TreeNode *root,vector<int> &res){
	//如果节点为空，直接返回
	if(root == NULL){
		return;
	}
	
	//创建一个栈来保存节点
	stack<TreeNode*> s;
	while(root != NULL || s.size() > 0){
		while(root != NULL){
			s.push(root);//节点存入栈
			root = root->left;//先遍历左子树
		}
		TreeNode *tmp = s.top();//栈顶元素
		s.pop();//出栈
		res.push_back(tmp->val);//根节点值存入结果数组
		root = tmp->right;//遍历右子树
	}
}

/**
 * @destription: 递归法后序遍历二叉树
 * @param root:二叉树根节点    res：结果数组
 * @return: 没有返回值
 */
void postOrderTraversal1(TreeNode* root,vector<int> &res){
	//如果是空，直接返回
	if(root == NULL){
		return;
	}
	//先后序遍历左子树
	postOrderTraversal1(root->left,res);
	//再后序遍历右子树
	postOrderTraversal1(root->right,res);
	//最后访问根节点
	res.push_back(root->val);
}

/**
 * @destription: 非递归法后序遍历一个二叉树
 * @param root:二叉树根节点    res：结果数组
 * @return: 没有返回值
 */
void postOrderTraversal2(TreeNode *root,vector<int> &res){
	//如果是空，直接返回
	if(root == NULL){
		return;
	}
	TreeNode* lastVisited;
	//创建一个栈来保存节点
	stack<TreeNode*> s;
	while(root != NULL || s.size() > 0){
		while(root != NULL){
			s.push(root);//节点存入栈
			root = root->left;//先遍历左子树
		}
		TreeNode *tmp = s.top();//栈顶元素
		//先不弹出节点，根节点必须在右节点弹出后再弹出
		if(tmp->right == NULL || tmp->right == lastVisited){
			s.pop();//弹出
			res.push_back(tmp->val);
			//标记当前节点已经弹出过
			lastVisited = tmp;
		}
		else{
			root = tmp->right;
		}
	}
}

/**
 * @destription: 层次遍历一个二叉树
 * @param root:二叉树根节点    res:保存每一层节点值的二维数组
 * @return: 没有返回值
 */
void levelTraversal(TreeNode* root,vector<vector<int>> &res){
	//如果节点为空，直接返回
	if(root == NULL){
		return;
	}
	//创建一个队列
	queue<TreeNode*> q;

	//根节点进队
	q.push(root);
	while(q.size() > 0){
		//创建一个数组保存每一层节点的值
		vector<int> levelNodes;
		//队列中保留的是每一层的所有节点，所以每次出队都要将上一层所有节点
		//全部出队
		for(int i = 0;i < q.size();++i){
			//获取队首元素
			TreeNode *top = q.front();
			//出队
			q.pop();
			//出队元素的值存入结果
			levelNodes.push_back(top->val);
			//出队的同时需要将下一层的节点进队
			if(top->left != NULL){
				q.push(top->left);
			}
			if(top->right != NULL){
				q.push(top->right);
			}
		}
		//每一层结果放入最后结果数组中
		res.push_back(levelNodes);
	}
}

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


	//先序遍历
	//递归法先序遍历
	vector<int> res;
	preOrderTraversal1(root,res);
	//输出递归法先序遍历的结果
	cout << "递归法先序遍历结果：" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;

	//清空res
	res.clear();
	//非递归法先序遍历
	preOrderTraversal2(root,res);
	//输出非递归法先序遍历的结果
	cout << "非递归法先序遍历结果：" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;




	//中序遍历
	//清空res
	res.clear();
	//递归法中序遍历
	inOrderTraversal1(root,res);
	//输出递归法中序遍历的结果
	cout << "递归法中序遍历结果：" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;

	//清空res
	res.clear();
	//非递归法中序遍历
	inOrderTraversal2(root,res);
	//输出非递归法中序遍历的结果
	cout << "非递归法中序遍历结果：" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;


	//后序遍历
	//清空res
	res.clear();
	//递归法后序遍历
	postOrderTraversal1(root,res);
	//输出递归法后序遍历的结果
	cout << "递归法后序遍历结果：" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;

	//清空res
	res.clear();
	//非递归法后序遍历
	postOrderTraversal2(root,res);
	//输出非递归法后序遍历的结果
	cout << "非递归法后序遍历结果：" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;


	//层次遍历结果
	vector<vector<int>> res_levelTraversal;
	levelTraversal(root,res_levelTraversal);
	for(int i = 0;i < res_levelTraversal.size();++i){
		cout << "第" << i+1 << "层元素为：" << " ";
		for(int j = 0;j < res_levelTraversal[i].size();++j){
			cout << res_levelTraversal[i][j] <<" ";
		}
		cout << endl;
	}


	//分治算法先序遍历
	res = preOrderTraversalByDevideAndConquer(root);
	//输出分治算法先序遍历的结果
	cout << "分治算法先序遍历结果：" << endl;
	for(auto num : res){
		cout << num << " ";
	}
	cout << endl;
	return 0;
}