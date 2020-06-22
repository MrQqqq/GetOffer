/*
 * @Description: 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于  x  的节点都在大于或等于  x  的节点之前。
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-23 03:34:54
 * @LastEditors: szq
 * @LastEditTime: 2020-06-23 03:52:47
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\LinkedList\src\partition.cpp
 */ 

#include<iostream>
using namespace std;

//链表节点的定义
struct ListNode{
    int val;//节点值
    ListNode *next;//下一个节点
    ListNode(int x):val(x),next(NULL){}
};

ListNode* partition(ListNode* head,int x){
    if(head == NULL){
        return head;
    }
    ListNode* headDummy = new ListNode(0);
    ListNode* tailDummy = new ListNode(0);
    ListNode* tail = tailDummy;
    headDummy->next = head;
    head = headDummy;
    while(head->next){
        if(head->next->val < x){
            head = head->next;
        }
        else{
            tail->next = head->next;
            tail = tail->next;
            head->next = head->next->next;
        }
    }
    tail->next = NULL;
    head->next = tailDummy->next;
    return headDummy->next;
}

int main(){
    //构建链表1->1->2->3->3
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    //分割
    head = partition(head,3);
    //输出删除后的链表
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
