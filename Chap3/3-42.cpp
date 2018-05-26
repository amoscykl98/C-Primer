/*************************************************************************
	> File Name: 3-42.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 16时10分46秒
 ************************************************************************/
/* 将含有整数元素的vector对象拷贝给一个整型数组*/

#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
	const int sz = 10;   
	vector<int> vInt;
	srand((unsigned)time(NULL));

	cout << "vector对象的内容是:" << endl;

	for(int i=0;i!=sz;i++)
	{
		vInt.push_back(rand()%100);
		cout << vInt[i] << " ";
	}
	cout << endl;

	auto it = vInt.cbegin();
	int a[vInt.size()];
	cout << "数组的内容是: " << endl;

	for(auto &val : a)
	{
		val = *it;
		cout << val << " ";
		it++;
	}
	cout << endl;
	return 0;
}
