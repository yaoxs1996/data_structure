#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *pre;
    struct Node *next;
} node;

int main()
{
    node *head, *p, *q;
    head = (node *)malloc(sizeof(node));
    printf("Input some numbers and end with 0 \n");

    head->val = 0;
    head->next = NULL;
    head->pre = NULL;
    q = NULL;
    p = (node *)malloc(sizeof(node));

    scanf("%d", &p->val);
    while(p->val != 0)
    {
        head->next = p;
        p->pre = head;
        p->next = q;
        q = p;
        p = (node *)malloc(sizeof(node));
        scanf("%d", &p->val);
    }
    
    printf("\n");
    p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    
    system("pause");
    return 0;
}
