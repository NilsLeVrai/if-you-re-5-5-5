#include "bigint.hpp"    

// Private helper to remove leading zeros.
void bigint::removeLeadingZeros() {

	int i = 0;
	while (i < digits.length() && digits[i] == '0') {
		++i;
	}
	if (i == digits.length()) {
		digits = "0";
	} else {
		digits = digits.substr(i);
	}
}

// Constructor from long. Changed from long long to long for C++98.
bigint::bigint(long n) {
    if (n < 0) {
        digits = "0"; // Or throw an exception for unsigned negative input
    } else {
        std::stringstream ss; // Use stringstream for conversion
        ss << n;
        digits = ss.str();
    }
    removeLeadingZeros();
}

// Constructor from std::string.
/*bigint::bigint(const std::string& s) {
    if (s.empty()) {
        digits = "0";
    } else {
        // Replaced range-based for loop with traditional for loop for C++98.
        for (std::string::size_type i = 0; i < s.length(); ++i) {
            if (!std::isdigit(s[i])) {
                digits = "0"; // Fallback for invalid characters
                break;
            }
        }
        digits = s;
    }
    removeLeadingZeros();
}*/

// Constructor from C-style string.
// Implemented directly instead of delegating for C++98 compatibility.
bigint::bigint(const char* s) {
    if (!s || !*s) {  // Check for NULL or empty string
        digits = "0";
        return;
    }
    std::string temp(s);
    if (temp.find_first_not_of("0123456789") != std::string::npos) {
        digits = "0";
    } else {
        digits = temp;
    }
    removeLeadingZeros();
}

std::ostream& operator<<(std::ostream& os, const bigint& num) {
	os << num.digits;
	return os;
}

/*bigint bigint::operator+(const bigint& other) const {
    std::string result_str = "";
    std::string s1 = digits;
    std::string s2 = other.digits;

    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += (s1[i--] - '0');
        }
        if (j >= 0) {
            sum += (s2[j--] - '0');
        }

        // Use stringstream to convert int to char for C++98 compatibility
        std::stringstream ss_digit;
        ss_digit << (sum % 10);
        result_str += ss_digit.str();

        carry = sum / 10;
    }

    std::reverse(result_str.begin(), result_str.end());

    return bigint(result_str);
}

// Subtraction operator.
bigint bigint::operator-(const bigint& other) const {
    if (*this < other) {
        return bigint(0L); // Fix: Use 0L to explicitly call bigint(long)
    }

    std::string result_str = "";
    std::string s1 = digits;
    std::string s2 = other.digits;

    // Pad s2 with leading zeros if it's shorter than s1.
    if (s1.length() > s2.length()) {
        s2 = std::string(s1.length() - s2.length(), '0') + s2;
    }

    int borrow = 0;
    for (int i = s1.length() - 1; i >= 0; --i) {
        int digit1 = s1[i] - '0';
        int digit2 = s2[i] - '0';

        digit1 -= borrow;

        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        std::stringstream ss_diff;
        ss_diff << (digit1 - digit2);
        result_str += ss_diff.str();
    }

    std::reverse(result_str.begin(), result_str.end());

    return bigint(result_str);
}

// Compound assignment addition.
bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return *this;
}

// Compound assignment subtraction.
bigint& bigint::operator-=(const bigint& other) {
    *this = *this - other;
    return *this;
}

// Pre-increment operator (++prefix)
bigint& bigint::operator++() {
    *this = *this + bigint(1L); // Fix: Use 1L to explicitly call bigint(long)
    return *this;
}

// Post-increment operator (postfix++)
bigint bigint::operator++(int) {
    bigint temp = *this;
    ++(*this);
    return temp;
}

// Equality comparison operator.
bool bigint::operator==(const bigint& other) const {
    return digits == other.digits;
}

// Inequality comparison operator.
bool bigint::operator!=(const bigint& other) const {
    return !(digits == other.digits);
}

// Less than comparison operator.
bool bigint::operator<(const bigint& other) const {
    if (digits.length() != other.digits.length()) {
        return digits.length() < other.digits.length();
    }
    return digits < other.digits;
}

bool bigint::operator>(const bigint& other) const {
	return other < *this; // Use the less than operator for comparison
}

// Less than or equal to comparison operator.
bool bigint::operator<=(const bigint& other) const {
    return !(*this > other);
}

// Greater than or equal to comparison operator.
bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

// Left digit shift operator.
bigint bigint::operator<<(unsigned int shift_amount) const {
    if (digits == "0") {
        return bigint(0L); // Fix: Use 0L to explicitly call bigint(long)
    }

    std::string shifted_digits = digits;
    shifted_digits.append(shift_amount, '0');
    return bigint(shifted_digits);
}

// Right digit shift operator.
bigint bigint::operator>>(unsigned int shift_amount) const {
    if (shift_amount >= digits.length()) {
        return bigint(0L); // Fix: Use 0L to explicitly call bigint(long)
    }

    std::string shifted_digits = digits.substr(0, digits.length() - shift_amount);
    return bigint(shifted_digits);
}

// Compound assignment left digit shift.
bigint& bigint::operator<<=(unsigned int shift_amount) {
    *this = *this << shift_amount;
    return *this;
}

// Compound assignment right digit shift.
bigint& bigint::operator>>=(unsigned int shift_amount) {
    *this = *this >> shift_amount;
    return *this;
}*/

// Output stream operator.
