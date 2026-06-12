#include <stdio.h>
#include <stdlib.h>

// 结点定义
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 初始化头结点
Node *InitList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

// 头插法
void HeadInsert(Node *head, int x)
{
    Node *s = (Node *)malloc(sizeof(Node));

    s->data = x;
    s->next = head->next;
    head->next = s;
}

// 尾插法
void TailInsert(Node *head, int x)
{
    Node *p = head;

    while (p->next)
        p = p->next;

    Node *s = (Node *)malloc(sizeof(Node));

    s->data = x;
    s->next = NULL;

    p->next = s;
}

// 按位查找
Node *GetElem(Node *head, int pos)
{
    Node *p = head->next;

    int j = 1;

    while (p && j < pos)
    {
        p = p->next;
        j++;
    }

    return p;
}

// 按值查找
Node *LocateElem(Node *head, int x)
{
    Node *p = head->next;

    while (p)
    {
        if (p->data == x)
            return p;

        p = p->next;
    }

    return NULL;
}

// 插入
int ListInsert(Node *head, int pos, int x)
{
    Node *p = head;

    int j = 0;

    while (p && j < pos - 1)
    {
        p = p->next;
        j++;
    }

    if (!p)
        return 0;

    Node *s = (Node *)malloc(sizeof(Node));

    s->data = x;
    s->next = p->next;
    p->next = s;

    return 1;
}

// 删除
int ListDelete(Node *head, int pos)
{
    Node *p = head;

    int j = 0;

    while (p->next && j < pos - 1)
    {
        p = p->next;
        j++;
    }

    if (!p->next)
        return 0;

    Node *q = p->next;

    p->next = q->next;

    free(q);

    return 1;
}

// 输出链表
void PrintList(Node *head)
{
    Node *p = head->next;

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

// 销毁链表
void DestroyList(Node *head)
{
    Node *p = head;

    while (p)
    {
        Node *q = p;
        p = p->next;
        free(q);
    }
}

int main()
{
    Node *L = InitList();

    TailInsert(L, 10);
    TailInsert(L, 20);
    TailInsert(L, 30);

    PrintList(L);

    ListInsert(L, 2, 99);

    PrintList(L);

    ListDelete(L, 3);

    PrintList(L);

    DestroyList(L);

    return 0;
}
