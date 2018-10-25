#pragma once
#include "Quote.h"
class Bulk_quote :
	public Quote
{
public:
	Bulk_quote* clone() const & { return new Bulk_quote(*this);}
	Bulk_quote* clone() const && {return new Bulk_quote(std::move(*this));}

	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	virtual double net_price(std::size_t n) const override;
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

