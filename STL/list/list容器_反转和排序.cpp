#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//list容器的反转和排序
void test01()
{
	//反转
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);

	cout << "反转前: " << endl;
	printList(L1);

	//反转后
	cout << "反转后: " << endl;
	L1.reverse();
	printList(L1);
} 

bool myCompare(int v1, int v2)
{
	//降序 就让第一个数>第二个数
	return v1 > v2;
}

//排序
void test02()
{
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);
	cout << "排序前: " << endl;
	printList(L1);

	L1.sort();
	cout << "升序排序后: " << endl;
	printList(L1);

	L1.sort(myCompare);
	cout << "降序排序后: " << endl;
	printList(L1);
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}

/*
结果展示
反转前:
20 10 50 40 30
反转后:
30 40 50 10 20
排序前:
20 10 50 40 30
升序排序后:
10 20 30 40 50
降序排序后:
50 40 30 20 10
*/
