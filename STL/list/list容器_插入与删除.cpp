#include <iostream>
#include <list>
using namespace std;

//list容器的插入和删除
/*
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos, elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos, n, elem);//在pos位置插入n个elem数据，无返回值。
insert(pos, beg, end);//在pos位置插入[beg, end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg, end);//删除[beg, end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//赋值
void test01()
{
	list<int>L;

	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);

	//头插
	L.push_front(100);
	L.push_front(100);
	L.push_front(100);
	printList(L);  //100 100 100 10 20 30

	//尾删
	L.pop_back();
	printList(L);  //100 100 100 10 20

	//头删
	L.pop_front();
	printList(L);  //100 100 10 20

	//insert插入
	L.insert(L.begin(), 1000);
	printList(L);  //1000 100 100 10 20

	//insert插入(plus版)
	list<int>::iterator it = L.begin();
	L.insert(++it, 2000);
	printList(L);  //1000 2000 100 100 10 20

	//删除
	it = L.begin();
	L.erase(it);
	printList(L);  //2000 100 100 10 20

	//移除
	L.remove(2000);
	printList(L);  //100 100 10 20
} 

int main()
{
	test01();
	system("pause");
	return 0;
}

/*
结果展示
100 100 100 10 20 30                                                                                                    
100 100 100 10 20                                                                                                       
100 100 10 20                                                                                                           
1000 100 100 10 20                                                                                                      
1000 2000 100 100 10 20                                                                                                 
2000 100 100 10 20                                                                                                      
100 100 10 20
*/
