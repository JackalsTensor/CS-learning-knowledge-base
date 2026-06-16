# 51单片机 LED模块实验

## 实验目标

学习51单片机GPIO（通用输入输出口）的基本使用方法，掌握：

- LED点亮
- LED熄灭
- LED流水灯
- 高低电平控制
- P2端口操作

---

## 实验平台

- 单片机：STC89C52RC
- 开发板：普中A2
- 编译环境：Keil5
- 下载软件：STC-ISP

---

# LED模块简介

LED（Light Emitting Diode）即发光二极管。

开发板上共有8个LED：

```text
D8 D7 D6 D5 D4 D3 D2 D1
●  ●  ●  ●  ●  ●  ●  ●
```

对应关系：

```text
P2.7 P2.6 P2.5 P2.4 P2.3 P2.2 P2.1 P2.0
 D8   D7   D6   D5   D4   D3   D2   D1
```

---

# 工作原理

本开发板采用：

```text
低电平点亮
高电平熄灭
```

即：

| IO状态 | LED状态 |
|---------|---------|
| 0 | 亮 |
| 1 | 灭 |

记忆口诀：

```text
0亮1灭
```

---

# 常用控制代码

## 全亮

```c
P2 = 0x00;
```

二进制：

```text
00000000
```

效果：

```text
● ● ● ● ● ● ● ●
```

---

## 全灭

```c
P2 = 0xFF;
```

二进制：

```text
11111111
```

效果：

```text
○ ○ ○ ○ ○ ○ ○ ○
```

---

## 点亮第一个LED

```c
P2 = 0xFE;
```

二进制：

```text
11111110
```

效果：

```text
○ ○ ○ ○ ○ ○ ○ ●
```

---

## 点亮第二个LED

```c
P2 = 0xFD;
```

二进制：

```text
11111101
```

效果：

```text
○ ○ ○ ○ ○ ○ ● ○
```

---

## 点亮第三个LED

```c
P2 = 0xFB;
```

---

## 点亮第四个LED

```c
P2 = 0xF7;
```

---

## 点亮第五个LED

```c
P2 = 0xEF;
```

---

## 点亮第六个LED

```c
P2 = 0xDF;
```

---

## 点亮第七个LED

```c
P2 = 0xBF;
```

---

## 点亮第八个LED

```c
P2 = 0x7F;
```

---

# 单独控制LED

控制第一个LED：

```c
P2_0 = 0;    // D1亮
P2_0 = 1;    // D1灭
```

控制第二个LED：

```c
P2_1 = 0;    // D2亮
P2_1 = 1;    // D2灭
```

控制第三个LED：

```c
P2_2 = 0;    // D3亮
P2_2 = 1;    // D3灭
```

控制第四个LED：

```c
P2_3 = 0;    // D4亮
P2_3 = 1;    // D4灭
```

---

# 延时函数

为了让LED变化能够被肉眼观察，需要加入延时。

```c
void Delay(unsigned int t)
{
    unsigned int i,j;
    for(i=t;i>0;i--)
        for(j=110;j>0;j--);
}
```

作用：

- 让程序暂停一段时间
- 控制LED闪烁速度

---

# 流水灯实验

## 实验代码

```c
#include <REGX52.H>

void Delay(unsigned int t)
{
    unsigned int i,j;
    for(i=t;i>0;i--)
        for(j=110;j>0;j--);
}

void main()
{
    while(1)
    {
        P2=0xFE;
        Delay(500);

        P2=0xFD;
        Delay(500);

        P2=0xFB;
        Delay(500);

        P2=0xF7;
        Delay(500);

        P2=0xEF;
        Delay(500);

        P2=0xDF;
        Delay(500);

        P2=0xBF;
        Delay(500);

        P2=0x7F;
        Delay(500);
    }
}
```

---

## 实验现象

LED依次点亮：

```text
D1 → D2 → D3 → D4 → D5 → D6 → D7 → D8
```

形成流水灯效果。

---

# 开发流程

每次修改代码后：

```text
编写代码
    ↓
Ctrl + S 保存
    ↓
F7 编译(Build)
    ↓
确认：
0 Error(s)
0 Warning(s)
    ↓
生成HEX文件
    ↓
STC-ISP下载
    ↓
按RESET
    ↓
观察现象
```

---

# 常见问题

## 修改代码后现象没变化

原因：

```text
忘记Build
```

解决：

```text
F7重新编译
重新烧录
```

---

## 下载提示 Checking target MCU...

检查：

- COM口是否正确
- 是否选择CH340串口
- 是否按RESET
- 是否生成HEX文件

---

# 学习收获

通过LED实验掌握：

- GPIO控制
- IO口输出
- 高低电平概念
- 延时函数
- HEX烧录流程
- 单片机开发基本流程

---

# 下一步学习路线

```text
LED
 ↓
独立按键
 ↓
蜂鸣器
 ↓
数码管
 ↓
定时器
 ↓
中断系统
 ↓
LCD1602
 ↓
串口通信
 ↓
DS18B20
 ↓
STM32
```

---

⭐ 本实验是学习51单片机的第一个实验，也是嵌入式开发的起点。
