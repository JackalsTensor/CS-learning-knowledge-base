#include <stdio.h>

#define MAXSIZE 100

// 顺序表结构体
typedef struct
{
    int data[MAXSIZE];
    int length;
} SeqList;

// 初始化
void InitList(SeqList *L)
{
    L->length = 0;
}

// 插入元素（位置从1开始）
int ListInsert(SeqList *L, int pos, int e)
{
    if (pos < 1 || pos > L->length + 1)
        return 0;

    if (L->length >= MAXSIZE)
        return 0;

    for (int i = L->length; i >= pos; i--)
    {
        L->data[i] = L->data[i - 1];
    }

    L->data[pos - 1] = e;
    L->length++;

    return 1;
}

// 删除元素
int ListDelete(SeqList *L, int pos, int *e)
{
    if (pos < 1 || pos > L->length)
        return 0;

    *e = L->data[pos - 1];

    for (int i = pos; i < L->length; i++)
    {
        L->data[i - 1] = L->data[i];
    }

    L->length--;

    return 1;
}

// 按位查找
int GetElem(SeqList L, int pos)
{
    if (pos < 1 || pos > L.length)
        return -1;

    return L.data[pos - 1];
}

// 按值查找
int LocateElem(SeqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }

    return 0;
}

// 输出顺序表
void PrintList(SeqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

// 测试
int main()
{
    SeqList L;
    InitList(&L);

    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);
    ListInsert(&L, 3, 30);

    PrintList(L);

    int x;
    ListDelete(&L, 2, &x);

    printf("删除元素:%d\n", x);

    PrintList(L);

    printf("第2个元素:%d\n", GetElem(L, 2));

    printf("30的位置:%d\n", LocateElem(L, 30));

    return 0;
}
