# C++ Pointer（指针）学习笔记

## 什么是指针

指针（Pointer）是 C++ 中最重要的概念之一。

简单来说：

> 指针是一个用于存储内存地址的变量。

例如：

```cpp
int a = 10;

int *p = &a;
```

此时：

```text
a = 10

&a = a的地址

p = 存储a地址

*p = 10
```

关系图：

```text
变量a
┌───────┐
│  10   │
└───────┘
    ▲
    │
    │
    p
```

---

# 取地址运算符 &

获取变量地址：

```cpp
int a = 10;

cout << &a;
```

输出：

```text
0x61ff08
```

（实际地址因运行环境而不同）

---

# 解引用运算符 *

访问地址对应的数据：

```cpp
int a = 10;

int *p = &a;

cout << *p;
```

输出：

```text
10
```

---

# 通过指针修改变量

```cpp
int a = 10;

int *p = &a;

*p = 100;
```

结果：

```cpp
cout << a;
```

输出：

```text
100
```

---

# nullptr 空指针

现代 C++ 推荐：

```cpp
int *p = nullptr;
```

作用：

* 表示不指向任何地址
* 防止野指针
* 类型安全

不要使用：

```cpp
NULL
```

---

# 指针与数组

数组名本质：

```cpp
int arr[5]={1,2,3,4,5};
```

数组名：

```cpp
arr
```

实际上表示：

```text
首元素地址
```

---

## 等价关系

```cpp
arr[0]
```

等价于：

```cpp
*(arr+0)
```

---

```cpp
arr[1]
```

等价于：

```cpp
*(arr+1)
```

---

# 指针遍历数组

```cpp
int arr[5]={1,2,3,4,5};

for(int *p=arr;p<arr+5;p++)
{
    cout<<*p<<" ";
}
```

输出：

```text
1 2 3 4 5
```

---

# 指针运算

定义：

```cpp
int *p=arr;
```

---

当前：

```text
p → arr[0]
```

执行：

```cpp
p++;
```

变为：

```text
p → arr[1]
```

---

常见操作：

```cpp
p++
p--
p+n
p-n
```

---

# 指针作为函数参数

普通交换：

```cpp
void swapNum(int a,int b)
{
    int t=a;
    a=b;
    b=t;
}
```

无法交换成功。

---

使用指针：

```cpp
void swapNum(int *a,int *b)
{
    int t=*a;

    *a=*b;

    *b=t;
}
```

调用：

```cpp
swapNum(&x,&y);
```

交换成功。

---

# 动态内存申请

## 单个变量

申请：

```cpp
int *p=new int;
```

赋值：

```cpp
*p=100;
```

释放：

```cpp
delete p;
```

---

## 动态数组

申请：

```cpp
int *arr=new int[n];
```

使用：

```cpp
arr[i]=i;
```

释放：

```cpp
delete[] arr;
```

---

# 二级指针

定义：

```cpp
int **pp;
```

结构：

```text
pp
 ↓
 p
 ↓
 a
```

示例：

```cpp
int a=10;

int *p=&a;

int **pp=&p;

cout<<**pp;
```

输出：

```text
10
```

---

# 指针与结构体

结构体：

```cpp
struct Student
{
    string name;
    int age;
};
```

定义：

```cpp
Student s={"Tom",18};

Student *p=&s;
```

访问成员：

```cpp
p->name

p->age
```

等价于：

```cpp
(*p).name

(*p).age
```

---

# 常见错误

## 野指针

```cpp
int *p;
```

未初始化直接使用：

```cpp
*p=10;
```

错误。

---

## 空指针解引用

```cpp
int *p=nullptr;

cout<<*p;
```

错误。

---

## 内存泄漏

```cpp
int *p=new int;
```

忘记：

```cpp
delete p;
```

会导致内存泄漏。

---

## 重复释放

```cpp
delete p;

delete p;
```

错误。

---

# 时间复杂度

| 操作   | 复杂度  |
| ---- | ---- |
| 地址访问 | O(1) |
| 解引用  | O(1) |
| 指针移动 | O(1) |
| 数组遍历 | O(n) |

---

# 蓝桥杯高频应用

## 数组遍历

```cpp
for(int *p=arr;p<arr+n;p++)
{
    cout<<*p<<" ";
}
```

---

## 函数传参

```cpp
swapNum(&a,&b);
```

---

## 动态数组

```cpp
int *arr=new int[n];

delete[] arr;
```

---

# 面试高频问题

### p 与 *p 的区别

```text
p   -> 地址

*p  -> 地址对应的数据
```

---

### 数组名是什么

```text
数组首元素地址
```

---

### nullptr 与 NULL 区别

```text
nullptr 是 C++11 引入的空指针常量

类型安全

推荐使用
```

---

# 学习总结

必须掌握：

* &
* *
* 指针定义
* 指针与数组
* 指针遍历数组
* 函数传参
* nullptr
* new
* delete
* delete[]

后续学习：

* 链表
* 树
* 图
* 智能指针
* STL源码

都会大量使用指针。

掌握指针，是理解 C++ 底层机制和数据结构实现的重要基础。
