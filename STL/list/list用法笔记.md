# C++ STL list 深度解析

## 一、什么是 list

`std::list` 是 C++ STL 中的双向链表容器。

头文件：

```cpp
#include <list>
```

定义：

```cpp
list<int> L;
```

底层结构：

```text
NULL ← [10] ⇄ [20] ⇄ [30] → NULL
```

每个结点包含：

```cpp
struct Node
{
    int data;
    Node* prev;
    Node* next;
};
```

因此 list 本质上就是：

```text
双向链表（Doubly Linked List）
```

---

# 二、list 与 vector 的区别

| 项目   | vector | list |
| ---- | ------ | ---- |
| 底层   | 动态数组   | 双向链表 |
| 内存   | 连续     | 不连续  |
| 随机访问 | O(1)   | O(n) |
| 尾插   | O(1)   | O(1) |
| 中间插入 | O(n)   | O(1) |
| 中间删除 | O(n)   | O(1) |

示例：

```cpp
vector<int> v={1,2,3};
cout<<v[1];
```

合法。

---

```cpp
list<int> L={1,2,3};
cout<<L[1];
```

错误。

原因：

```text
链表无法随机访问
```

---

# 三、创建 list

## 空链表

```cpp
list<int> L;
```

---

## 指定大小

```cpp
list<int> L(5);
```

结果：

```text
0 0 0 0 0
```

---

## 指定初始值

```cpp
list<int> L(5,100);
```

结果：

```text
100 100 100 100 100
```

---

## 初始化列表

```cpp
list<int> L={1,2,3,4,5};
```

---

# 四、遍历方式

## 范围 for

```cpp
for(auto x:L)
{
    cout<<x<<" ";
}
```

推荐指数：

★★★★★

---

## 迭代器

```cpp
for(auto it=L.begin();it!=L.end();++it)
{
    cout<<*it<<" ";
}
```

推荐指数：

★★★★★

---

## 逆序遍历

```cpp
for(auto it=L.rbegin();it!=L.rend();++it)
{
    cout<<*it<<" ";
}
```

---

# 五、插入操作

## push_back

尾插

```cpp
L.push_back(10);
```

复杂度：

```text
O(1)
```

---

## push_front

头插

```cpp
L.push_front(5);
```

复杂度：

```text
O(1)
```

---

## insert

指定位置插入

```cpp
auto it=L.begin();

++it;

L.insert(it,99);
```

结果：

```text
1 99 2 3
```

复杂度：

```text
O(1)
```

（已获得迭代器的情况下）

---

## emplace

原地构造

```cpp
L.emplace(it,100);
```

---

## emplace_back

```cpp
L.emplace_back(200);
```

---

## emplace_front

```cpp
L.emplace_front(300);
```

---

# 六、删除操作

## pop_back

删除尾元素

```cpp
L.pop_back();
```

---

## pop_front

删除头元素

```cpp
L.pop_front();
```

---

## erase

删除指定位置

```cpp
auto it=L.begin();

L.erase(it);
```

---

## remove

删除所有指定值

```cpp
L.remove(5);
```

示例：

```text
1 5 2 5 3
```

↓

```text
1 2 3
```

---

## clear

清空链表

```cpp
L.clear();
```

---

# 七、访问元素

## front

```cpp
cout<<L.front();
```

首元素。

---

## back

```cpp
cout<<L.back();
```

尾元素。

---

## begin

```cpp
auto it=L.begin();
```

首迭代器。

---

## end

```cpp
auto it=L.end();
```

尾后迭代器。

---

# 八、容量函数

## size

```cpp
L.size();
```

返回元素个数。

---

## empty

```cpp
L.empty();
```

判断是否为空。

---

## max_size

```cpp
L.max_size();
```

理论最大容量。

---

# 九、链表专属函数

## reverse

翻转链表

```cpp
L.reverse();
```

示例：

```text
1 2 3 4
```

↓

```text
4 3 2 1
```

---

## sort

链表排序

```cpp
L.sort();
```

示例：

```text
4 2 1 3
```

↓

```text
1 2 3 4
```

注意：

```cpp
sort(L.begin(),L.end());
```

错误。

必须使用：

```cpp
L.sort();
```

---

## unique

去除连续重复元素

```cpp
L.unique();
```

示例：

```text
1 1 2 2 3 3
```

↓

```text
1 2 3
```

---

## merge

合并两个有序链表

```cpp
L1.merge(L2);
```

示例：

```text
L1:
1 3 5

L2:
2 4 6
```

↓

```text
1 2 3 4 5 6
```

---

## splice

链表拼接

```cpp
L1.splice(L1.end(),L2);
```

作用：

```text
把L2整体移动到L1尾部
```

---

# 十、时间复杂度总结

| 操作         | 时间复杂度    |
| ---------- | -------- |
| push_back  | O(1)     |
| push_front | O(1)     |
| pop_back   | O(1)     |
| pop_front  | O(1)     |
| insert     | O(1)     |
| erase      | O(1)     |
| front      | O(1)     |
| back       | O(1)     |
| 查找元素       | O(n)     |
| reverse    | O(n)     |
| sort       | O(nlogn) |

---

# 十一、常见错误

## 错误1

```cpp
L[2];
```

错误。

---

## 错误2

```cpp
L.at(2);
```

错误。

---

## 错误3

```cpp
sort(L.begin(),L.end());
```

错误。

---

## 错误4

```cpp
auto it=L.end();

cout<<*it;
```

错误。

end() 指向尾后位置。

---

# 十二、蓝桥杯中的使用场景

适合：

* 模拟双向链表
* LRU缓存
* 编辑器光标移动
* 浏览器历史记录

不适合：

* 高频随机访问
* 下标操作

比赛中大多数情况：

```cpp
vector
```

比

```cpp
list
```

更常见。

---

# 十三、学习路线

```text
vector
 ↓
string
 ↓
pair
 ↓
queue
 ↓
stack
 ↓
priority_queue
 ↓
set
 ↓
map
 ↓
list
```

---

# 十四、总结

list 的本质是：

```text
双向链表
```

核心特点：

✔ 头尾插入删除快

✔ 中间插入删除快

✔ 支持双向遍历

✔ 不支持随机访问

✔ STL链表容器代表

掌握 list 的关键：

* 理解双向链表原理
* 熟练使用迭代器
* 掌握 reverse、sort、unique、merge、splice
* 理解与 vector 的区别

这是学习 STL 容器体系的重要组成部分。
