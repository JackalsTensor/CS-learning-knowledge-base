# memset 使用要领

## 1. memset 是什么？

`memset` 是 C/C++ 中用于**按照字节（byte）批量设置一段内存**的函数。

头文件：

```cpp
#include <cstring>
```

基本形式：

```cpp
memset(目标地址, 填充值, 字节数);
```

例如：

```cpp
int arr[5] = {1, 2, 3, 4, 5};

memset(arr, 0, 20);
```

因为：

```cpp
int arr[5]
```

一共有：

```text
5 × sizeof(int)
```

个字节。

通常 `int` 占 4 字节，因此：

```text
5 × 4 = 20 字节
```

所以这条语句会把 `arr` 的全部 20 个字节都设置为 `0`。

最终：

```text
0 0 0 0 0
```

---

# 2. memset 的基本原理

理解 `memset` 最重要的一句话：

> **memset 不关心数组中存储的是什么类型，它只是一字节一字节地修改内存。**

例如：

```cpp
char arr[] = "hello world";

memset(arr, 'x', 5);
```

字符 `'x'` 的 ASCII 值是：

```text
120
```

因此 `memset` 会把前 5 个字节全部设置成：

```text
'x' 'x' 'x' 'x' 'x'
```

原来的：

```text
hello world
```

变成：

```text
xxxxx world
```

这里可以理解为：

```text
内存：

h e l l o   w o r l d \0
↓ ↓ ↓ ↓ ↓
x x x x x
```

所以：

```cpp
cout << arr;
```

输出：

```text
xxxxx world
```

---

# 3. 为什么 memset 能操作不同类型的数组？

因为 `memset` 操作的不是“数组元素”，而是**内存中的字节**。

例如：

```cpp
char arr[5];
```

一个 `char` 通常占 1 字节。

而：

```cpp
int arr[5];
```

一个 `int` 通常占 4 字节。

`memset` 不需要知道这些元素是什么类型，它只需要：

```text
起始地址 + 要修改多少个字节
```

例如：

```cpp
memset(arr, 0, 20);
```

意思不是：

> 把 20 个元素设置为 0

而是：

> 从 `arr` 开始，把连续的 20 个字节全部设置成 `0`。

---

# 4. memset 的第三个参数为什么是“字节数”？

例如：

```cpp
int arr[5];
```

假设：

```cpp
sizeof(int) == 4
```

那么：

```cpp
sizeof(arr)
```

就是：

```text
5 × 4 = 20
```

因此推荐这样写：

```cpp
memset(arr, 0, sizeof(arr));
```

而不是：

```cpp
memset(arr, 0, 20);
```

这样更加安全。

完整代码：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    memset(arr, 0, sizeof(arr));

    for (int e : arr)
    {
        cout << e << " ";
    }

    return 0;
}
```

输出：

```text
0 0 0 0 0
```

---

# 5. 最容易踩坑的地方：整数数组

这是使用 `memset` 时最重要的知识点。

很多初学者会误以为：

```cpp
int arr[5];

memset(arr, 1, sizeof(arr));
```

等价于：

```cpp
arr[0] = 1;
arr[1] = 1;
arr[2] = 1;
arr[3] = 1;
arr[4] = 1;
```

**实际上不是。**

因为 `memset` 是按照“字节”进行填充的。

假设一个 `int` 占 4 字节：

```cpp
memset(arr, 1, sizeof(arr));
```

每个字节都会变成：

```text
00000001
```

于是一个 `int` 的 4 个字节实际上是：

```text
01 01 01 01
```

换算成整数：

```text
0x01010101
```

十进制是：

```text
16843009
```

所以：

```cpp
int arr[5];

memset(arr, 1, sizeof(arr));
```

得到的不是：

```text
1 1 1 1 1
```

而通常是：

```text
16843009 16843009 16843009 16843009 16843009
```

---

# 6. 为什么 memset(arr, 0, ...) 可以正确得到整数 0？

因为：

```cpp
memset(arr, 0, sizeof(arr));
```

会让每一个字节变成：

```text
00
```

因此一个 `int` 的所有字节都是：

```text
00 00 00 00
```

这表示整数：

```text
0
```

所以：

```cpp
memset(arr, 0, sizeof(arr));
```

可以非常方便地把整数数组全部初始化为 0。

---

# 7. memset(arr, -1, ...) 为什么经常用于初始化？

竞赛和算法题中经常看到：

```cpp
int arr[100];

memset(arr, -1, sizeof(arr));
```

因为 `-1` 转换成一个字节后通常是：

```text
FF
```

所以一个 `int` 会变成：

```text
FF FF FF FF
```

在现代常见的补码整数表示中，这就是：

```text
-1
```

因此：

```cpp
memset(arr, -1, sizeof(arr));
```

通常可以得到：

```text
-1 -1 -1 -1 ...
```

这也是算法竞赛中非常常见的写法。

---

# 8. 整数数组使用 memset 的规律

对于 `int` 数组，可以重点记住：

```cpp
memset(arr, 0, sizeof(arr));
```

得到：

```text
0 0 0 0 ...
```

以及：

```cpp
memset(arr, -1, sizeof(arr));
```

通常得到：

```text
-1 -1 -1 -1 ...
```

但是：

```cpp
memset(arr, 1, sizeof(arr));
```

**不是**：

```text
1 1 1 1 ...
```

而通常是：

```text
16843009 16843009 ...
```

同理：

```cpp
memset(arr, 2, sizeof(arr));
```

也不是：

```text
2 2 2 2 ...
```

而通常会得到：

```text
0x02020202
```

即：

```text
33686018
```

---

# 9. 如果想把 int 数组全部设置为某个整数怎么办？

假设想：

```cpp
int arr[5];

arr[0] = 100;
arr[1] = 100;
arr[2] = 100;
arr[3] = 100;
arr[4] = 100;
```

不要写：

```cpp
memset(arr, 100, sizeof(arr)); // ❌
```

应该使用循环：

```cpp
for (int &x : arr)
{
    x = 100;
}
```

或者：

```cpp
fill(arr, arr + 5, 100);
```

`fill` 才是真正意义上的“按照元素进行填充”。

---

# 10. memset 和 fill 的区别

### memset

按照：

```text
字节
```

进行填充。

```cpp
memset(arr, 0, sizeof(arr));
```

适合：

```text
全部设置为 0
全部设置为 -1（常见整数场景）
字符数组批量设置字符
清空一段原始内存
```

### fill

按照：

```text
数组元素
```

进行填充。

```cpp
fill(arr, arr + 5, 100);
```

真正表示：

```text
arr[0] = 100
arr[1] = 100
arr[2] = 100
arr[3] = 100
arr[4] = 100
```

所以：

> **memset 是按字节填充，fill 是按元素填充。**

---

# 11. 字符数组为什么特别适合 memset？

因为：

```cpp
char
```

本身就是 1 字节。

例如：

```cpp
char arr[10];

memset(arr, 'a', sizeof(arr));
```

会得到：

```text
a a a a a a a a a a
```

这里不会出现整数数组那种问题。

因为：

```text
一个 char = 一个字节
```

`memset` 设置一个字节为 `'a'`，正好就是设置一个 `char` 为 `'a'`。

---

# 12. memset 也可以用来清空字符数组

例如：

```cpp
char arr[100];

memset(arr, 0, sizeof(arr));
```

所有字节都会变成：

```text
\0
```

因此可以把它理解成：

> 把字符数组的内容全部清零。

例如：

```cpp
char arr[] = "hello";

memset(arr, 0, sizeof(arr));

cout << arr;
```

此时 `arr` 的第一个字符就是 `'\0'`，所以作为 C 风格字符串输出时，相当于空字符串。

---

# 13. 第三个参数一定要注意

例如：

```cpp
int arr[5];

memset(arr, 0, 5);
```

这里的 `5` 表示：

```text
5 个字节
```

**不是 5 个 int。**

如果 `int` 是 4 字节，那么只会修改：

```text
5 / 4 ≈ 1 个完整 int + 1 个字节
```

这可能导致数据错误。

因此对于整个数组，推荐：

```cpp
memset(arr, 0, sizeof(arr));
```

---

# 14. 一句话理解 memset

可以把：

```cpp
memset(arr, value, n);
```

理解成：

> 从 `arr` 指向的内存开始，连续 `n` 个字节，每个字节都写成 `value`。

例如：

```cpp
memset(arr, 0, sizeof(arr));
```

相当于：

```text
内存：
00 00 00 00 00 00 00 00 ...
```

而：

```cpp
memset(arr, 1, sizeof(arr));
```

相当于：

```text
01 01 01 01 01 01 01 01 ...
```

不是：

```text
00 00 00 01 00 00 00 01 ...
```

这就是为什么整数数组使用 `memset` 时需要特别小心。

---

# 15. 最终记忆表

| 写法                              | 含义            | 常见结果                |
| ------------------------------- | ------------- | ------------------- |
| `memset(arr, 0, sizeof(arr))`   | 所有字节设为 0      | `int` 数组全部为 0       |
| `memset(arr, -1, sizeof(arr))`  | 所有字节设为 `0xFF` | 常见 `int` 中全部为 -1    |
| `memset(arr, 1, sizeof(arr))`   | 所有字节设为 `0x01` | `int` 通常变成 16843009 |
| `memset(arr, 'x', sizeof(arr))` | 所有字节设为字符 `x`  | 字符数组变成 `xxxxx...`   |
| `fill(arr, arr+n, 100)`         | 所有元素设为 100    | `100 100 100...`    |

---

# 16. 核心结论

学习 `memset` 最重要的是记住下面三句话：

### ① memset 是按照字节操作的

```cpp
memset(地址, 值, 字节数);
```

### ② 字符数组非常适合使用 memset

因为：

```text
char = 1 字节
```

所以：

```cpp
memset(arr, 'x', sizeof(arr));
```

可以直接把每个字符设置为 `x`。

### ③ 整数数组不要把 memset 当成 fill

```cpp
memset(arr, 0, sizeof(arr));   // ✅
memset(arr, -1, sizeof(arr));  // ✅ 常见用法

memset(arr, 100, sizeof(arr)); // ❌ 不等于全部设置成100
```

如果想让整数数组的每个**元素**变成指定数字：

```cpp
fill(arr, arr + n, value);
```

或者使用循环：

```cpp
for (int &x : arr)
{
    x = value;
}
```

**最终记忆：**

```text
memset → 按字节
fill   → 按元素
```

这就是 `memset` 最核心的区别。
