#include <string>
#include <iostream>

class Quote {
public:
	Quote() = default;
	Quote(const std::string& book, double salesPrice) : bookNo(book), price(salesPrice) {}

	std::string isbn() const { return bookNo; }
	virtual double netPrice(std::size_t n) const { return n * price; }
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};