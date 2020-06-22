/*
 * @Description: 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-23 01:34:35
 * @LastEditors: szq
 * @LastEditTime: 2020-06-23 01:55:02
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\LinkedList\src\deleteDuplicates.cpp
 */ 
#include<iostream>
using namespace std;

//链表节点的定义
struct ListNode{
    int val;//节点值
    ListNode *next;//下一个节点
    ListNode(int x):val(x),next(NULL){}
};

/**
 * @destription: 删除排序链表中重复的元素
 * @param head:链表头结点
 * @return: 删除重复元素后的链表头结点
 */
ListNode* deleteDuplicates(ListNode* head){
    //如果头节点为空或者链表中只有一个节点，直接返回头结点
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* curNode = head->next;//当前节点
    ListNode* preNode = head;//前一个节点
    while(curNode != NULL){
        //如果当前节点和前一个节点值相等，则跳过当前节点
        if(curNode->val == preNode->val){
            preNode->next = curNode->next;
        }
        //否则更新前一个节点
        else{
            preNode = curNode;
        }
        //检查下一个节点
        curNode = curNode->next;
    }
    return head;
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

    head = deleteDuplicates(head);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}