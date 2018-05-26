/*************************************************************************
	> File Name: 10-11.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 21时31分24秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

inline void output_words(vector<string> &words)
{
	for(auto iter = words.begin(); iter != words.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

bool isShorter(const string &s1,const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
	output_words(words);

	sort(words.begin(),words.end());
	output_words(words);

	auto end_unique = unique(words.begin(),words.end());
	output_words(words);

	words.erase(end_unique,words.end());
	output_words(words);

	stable_sort(words.begin(),words.end(),isShorter);	//按长度排序，长度相同的保持之前的字典排序
	output_words(words);
}

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "打开输入文件失败!" << endl;
		exit(1);
	}

	vector<string> words;
	string word;
	while (in >> word)
		words.push_back(word);

	elimDups(words);

	return 0;
}
