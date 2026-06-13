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

	//opreator= 赋值
	deque<int>d2;
	d2 = d1;
	printDeque(d2);

	//assign赋值
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);
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
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
100 100 100 100 100 100 100 100 100 100
*/
