//
//  main.c
//  DoubleLinkedList_HeadList
//
//  Created by chenyufeng on 16/3/3.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  实现带头结点和尾结点的非循环双向链表
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//1.初始化带头结点和尾结点的非循环双向链表
void InitialList(Node **pHead,Node **pTail){

    *pHead = (Node *)malloc(sizeof(Node));
    *pTail = (Node *)malloc(sizeof(Node));

    if (*pHead == NULL || *pTail == NULL) {
        printf("%s函数执行，内存分配失败，初始化双链表失败\n",__FUNCTION__);
    }else{

        (*pHead)->prior = NULL;
        (*pTail)->next = NULL;

        //链表为空的时候把头结点和尾结点连起来
        (*pHead)->next = *pTail;
        (*pTail)->prior = *pHead;

        printf("%s函数执行，带头结点和尾节点的双向非循环链表初始化成功\n",__FUNCTION__);
    }
}

//2.创建带头结点和尾结点的双向非循环链表
void CreateList(Node *pHead,Node *pTail){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pHead;
    while (pInsert->element > 0) {

        pMove->next = pInsert;
        pInsert->prior = pMove;
        pInsert->next = pTail;
        pTail->prior = pInsert;
        pMove = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->prior = NULL;
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行完成，带头节点和尾结点的双向非循环链表创建成功\n",__FUNCTION__);

}

//3.正序打印链表
void PrintList(Node *pHead,Node *pTail){

    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        printf("%d ",pMove->element);
        pMove = pMove->next;
    }

    printf("\n%s函数执行，正序打印带头结点尾结点的双向非循环链表创建成功\n",__FUNCTION__);
}

//4.逆序打印链表
void PrintReverseList(Node *pHead,Node *pTail){

    Node *pMove;
    pMove = pTail->prior;
    while (pMove != pHead) {
        printf("%d ",pMove->element);
        pMove = pMove->prior;
    }

    printf("\n%s函数执行，逆序打印带头结点尾结点的双向非循环链表创建成功\n",__FUNCTION__);
}

//5.清除链表中的所有元素，使成为空表
void ClearList(Node *pHead,Node *pTail){

    Node *pMove;
    pMove = pHead->next;

    while (pMove != pTail) {

        pHead->next = pMove->next;
        pMove->next->prior = pHead;
        free(pMove);
        pMove = pHead->next;
    }

    printf("%s函数执行，双向非循环链表清空成功\n",__FUNCTION__);
}



int main(int argc, const char * argv[]) {

    Node *pHead;//头结点
    Node *pTail;//尾结点

    InitialList(&pHead, &pTail);
    
    CreateList(pHead, pTail);
    PrintList(pHead, pTail);
    PrintReverseList(pHead,pTail);

    ClearList(pHead,pTail);
    PrintList(pHead, pTail);
    
    return 0;
}











