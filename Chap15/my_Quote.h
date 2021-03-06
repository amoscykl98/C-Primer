/*************************************************************************
	> File Name: 15-3.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月21日 星期六 13时42分13秒
 ************************************************************************/

using namespace std;

/* 定义自己的Quote类和print_total函数 */
class Quote 
{
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price) : 
					bookNo(book),price(sales_price) {}
		std::string isbn() const { return bookNo; }
		//返回给定数量的书籍的销售总额,派生类改写并使用不用的折扣计算方法
		virtual double net_price(std::size_t n) const { return n*price; }
		virtual ~Quote() = default;			//对析构函数进行动态绑定
	private:
		std::string bookNo;					//书籍的ISBN编号
	protected:
		double price = 0.0;					//代表普通状况下不打折的价格
};

double print_total(ostream &os, const Quote &item, size_t n)
{
	//根据传入item形参的对象类型调用Quote::net_price
	//或者Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}

