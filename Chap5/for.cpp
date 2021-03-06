/*************************************************************************
	> File Name: for.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月03日 星期二 08时51分25秒
 ************************************************************************/

/*范围for循环和与之等价的传统for循环*/

vector<int> v = {0,1,2,3,4,5,6,7,8,9};

	for (auto &r : v)
		r*=2;

/* 等价 */

	for(auto beg = v.begin(),end=v.end();beg!=end;++beg)
	{	
		auto &r = *beg;
		r *= 2;
	}
	
强调不能通过范围ofr语句增加vector对象（或其它容器）的元素了。
在范围for语句中预存了end()的值，一但添加了元素，end函数的值就变得无效了。

