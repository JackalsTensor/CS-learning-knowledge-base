# 🚀 C++函数部分知识总结（蓝桥杯 / 竞赛 / 考研通用）

本笔记整理 C++ 函数部分核心知识点 + 常用模板 + 竞赛技巧，适用于：
- 蓝桥杯备赛
- 数据结构与算法学习
- C++基础巩固

![概览图](C++/函数/images/C++函数.png)

# 一、函数基础结构

## 1️⃣ 函数定义

```cpp
返回类型 函数名(参数列表) {
    函数体
    return 返回值;
}
````

示例：

```cpp
int add(int a, int b) {
    return a + b;
}
```

---

## 2️⃣ 函数调用

```cpp
int x = add(1, 2);
```

---

## 3️⃣ 声明与定义分离

```cpp
int add(int, int); // 声明

int main() {
    cout << add(1,2);
}

int add(int a, int b) {
    return a + b;
}
```

---

# 二、参数传递（重点）

## 1️⃣ 值传递

```cpp
void f(int x) {
    x++;
}
```

👉 不影响原变量

---

## 2️⃣ 引用传递（重点🔥）

```cpp
void f(int &x) {
    x++;
}
```

👉 会修改原变量

---

## 3️⃣ 指针传递

```cpp
void f(int *x) {
    (*x)++;
}
```

---

## 📌 对比总结

| 类型   | 是否修改原值 | 使用场景     |
| ---- | ------ | -------- |
| 值传递  | ❌      | 小数据      |
| 引用传递 | ✅      | 排序/交换/优化 |
| 指针传递 | ✅      | 底层操作     |

---

# 三、函数特性（C++扩展）

## 1️⃣ 函数重载

```cpp
int add(int a, int b);
double add(double a, double b);
```

---

## 2️⃣ 默认参数

```cpp
void print(int x = 10) {
    cout << x;
}
```

---

## 3️⃣ inline函数

```cpp
inline int add(int a, int b) {
    return a + b;
}
```

---

# 四、递归函数（核心🔥）

## 1️⃣ 递归结构

```cpp
if (终止条件) return;
递归调用;
```

---

## 2️⃣ 阶乘

```cpp
int fact(int n) {
    if (n == 1) return 1;
    return n * fact(n - 1);
}
```

---

## 3️⃣ 斐波那契

```cpp
int fib(int n) {
    if (n <= 2) return 1;
    return fib(n - 1) + fib(n - 2);
}
```

---

## 📌 递归三要素

* 终止条件
* 子问题拆分
* 返回合并

---

# 五、数组与函数

## 1️⃣ 数组作为参数

```cpp
void print(int a[], int n);
```

👉 本质是指针传递

---

## 2️⃣ 遍历函数

```cpp
void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
```

---

# 六、常用工具函数（竞赛必备）

## 1️⃣ swap函数

```cpp
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
```

---

## 2️⃣ gcd（最大公约数）

```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

---

## 3️⃣ 快速幂（重点🔥）

```cpp
long long fastPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
```

---

# 七、DFS / 回溯模板（核心🔥🔥）

## 1️⃣ 全排列

```cpp
void dfs(int step) {
    if (step == n) return;

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            dfs(step + 1);
            used[i] = false;
        }
    }
}
```

---

## 2️⃣ 子集问题

```cpp
void dfs(int i) {
    if (i == n) return;

    dfs(i + 1); // 选
    dfs(i + 1); // 不选
}
```

---

## 3️⃣ 迷宫DFS

```cpp
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        dfs(nx, ny);
    }
}
```

---

# 八、函数设计思想（竞赛核心）

## ⭐ 常见模块化函数

* solve() → 主逻辑
* check() → 判断合法性
* dfs() → 搜索
* calc() → 计算
* isValid() → 判断条件

---

# 九、蓝桥杯函数核心总结

## 🔥 必须掌握

* 函数定义与调用
* 引用传递
* 递归
* DFS / 回溯
* gcd / 快速幂

---

## ⚡ 提分关键

* 模块化写代码
* 函数拆分思维
* 搜索类函数熟练度

---

# 🎯 一句话总结

👉 C++函数 = “拆解问题 + 封装逻辑 + 递归搜索 + 模块化思维”

