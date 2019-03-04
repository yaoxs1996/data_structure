#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int val;
    struct Node *next;
} node;

int main()
{
    int n;
    node *head, *p;

    //初始化头结点
    head = (node *)malloc(sizeof(node));
    head->val = 0;
    head->next = NULL;

    for(int i=0; i<20; i++)
    {
        p = (node *)malloc(sizeof(node));
        scanf("%d", &n);
        p->val = n;

        //头插法
        p->next = head->next;
        head->next = p;
    }

    //回到非头的第一个节点，打印
    p = head->next;
    while(p)
    {
        printf("%d ", p->val);
        p = p->next;
    }

    system("pause");
    return 0;
}
