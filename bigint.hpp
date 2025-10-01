#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>

class bigint {

private:
	void removeZeroes();
	std::string _digits;


public:
	bigint(long n = 0);
	bigint(const char *s);
	bigint(const std::string& s);


	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other) ;

	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>=(const bigint& other) const;
	bool operator<(const bigint& other) const;
	bool operator>(const bigint& other) const;

	bigint operator++(int);
	bigint& operator++();

	bigint operator<<(unsigned int shift) const ;
	bigint operator>>(unsigned int shift) const ;
	bigint& operator>>=(unsigned int shift)  ;
	bigint& operator<<=(unsigned int shift)  ;

	bigint operator<<(const bigint& other) const;
	bigint operator>>(const bigint& other) const;
	bigint& operator<<=(const bigint& other);
	bigint& operator>>=(const bigint& other);

	friend std::ostream& operator<<(std::ostream& os, const bigint& other);

};
