#include <stdio.h>
#include <stdlib.h>

// 双链表结点
typedef struct DNode
{
    int data;
    struct DNode *prior;
    struct DNode *next;
} DNode;

// 初始化
DNode *InitList()
{
    DNode *head = (DNode *)malloc(sizeof(DNode));

    head->prior = NULL;
    head->next = NULL;

    return head;
}

// 尾插法
void TailInsert(DNode *head, int x)
{
    DNode *p = head;

    while (p->next)
        p = p->next;

    DNode *s = (DNode *)malloc(sizeof(DNode));

    s->data = x;
    s->next = NULL;
    s->prior = p;

    p->next = s;
}

// 插入到第pos个位置
int ListInsert(DNode *head, int pos, int x)
{
    DNode *p = head;

    int j = 0;

    while (p && j < pos - 1)
    {
        p = p->next;
        j++;
    }

    if (!p)
        return 0;

    DNode *s = (DNode *)malloc(sizeof(DNode));

    s->data = x;

    s->next = p->next;
    s->prior = p;

    if (p->next)
        p->next->prior = s;

    p->next = s;

    return 1;
}

// 删除第pos个结点
int ListDelete(DNode *head, int pos)
{
    DNode *p = head->next;

    int j = 1;

    while (p && j < pos)
    {
        p = p->next;
        j++;
    }

    if (!p)
        return 0;

    p->prior->next = p->next;

    if (p->next)
        p->next->prior = p->prior;

    free(p);

    return 1;
}

// 正向遍历
void PrintForward(DNode *head)
{
    DNode *p = head->next;

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

// 逆向遍历
void PrintBackward(DNode *head)
{
    DNode *p = head;

    while (p->next)
        p = p->next;

    while (p != head)
    {
        printf("%d ", p->data);
        p = p->prior;
    }

    printf("\n");
}

// 销毁链表
void DestroyList(DNode *head)
{
    DNode *p = head;

    while (p)
    {
        DNode *q = p;
        p = p->next;
        free(q);
    }
}

int main()
{
    DNode *L = InitList();

    TailInsert(L, 10);
    TailInsert(L, 20);
    TailInsert(L, 30);

    PrintForward(L);

    ListInsert(L, 2, 99);

    PrintForward(L);

    ListDelete(L, 3);

    PrintForward(L);

    PrintBackward(L);

    DestroyList(L);

    return 0;
}
