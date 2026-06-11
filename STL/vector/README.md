# Vector 学习笔记

## 1. 什么是 Vector

`vector` 是 C++ STL（标准模板库）中最常用的顺序容器之一。

它本质上是一个 **动态数组（Dynamic Array）**，能够自动扩容，不需要提前确定数组大小。

头文件：

```cpp
#include <vector>
```

命名空间：

```cpp
using namespace std;
```

---

## 2. Vector 的特点

### 优点

* 支持动态扩容
* 支持随机访问
* 尾部插入效率高
* STL算法兼容性好

### 缺点

* 中间插入删除效率较低
* 扩容时可能发生数据搬迁

---

## 3. 创建 Vector

### 空 Vector

```cpp
vector<int> v;
```

### 指定大小

```cpp
vector<int> v(5);
```

结果：

```text
0 0 0 0 0
```

### 指定大小和初值

```cpp
vector<int> v(5,100);
```

结果：

```text
100 100 100 100 100
```

### 二维 Vector

```cpp
vector<vector<int>> g(3,vector<int>(4,0));
```

---

## 4. 常用操作

### 添加元素

```cpp
v.push_back(10);
```

### 删除最后一个元素

```cpp
v.pop_back();
```

### 获取大小

```cpp
v.size();
```

### 判断是否为空

```cpp
v.empty();
```

### 清空容器

```cpp
v.clear();
```

---

## 5. 元素访问

### 下标访问

```cpp
v[i];
```

### 第一个元素

```cpp
v.front();
```

### 最后一个元素

```cpp
v.back();
```

---

## 6. 遍历方式

### 普通 for

```cpp
for(int i=0;i<v.size();i++)
{
    cout<<v[i]<<" ";
}
```

### 范围 for

```cpp
for(auto x:v)
{
    cout<<x<<" ";
}
```

### 引用遍历

```cpp
for(auto &x:v)
{
    cin>>x;
}
```

---

## 7. 插入与删除

### 指定位置插入

```cpp
v.insert(v.begin()+2,100);
```

### 删除指定位置

```cpp
v.erase(v.begin()+2);
```

### 删除区间

```cpp
v.erase(v.begin()+1,v.begin()+4);
```

---

## 8. 排序

### 升序排序

```cpp
sort(v.begin(),v.end());
```

### 降序排序

```cpp
sort(v.begin(),v.end(),greater<int>());
```

---

## 9. 去重

```cpp
sort(v.begin(),v.end());

v.erase(
    unique(v.begin(),v.end()),
    v.end()
);
```

示例：

```text
1 1 2 2 3 3 4
```

变为：

```text
1 2 3 4
```

---

## 10. 查找

### 顺序查找

```cpp
auto it=find(v.begin(),v.end(),5);
```

### 二分查找

```cpp
sort(v.begin(),v.end());

binary_search(
    v.begin(),
    v.end(),
    5
);
```

---

## 11. 常用算法

### 最大值

```cpp
*max_element(
    v.begin(),
    v.end()
);
```

### 最小值

```cpp
*min_element(
    v.begin(),
    v.end()
);
```

### 求和

```cpp
accumulate(
    v.begin(),
    v.end(),
    0
);
```

### 反转

```cpp
reverse(
    v.begin(),
    v.end()
);
```

---

## 12. 时间复杂度

| 操作        | 时间复杂度    |
| --------- | -------- |
| 随机访问      | O(1)     |
| push_back | O(1)     |
| pop_back  | O(1)     |
| insert    | O(n)     |
| erase     | O(n)     |
| find      | O(n)     |
| sort      | O(nlogn) |

---

## 13. 蓝桥杯高频用法

### 读入数组

```cpp
vector<int> a(n);

for(auto &x:a)
{
    cin>>x;
}
```

### 排序

```cpp
sort(a.begin(),a.end());
```

### 去重

```cpp
a.erase(
    unique(a.begin(),a.end()),
    a.end()
);
```

### 求最大值

```cpp
cout<<*max_element(
    a.begin(),
    a.end()
);
```

---

## 14. 学习总结

Vector 是 STL 中使用频率最高的容器。

必须熟练掌握：

* push_back()
* pop_back()
* size()
* empty()
* clear()
* sort()
* reverse()
* find()
* erase()
* insert()
* unique()
* max_element()
* min_element()
* accumulate()

掌握以上内容后，可以覆盖蓝桥杯、机试、LeetCode 以及考研复试中绝大多数 Vector 相关题目。
