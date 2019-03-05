#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} node;

node* create_ins_head(int n)
{
    node *head, *p;
    head = (node *)malloc(sizeof(node));
    head->val = 0;
    head->next = NULL;

    for(int i=0; i<n; i++)
    {
        p = (node *)malloc(sizeof(node));
        printf("Input number: ");
        scanf("%d", &p->val);

        //头插法 逆序
        p->next = head->next;
        head->next = p;
    }

    return head;
}

//尾插法建立单链表
//结点次序与输入数据次序相同
node* create_ins_rear(int n)
{
    node *head, *s, *r;     //r为表尾指针
    head = (node *)malloc(sizeof(node));
    head->val = 0;
    head->next = NULL;
    r = head;

    for(int i=0; i<n; i++)
    {
        s = (node *)malloc(sizeof(node));
        printf("Input number: ");
        scanf("%d", &s->val);
        r->next = s;
        r = s;      //r指向新的表尾结点
    }
    r->next = NULL;
    return head;
}

//按序号查找结点值
node* getNodeByLoc(node *head, int i)
{
    int j = 1;
    node *p = head->next;       //头结点指针赋给p
    if(i == 0)
    {
        return head;
    }
    if(i < 1)
    {
        return NULL;
    }
    while(p && j<i)
    {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找表结点
node *getNodeByVal(node *head, int e)
{
    node *p = head->next;
    while(p != NULL && p->val != e)
    {
        p = p->next;
    }
    return p;       //找到后返回该结点指针，否则返回NULL
}

//打印结点
void printNode(node *head)
{
    node *p;
    p = head->next;

    printf("Printing nodes...\n");
    while(p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
}

//结点插入

//结点删除

//求表长

#endif
