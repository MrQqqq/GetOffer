/*
 * @Description: 保留链表中没有重复出现的元素
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-23 01:57:18
 * @LastEditors: szq
 * @LastEditTime: 2020-06-23 02:20:54
 * @FilePath: \cppc:\Users\86151\Desktop\GetOffer\CodingPractice\LinkedList\src\deleteDuplicates2.cpp
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
 * @destription: 删除重复出现的元素，保留只出现一次的元素
 * @param head:链表的头结点
 * @return: 删除重复出现节点后的链表头节点
 */
ListNode* deleteDuplicates(ListNode* head){
    //如果头结点为空或者链表中只有一个元素，直接返回头结点
    if(head == NULL || head->next == NULL){
        return head;
    }

    //由于头节点可能被删除，因此需要创建一个辅助节点，辅助节点的next指针指向头结点
    ListNode* resNode = new ListNode(0);
    resNode->next = head;

    //临时节点
    ListNode* tmp = resNode;
    //记录需要删除的节点的值
    int rmVal;
    while(tmp->next != NULL && tmp->next->next != NULL){
        //当节点值重复出现时
        if(tmp->next->val == tmp->next->next->val){
            //记录需要删除的节点值
            rmVal = tmp->next->val;
            //删除节点
            while(tmp->next != NULL && tmp->next->val == rmVal){
                tmp->next = tmp->next->next;
            }
        }
        //否则，判断下一个节点
        else{
            tmp = tmp->next;
        }
    }
    return resNode->next;
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

    //删除重复出现的元素
    head = deleteDuplicates(head);
    //输出删除后的链表
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}