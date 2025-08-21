#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>       // For std::string
#include <iostream>     // For std::ostream
#include <algorithm>    // For std::reverse
#include <stdexcept>    // For std::out_of_range (if used for error handling)
#include <sstream>      // For std::stringstream (C++98 way to convert int to string)
#include <cctype>       // For isdigit
#include <sstream>      // For std::stringstream

class bigint {
private:
    std::string digits; // Stores digits as a string, e.g., "123" for the number 123.
                        // The most significant digit is at digits[0].

    // Private helper to remove leading zeros.
    // Ensures that "00123" becomes "123" and "0" remains "0".
    void removeLeadingZeros();

public:
    // Constructors
    // Initializes a bigint from a long integer. Default to 0.
    // Changed long long to long for C++98 compatibility.
    bigint(long n = 0);
    // Initializes a bigint from a string of digits.
    bigint(const std::string& s);
    // Initializes a bigint from a C-style string literal of digits.
    bigint(const char* s);

    // Arithmetic operators
    // Adds two bigint numbers and returns a new bigint with the sum.
    bigint operator+(const bigint& other) const;
    // Subtracts one bigint from another and returns a new bigint with the difference.
    // Assumes *this >= other for unsigned bigint.
    bigint operator-(const bigint& other) const;

    // Compound assignment operators
    bigint& operator+=(const bigint& other);
    bigint& operator-=(const bigint& other);
    bigint& operator<<=(unsigned int shift_amount);
    bigint& operator>>=(unsigned int shift_amount);

    // Increment operators
    bigint& operator++();    // Pre-increment
    bigint operator++(int); // Post-increment

    // Comparison operators.
    // Compare two bigint numbers.
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;

    // Digit shift operators.
    // Behaves like bitshift but for base-10 digits.
    // Left shift (multiplication by powers of 10).
    // e.g., (42 << 3) == 42000
    bigint operator<<(unsigned int shift_amount) const;
    // Right shift (integer division by powers of 10, truncating).
    // e.g., (1337 >> 2) == 13
    bigint operator>>(unsigned int shift_amount) const;

    // Friend function to allow printing bigint objects using the << operator.
    friend std::ostream& operator<<(std::ostream& os, const bigint& num);
};

#endif // BIGINT_V4_HPP
