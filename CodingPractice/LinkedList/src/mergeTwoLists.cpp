/*
 * @Description: 合并两个已经排好序的链表
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-23 03:20:10
 * @LastEditors: szq
 * @LastEditTime: 2020-06-23 03:32:21
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\LinkedList\src\mergeTwoLists.cpp
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
 * @destription: 合并两个链表
 * @param l1:链表1   l2:链表2 
 * @return: 合并后新链表的头结点
 */
ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
    //哑巴节点，保存头结点
    ListNode* dummy = new ListNode(0);
    ListNode* head = dummy;

    //当两个链表都不为空时，比较两个链表头结点的值
    while(l1 != NULL && l2 != NULL){
        //如果链表l1头结点值小于l2头结点的值，l1头结点加在新链表后面，并且l1向后移
        if(l1->val < l2->val){
            head->next = l1;
            l1 = l1->next;
        }
        //否则，l2头结点加在新链表后面，并且l2向后移
        else{
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }

    //如果l1不为空，将l1添加到新链表后面
    while(l1){
        head->next = l1;
        l1 = l1->next;
        head = head->next;
    }
    //如果l2不为空，将l2添加到新链表后面
    while(l2){
        head->next = l2;
        l2 = l2->next;
        head = head->next;
    }
    return dummy->next;
}