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
        //这个里面是关键，也是判空的重要条件
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

//6.计算链表的长度
int SizeList(Node *pHead,Node *pTail){

    int i = 0;
    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        i++;
        pMove = pMove->next;
    }
    printf("%s函数执行，链表的长度为%d\n",__FUNCTION__,i);

    return i;
}

//7.判断带头结点尾结点的双向非循环链表是否为空,为空返回1，否则返回0
int IsEmptyList(Node *pHead,Node *pTail){
    if (pHead->next == pTail) {

        printf("%s函数执行，当前链表为空\n",__FUNCTION__);
        return 1;
    }

    printf("%s函数执行，当前链表不为空\n",__FUNCTION__);
    return 0;
}

//8.返回链表中第pos个结点中的元素，若返回-1，表示没有找到
int GetElement(Node *pHead,Node *pTail,int pos){

    int i = 1;
    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (i == pos) {
            printf("%s函数执行，第pos=%d位置的元素为%d\n",__FUNCTION__,pos,pMove->element);
            return pMove->element;
        }
        i++;
        pMove = pMove->next;
    }

    printf("%s函数执行，查找第pos=%d位置元素失败\n",__FUNCTION__,pos);

    return -1;
}

//9.从链表中查找给定值x的第一个元素，并返回data域的内存地址，否则返回NULL
int *GetElemAddr(Node *pHead,Node *pTail,int x){

    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (pMove->element == x) {
            printf("%s函数执行，值为%d的元素内存地址为0x%x\n",__FUNCTION__,x,&(pMove->element));
            return &(pMove->element);
        }
        pMove = pMove->next;
    }

    printf("%s函数执行，查找值为%d的元素地址失败\n",__FUNCTION__,x);

    return NULL;
}

//10.把链表中第pos个节点的值修改为x
int ModifyElem(Node *pHead,Node *pTail,int pos,int x){

    int i = 1;
    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (i == pos) {

            pMove->element = x;
            printf("%s函数执行，修改pos=%d位置值为%d成功\n",__FUNCTION__,pos,x);
            return 1;
        }
        i++;
        pMove = pMove->next;
    }

    printf("%s函数执行，修改pos=%d位置元素失败\n",__FUNCTION__,pos);

    return -1;
}

//11.向链表的表头插入一个元素
int InsertHeadList(Node *pHead,Node *pTail,int x){

    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->element = x;
    pInsert->prior = NULL;
    pInsert->next = NULL;

    pInsert->next = pHead->next;
    pHead->next->prior = pInsert;
    pHead->next = pInsert;
    pInsert->prior = pHead;

    printf("%s函数执行，在表头插入%d成功\n",__FUNCTION__,x);
    return 1;
}

//12.向链表的表尾插入一个元素
int InsertTailList(Node *pHead,Node *pTail,int x){

    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->element = x;
    pInsert->prior = NULL;
    pInsert->next = NULL;

    pTail->prior->next = pInsert;
    pInsert->prior = pTail->prior;
    pInsert->next = pTail;
    pTail->prior = pInsert;

    printf("%s函数执行，在表尾插入%d成功\n",__FUNCTION__,x);

    return 1;
}

int main(int argc, const char * argv[]) {

    Node *pHead;//头结点
    Node *pTail;//尾结点

    InitialList(&pHead, &pTail);

    CreateList(pHead, pTail);
    PrintList(pHead, pTail);
    PrintReverseList(pHead,pTail);

    SizeList(pHead, pTail);

    IsEmptyList(pHead,pTail);

    GetElement(pHead, pTail, 2);

    GetElemAddr(pHead, pTail, 5);

    ModifyElem(pHead, pTail, 2, 111);
    PrintList(pHead, pTail);
    
    InsertHeadList(pHead,pTail,100);
    PrintList(pHead, pTail);

    InsertTailList(pHead,pTail,900);
    PrintList(pHead, pTail);
    
    ClearList(pHead,pTail);
    PrintList(pHead, pTail);
    IsEmptyList(pHead,pTail);
    
    return 0;
}











