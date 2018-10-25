#pragma once
#include <memory>
#include <set>
#include "Quote.h"
#include <iostream>
#include <ostream>

using namespace std;

class Basket
{
public:
	void add_item(const std::shared_ptr<Quote> &sale)
	{
		items.insert(sale);
	}
	double total_receipt(std::ostream&) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs,
						const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
	double print_total(ostream &os, const Quote& item, size_t n) const
	{
		double ret = item.net_price(n);
		os << "ISBN: " << item.isbn()
			<< " # sold: " << "total due: " << ret << endl;
		return ret;
	}
};

