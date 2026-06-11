# LeetCode 118 杨辉三角（Pascal's Triangle）

知识点：

1. vector<int>
2. vector<vector<int>>
3. push_back()
4. 下标访问 []
5. 双层循环
6. 递推思想

核心规律：

杨辉三角每行首尾均为 1。

中间元素由上一行相邻两个元素之和得到：

当前元素 = 上一行左上元素 + 上一行右上元素

例如：

```
1 2 1
```

生成：

```
1 3 3 1
```

因为：

```
3 = 1 + 2
3 = 2 + 1
```

时间复杂度：

O(n²)

空间复杂度：

O(n²)

---

## 代码实现

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int numRows;
    cin >> numRows;

    // 保存整个杨辉三角
    vector<vector<int>> ans;

    // 逐行生成
    for(int i = 0; i < numRows; i++)
    {
        vector<int> row;

        // 每行开头都是1
        row.push_back(1);

        // 从第二行开始处理
        if(i > 0)
        {
            // 获取上一行
            vector<int> pre = ans[i - 1];

            // 计算中间元素
            for(int j = 0; j < pre.size() - 1; j++)
            {
                row.push_back(pre[j] + pre[j + 1]);
            }

            // 每行结尾都是1
            row.push_back(1);
        }

        ans.push_back(row);
    }

    // 输出结果
    for(auto row : ans)
    {
        for(auto x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
```

收获：

* 学会 vector 嵌套
* 学会 push_back()
* 学会二维 vector 访问
* 学会递推思想
* 学会利用上一状态构造下一状态
