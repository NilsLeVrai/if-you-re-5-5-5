#include "bigint.hpp"

void bigint::removeZeroes() {
    size_t i = 0;
    while (i < _digits.length() && _digits[i] == '0') {
        ++i;
    }
    if (i == _digits.length()) {
        _digits = "0";
    } else {
        _digits = _digits.substr(i);
    }
}

bigint::bigint(long n) {
	if (n < 0) {
		_digits = "0";
	} else {
		std::stringstream ss;
		ss << n;
		_digits = ss.str();
	}
	removeZeroes();
}

bigint::bigint(const char* s) {
    if (!s || !*s) {
        _digits = "0";
        return;
    }
    std::string temp(s);
    if (temp.find_first_not_of("0123456789") != std::string::npos) {
        _digits = "0";
    } else {
        _digits = temp;
    }
    removeZeroes();
}

bigint::bigint(const std::string& s) {
	if (s.empty()) {
		_digits = "0";
		return ;
	} else {
		for (unsigned int i = 0; i < s.length(); ++i) { // unsigned int ou size_t
			if (!std::isdigit(s[i])) {
				_digits = "0";
				return ;
			}
		}
		_digits = s;
	}
	removeZeroes();
}

std::ostream& operator<<(std::ostream& os, const bigint& other) {
	os << other._digits;
	return os;
}

bigint bigint::operator+(const bigint& other) const {
    std::string result = "";
    int i = _digits.length() - 1;
    int j = other._digits.length() - 1;

    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += _digits[i--] - '0';
        }
        if (j >= 0) {
            sum += other._digits[j--] - '0';
        }
        result += (char)('0' + sum % 10);
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return bigint(result);
}


bool bigint::operator<(const bigint& other) const {
	if (_digits.length() != other._digits.length()) {
		return (_digits.length() < other._digits.length());
	}
	return _digits < other._digits;
}

bool bigint::operator==(const bigint& other) const {
	return (_digits == other._digits);
}

bool bigint::operator!=(const bigint& other) const {
	return !(_digits == other._digits);
}

bool bigint::operator>(const bigint& other) const {
	return (other < *this);
}

bool bigint::operator<=(const bigint& other) const {
	return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
	return !(*this < other);
}

bigint& bigint::operator+=(const bigint& other) {
	*this = *this + other;
	return *this;
}

bigint bigint::operator++(int) {
	bigint temp = *this;
	++(*this);
	return temp;
}

bigint& bigint::operator++() {
	*this = *this + bigint(1L);
	return *this;
}

bigint bigint::operator<<(unsigned int shift) const {
	if (_digits == "0") {
		return (bigint(0L));
	}

	std::string shifted = _digits;
	shifted.append(shift, '0');
	return (bigint(shifted));
}


bigint bigint::operator>>(unsigned int shift) const {
    if (shift >= _digits.length()) {
        return bigint(0L);
    }
    
    std::string shifted = _digits.substr(0, _digits.length() - shift);
    return bigint(shifted);
}

bigint& bigint::operator>>=(unsigned int shift) {
	*this = *this >> shift;
	return *this;
}

bigint& bigint::operator<<=(unsigned int shift) {
	*this = *this << shift;
	return *this;
}

bigint& bigint::operator<<=(const bigint& other) {
	*this = *this << other;
	return *this;
}

bigint& bigint::operator>>=(const bigint& other) {
	*this = *this >> other;
	return *this;
}

bigint bigint::operator<<(const bigint& other) const {
    unsigned int shift = 0;
    for (size_t i = 0; i < other._digits.length(); ++i) {
        shift = shift * 10 + (other._digits[i] - '0');
    }
    
    return *this << shift;
}

bigint bigint::operator>>(const bigint& other) const {
    unsigned int shift = 0;
    for (size_t i = 0; i < other._digits.length(); ++i) {
        shift = shift * 10 + (other._digits[i] - '0');
    }
    
    return *this >> shift;
}
