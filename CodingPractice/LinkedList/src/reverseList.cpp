/*
 * @Description: 反转一个单链表
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-23 02:22:13
 * @LastEditors: szq
 * @LastEditTime: 2020-06-23 02:30:24
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\LinkedList\src\reverseList.cpp
 */ 

#include<iostream>
using namespace std;

//链表节点的定义
struct ListNode{
    int val;//节点值
    ListNode *next;//下一个节点
    ListNode(int x):val(x),next(NULL){}
};

ListNode* reverseList(ListNode* head){

    ListNode *preNode = NULL;
    while(head){
        //防止head->next被覆盖，保存
        ListNode *tmp = head->next;
        head->next = preNode;
        preNode = head;
        head = tmp;
    }
    return preNode;
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
    head = reverseList(head);
    //输出删除后的链表
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}