# `memcpy` —— 内存复制

`memcpy` 是 C/C++ 中用于**按字节复制一段内存数据**的函数，定义在：

```cpp
#include <cstring>
```

---

## 1. 基本作用

`memcpy` 可以把一块内存中的数据，复制到另一块内存中。

例如：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {0};

    memcpy(b, a, 10 * sizeof(int));

    for(int e : b)
    {
        cout << e << " ";
    }

    return 0;
}
```

输出：

```text
1 2 3 4 5 6 7 8 9 10
```

这里：

```cpp
memcpy(b, a, 10 * sizeof(int));
```

表示：

> 将 `a` 中前 `10 * sizeof(int)` 个字节的数据复制到 `b` 中。

---

## 2. 基本语法

```cpp
memcpy(目标地址, 源地址, 复制的字节数);
```

完整形式：

```cpp
memcpy(void* dest, const void* src, size_t count);
```

三个参数：

| 参数      | 含义      |
| ------- | ------- |
| `dest`  | 目标内存地址  |
| `src`   | 源内存地址   |
| `count` | 要复制的字节数 |

例如：

```cpp
memcpy(b, a, 10 * sizeof(int));
```

对应：

```text
        源地址             目标地址
          ↓                  ↓
       ┌────────┐        ┌────────┐
a  →   │ 1 2 3  │  ───→   │ 1 2 3  │  ← b
       └────────┘        └────────┘

              复制指定数量的字节
```

---

## 3. 为什么要使用 `sizeof`

`memcpy` 的第三个参数单位是：

> **字节（byte）**

而不是元素个数。

例如：

```cpp
int a[10];
```

假设：

```cpp
sizeof(int) == 4
```

那么：

```cpp
10 * sizeof(int)
```

就是：

```text
10 × 4 = 40 字节
```

所以：

```cpp
memcpy(b, a, 10 * sizeof(int));
```

就是复制整个 `a` 数组。

### 推荐写法

如果复制整个数组，可以写：

```cpp
memcpy(b, a, sizeof(a));
```

因为：

```cpp
sizeof(a)
```

就是整个数组占用的字节数。

因此：

```cpp
memcpy(b, a, sizeof(a));
```

等价于：

```cpp
memcpy(b, a, 10 * sizeof(int));
```

---

## 4. 复制数组的一部分

`memcpy` 不一定要复制整个数组。

例如：

```cpp
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int b[10] = {0};

memcpy(b, a, 5 * sizeof(int));
```

只复制前 5 个 `int`：

```text
a:
1 2 3 4 5 6 7 8 9 10

      ↓ memcpy

b:
1 2 3 4 5 0 0 0 0 0
```

---

## 5. 复制字符串

`memcpy` 也可以复制字符数组：

```cpp
char a[] = "Hello";
char b[10];

memcpy(b, a, sizeof(a));

cout << b;
```

输出：

```text
Hello
```

这里：

```cpp
sizeof(a)
```

包含字符串末尾的 `'\0'`。

即：

```text
H e l l o \0
```

---

## 6. `memcpy` 可以复制结构体

例如：

```cpp
struct Student
{
    int age;
    double score;
};

Student a = {18, 95.5};
Student b;

memcpy(&b, &a, sizeof(Student));
```

此时：

```cpp
b.age
b.score
```

都会得到 `a` 中对应的数据。

也可以写成：

```cpp
memcpy(&b, &a, sizeof(a));
```

---

## 7. `memcpy` 的本质

`memcpy` **不关心数据是什么类型**。

它只负责：

> 从源地址开始，复制指定数量的字节到目标地址。

例如：

```cpp
int a = 123;
int b;

memcpy(&b, &a, sizeof(int));
```

实际上就是把 `a` 在内存中的二进制数据复制给 `b`。

可以理解成：

```text
a 的内存
┌────┬────┬────┬────┐
│字节│字节│字节│字节│
└────┴────┴────┴────┘
          ↓
       memcpy
          ↓
┌────┬────┬────┬────┐
│字节│字节│字节│字节│
└────┴────┴────┴────┘
b 的内存
```

所以 `memcpy` 本质上属于**内存操作函数**。

---

## 8. `memcpy` 和赋值的区别

数组不能直接使用 `=` 进行整体复制：

```cpp
int a[5] = {1,2,3,4,5};
int b[5];

b = a;  // ❌ 错误
```

可以使用：

```cpp
memcpy(b, a, sizeof(a));
```

或者使用 C++ 的：

```cpp
copy(a, a + 5, b);
```

---

## 9. `memcpy` 和 `memset` 的区别

这两个函数非常容易混淆。

### `memcpy`

作用：

> **复制另一块内存中的数据**

```cpp
memcpy(b, a, sizeof(a));
```

相当于：

```text
a ───────→ b
复制数据
```

### `memset`

作用：

> **用指定的一个字节值填充内存**

```cpp
memset(b, 0, sizeof(b));
```

相当于：

```text
0 0 0 0 0 ...
```

简单记忆：

```text
memcpy → copy → 复制内存

memset → set  → 设置内存
```

---

## 10. 一个非常重要的注意事项

`memcpy` 的第三个参数是**字节数**。

例如：

```cpp
int a[10];
int b[10];

memcpy(b, a, 10);
```

这不是复制 10 个 `int`！

而是只复制：

```text
10 个字节
```

如果一个 `int` 占 4 字节，那么实际上只复制了：

```text
10 / 4 = 2.5 个 int
```

这通常不是我们想要的。

正确写法：

```cpp
memcpy(b, a, 10 * sizeof(int));
```

或者：

```cpp
memcpy(b, a, sizeof(a));
```

---

## 11. 目标空间必须足够大

例如：

```cpp
int a[10];
int b[5];

memcpy(b, a, sizeof(a));  // ❌ 危险
```

因为：

```text
a → 需要复制 40 字节

b → 只有 20 字节
```

会导致超出 `b` 的内存范围，产生**未定义行为**。

因此必须保证：

```text
目标空间 ≥ 复制的数据大小
```

---

## 12. `memcpy` 不能处理内存重叠

例如：

```cpp
memcpy(a + 1, a, 5 * sizeof(int));
```

如果源区域和目标区域发生重叠，使用 `memcpy` 是**未定义行为**。

这种情况下应该使用：

```cpp
memmove()
```

例如：

```cpp
memmove(a + 1, a, 5 * sizeof(int));
```

简单记忆：

```text
memcpy  → 内存区域不能重叠
memmove → 可以处理内存重叠
```

---

## 13. 常见用法总结

### 复制整个数组

```cpp
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int b[10];

memcpy(b, a, sizeof(a));
```

### 复制数组的一部分

```cpp
memcpy(b, a, 5 * sizeof(int));
```

### 复制结构体

```cpp
memcpy(&b, &a, sizeof(a));
```

### 复制字符数组

```cpp
char a[] = "Hello";
char b[10];

memcpy(b, a, sizeof(a));
```

---

## 14. 一句话理解

> **`memcpy` = 从源地址开始，把指定数量的“字节”原封不动地复制到目标地址。**

最常见的数组写法：

```cpp
memcpy(目标数组, 源数组, sizeof(源数组));
```

例如：

```cpp
memcpy(b, a, sizeof(a));
```

---

## 15. 记忆口诀

```text
memcpy：
    copy → 复制
    参数第三个 → 字节数
    不关心数据类型
    目标空间必须足够
    源和目标不能重叠

memset：
    set → 填充
    按字节填充
```

### 核心代码

```cpp
#include <cstring>

memcpy(目标地址, 源地址, 字节数);
```

例如：

```cpp
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int b[10];

memcpy(b, a, sizeof(a));
```
