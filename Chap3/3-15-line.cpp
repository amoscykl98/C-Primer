/*************************************************************************
	> File Name: 3-14.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 12时08分29秒
 ************************************************************************/

/* 输入一个字符串，存到vector对象，然后打印出来
 * 此程序输入行*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> vString;
	string s;
	char flag;
	cout << "请输入第一行字符串: " << endl;
	while(getline(cin,s))
	{
		vString.push_back(s);
		cout << "老哥你要继续吗?<y or n>" << endl;
		cin >> flag;
		if(flag == 'y' || flag == 'Y')
			cout << "请输入下一行字符串：" << endl;
		else
			break;
	}
	//cout << vString << endl;     不能直接输出vector对象,应该使用范围for
	for(auto i : vString)
		cout << i << " ";      //不加endl，使在同一行输出，加endl会到下一行输出
	cout << endl;
	return 0;
}

