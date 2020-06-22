/*
 * @Description: 反转从位置m到n的链表。使用一趟扫描完成反转
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-23 02:36:57
 * @LastEditors: szq
 * @LastEditTime: 2020-06-23 03:18:18
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\LinkedList\src\reverseBetween.cpp
 */ 

#include<iostream>
using namespace std;

//链表节点的定义
struct ListNode{
    int val;//节点值
    ListNode *next;//下一个节点
    ListNode(int x):val(x),next(NULL){}
};


ListNode* reverseBetween(ListNode* head,int m,int n){
    //如果头结点为空，直接返回头结点
    if(head == NULL){
        return head;
    }
    //创建一个哑巴节点
    ListNode*  dummy = new ListNode(0);
    //哑巴节点的next指针指向head
    dummy->next = head;
    //保存第m个节点之前的一个节点
    ListNode* preNode;

    head = dummy;
    int i = 0;
    //前m-1个节点不变
    while(i < m){
        preNode = head;
        head = head->next;
        i++;
    }

    //反转后的末尾节点
    ListNode* end = NULL;
    //记录第m个节点，因为后面要将第m个节点的next指针指向第n+1节点
    ListNode* mid = head;
    while(head != NULL && i <= n){
        ListNode* next = head->next;
        head->next = end;
        end = head;
        head = next;
        i++;
    }
    //第m-1节点的next指向第n节点
    preNode->next = end;
    //后面剩余的节点直接加在后面
    mid->next = head;
    return dummy->next;

}


int main(){
    //构建链表1->1->2->3->3
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    //反转链表
    head = reverseBetween(head,2,4);
    //输出删除后的链表
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
