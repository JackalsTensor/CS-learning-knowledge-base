#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		*it != 100;
		cout << *it << " ";
	}
	cout << endl;
}

//deque容器赋值操作
void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty())
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
		cout << "d1的大小为" << d1.size() << endl;
	}

	//重新指定大小
	d1.resize(15, 1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
} 


int main()
{
	test01();
	system("pause");
	return 0;
}

/*
结果展示
0 1 2 3 4 5 6 7 8 9
d1不为空
d1的大小为10
0 1 2 3 4 5 6 7 8 9 1 1 1 1 1
0 1 2 3 4
*/
