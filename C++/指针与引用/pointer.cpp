/*
==================================================
            C++ Pointer Template
==================================================
*/

#include <iostream>
#include <string>

using namespace std;

/*
==================================================
            指针传参交换函数
==================================================
*/
void swapNum(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
==================================================
            结构体
==================================================
*/
struct Student
{
    string name;
    int age;
};

int main()
{
    cout << "=============================\n";
    cout << "1. 指针定义\n";
    cout << "=============================\n";

    int a = 10;

    int *p = &a;

    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;


    cout << "\n=============================\n";
    cout << "2. 通过指针修改变量\n";
    cout << "=============================\n";

    *p = 100;

    cout << "a = " << a << endl;


    cout << "\n=============================\n";
    cout << "3. nullptr\n";
    cout << "=============================\n";

    int *nullPtr = nullptr;

    cout << "nullptr创建成功\n";


    cout << "\n=============================\n";
    cout << "4. 指针与数组\n";
    cout << "=============================\n";

    int arr[5] = {1,2,3,4,5};

    cout << "数组名地址: "
         << arr
         << endl;

    cout << "首元素: "
         << *arr
         << endl;

    cout << "第二个元素: "
         << *(arr + 1)
         << endl;


    cout << "\n=============================\n";
    cout << "5. 指针遍历数组\n";
    cout << "=============================\n";

    for(int *ptr = arr; ptr < arr + 5; ptr++)
    {
        cout << *ptr << " ";
    }

    cout << endl;


    cout << "\n=============================\n";
    cout << "6. 指针运算\n";
    cout << "=============================\n";

    int *ptr = arr;

    cout << *ptr << endl;

    ptr++;

    cout << *ptr << endl;


    cout << "\n=============================\n";
    cout << "7. 指针传参\n";
    cout << "=============================\n";

    int x = 10;
    int y = 20;

    cout << "交换前: ";
    cout << x << " " << y << endl;

    swapNum(&x, &y);

    cout << "交换后: ";
    cout << x << " " << y << endl;


    cout << "\n=============================\n";
    cout << "8. 动态内存申请\n";
    cout << "=============================\n";

    int *num = new int;

    *num = 500;

    cout << *num << endl;

    delete num;


    cout << "\n=============================\n";
    cout << "9. 动态数组\n";
    cout << "=============================\n";

    int n = 5;

    int *dynamicArr = new int[n];

    for(int i = 0; i < n; i++)
    {
        dynamicArr[i] = i + 1;
    }

    for(int i = 0; i < n; i++)
    {
        cout << dynamicArr[i] << " ";
    }

    cout << endl;

    delete[] dynamicArr;


    cout << "\n=============================\n";
    cout << "10. 二级指针\n";
    cout << "=============================\n";

    int value = 88;

    int *p1 = &value;

    int **p2 = &p1;

    cout << value << endl;
    cout << *p1 << endl;
    cout << **p2 << endl;


    cout << "\n=============================\n";
    cout << "11. 结构体指针\n";
    cout << "=============================\n";

    Student stu =
    {
        "Tom",
        18
    };

    Student *sp = &stu;

    cout << sp->name << endl;
    cout << sp->age << endl;


    cout << "\n=============================\n";
    cout << "12. 指针总结\n";
    cout << "=============================\n";

    cout << "p      -> 地址\n";
    cout << "*p     -> 地址对应的数据\n";
    cout << "&a     -> 变量地址\n";
    cout << "arr    -> 首元素地址\n";
    cout << "nullptr-> 空指针\n";

    return 0;
}
