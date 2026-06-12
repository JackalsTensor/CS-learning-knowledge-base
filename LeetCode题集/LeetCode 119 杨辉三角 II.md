# LeetCode 119 杨辉三角 II

## 题目描述

给定一个非负索引 `rowIndex`，返回杨辉三角的第 `rowIndex` 行。

例如：

```text
输入：
rowIndex = 3

输出：
[1,3,3,1]
```

杨辉三角规律：

```text
        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1
```

其中：

* 每行首尾元素均为 `1`
* 中间元素等于上一行相邻两个元素之和

即：

```text
当前元素 = 左上元素 + 右上元素
```

---

## 涉及知识点

### STL 容器

```cpp
vector<int>
vector<vector<int>>
```

### 常用函数

```cpp
push_back()
size()
```

### 基础语法

```cpp
for循环
双层循环
下标访问 []
```

### 算法思想

```text
递推
模拟
二维数据存储
```

---

## 解题思路

本题可以直接复用 LeetCode 118《杨辉三角》的思路。

### 第一步

创建二维数组保存整个杨辉三角：

```cpp
vector<vector<int>> ans;
```

---

### 第二步

逐行生成：

```text
第0行
1

第1行
1 1

第2行
1 2 1

第3行
1 3 3 1
```

每行遵循：

```text
开头放1

中间元素：
上一行相邻元素之和

结尾放1
```

---

### 第三步

生成到第 rowIndex 行后：

```cpp
return ans[rowIndex];
```

即可得到答案。

---

## 示例推导

当：

```cpp
rowIndex = 3
```

生成过程：

```text
第0行
1

第1行
1 1

第2行
1 2 1

第3行
1 3 3 1
```

返回：

```text
1 3 3 1
```

---

## 代码实现（学习版）

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int rowIndex;
    cin >> rowIndex;

    vector<vector<int>> ans;

    for (int i = 0; i <= rowIndex; i++)
    {
        vector<int> row;

        row.push_back(1);

        if (i > 0)
        {
            vector<int> pre = ans[i - 1];

            for (int j = 0; j < pre.size() - 1; j++)
            {
                row.push_back(pre[j] + pre[j + 1]);
            }

            row.push_back(1);
        }

        ans.push_back(row);
    }

    vector<int> target = ans[rowIndex];

    for (int x : target)
    {
        cout << x << " ";
    }

    return 0;
}
```

---

## 复杂度分析

### 时间复杂度

```text
O(n²)
```

需要生成前 `rowIndex+1` 行。

---

### 空间复杂度

```text
O(n²)
```

保存了整个杨辉三角。

---

## 收获总结

通过本题可以掌握：

* vector 的创建与使用
* vector 嵌套（二维 vector）
* push_back()
* size()
* 下标访问
* 范围 for 循环
* 双层循环
* 递推思想
* 利用上一状态构造下一状态

---

## 学习建议

推荐刷题顺序：

```text
118. 杨辉三角
↓
119. 杨辉三角 II
↓
88. 合并两个有序数组
↓
27. 移除元素
↓
283. 移动零
```

适合作为 STL vector 专题入门练习题。

---

## 标签

```text
#C++
#STL
#Vector
#LeetCode
#递推
#模拟
#蓝桥杯基础
#算法入门
```
