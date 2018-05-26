/*************************************************************************
	> File Name: text-find.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月17日 星期二 12时37分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

/* TextQuery类的定义 */
class QueryResult;				//为了定义函数query的返回类型，这个定义是必须的
class TextQuery {
	public:
		using line_no = std::vector<std::string>::sizetype;	//行号
		TextQuery(std::ifstream &);
		QueryResult query(const std::string &) const;
	private:
		std::shared_ptr<std::vector<std::string>> file;		//输入文件
		//每个单词到它所在的行号的集合的映射
		std::map<std::string,std::shared_ptr<std::std<line_no>>> wm;
}

//TextQuery构造函数
TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string text;
	while (getline(is,text)) {		//对文件中每一行
		file->push_back(text);		//保存此行文本
		int n = file->size() - 1;	//当前行号
		istringstream line(text);	//将行文本分解为单词
		string word;
		while (line >> word) {		//对行中每个单词
			//如果单词不在wm中，以下为下标word在wm中添加一项
			auto &lines = wm[word];	//lines是一个shared_ptr
			if( !lines )			//在我们第一次遇到这个单词时，此指针为空
				lines.reset(new set<line_no>);	//分配一个新的set
			lines->insert(n);		//将此行号插入到set中,因为lines是引用
		}
	}
}

/* QueryResult类的定义 */
class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
	public:
		QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
					:	sought(s), lines(p), file(f) { }
	private:
		std::string sought;			//查询单词
		std::shared_ptr<std::set<line_no>> lines;		//出现的行号
		std::shared_ptr<std::vector<std::string>> file;	//输入文件
}


/* query函数 */
QueryResult
TextQuery::query(const string &sought) const		
{
	//如果未找到sought，返回一个指向此set的指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	//使用find而不是下标运算符来查找单词,避免将单词添加到wm中
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought,nodata,file);	//未找到
	else
		return QueryResult(sought, loc->second, file);		//给QueryResult对象单词，行号，输入文件的参数
}

/* print函数在给定的流上打印给定的QueryResult对象 */
ostream &print(ostream & os, const QueryResult &qr)
{
	//如果找到了单词，打印出现次数和所有出现的位置
	os << qr.sought << " occurs " << qr.line->size() << " " << make_plural(qr.lines->size(),"time","s") << endl;
	//打印单词出现的每一行
	for (auto num : *qr.lines)		//对set中每个单词
		//避免行号从0开始给用户带来的困惑
		os << "\t(line " << num+1 << ") " << *(qr.file->begin + num) << endl;
	return os;
}




/* 函数接受一个指向要处理的文件的ifstream，并与用户交互，打印给定单词的查询结果 */
void runQueries(ifstream &infile)
{
	//infile是一个ifstream，指向要处理的文件
	TextQuery tq(infile);		//保存文件并建立查询map
	//与用户交互:提示用户输入要查找的单词，完成查询并打印结果
	while(true) {
		cout << "enter word to look for, or q to quit: "; 
		string s;
		//若遇到文件尾或用户输入'q'时循环终止
		if (!(cin >> s) || s== "q") 
			break;
		//指向查询结果并打印
		print(cout,tq.query(s)) << endl; 
	}
}
