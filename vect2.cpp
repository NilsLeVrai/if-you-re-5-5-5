#include "vect2.hpp"

vect2::vect2() : _x(0) , _y(0) {}

vect2::vect2(int x, int y) : _x(x) , _y(y) {}

int& vect2::operator[](int index) {
    if (index == 0) {
        return _x;
    } else {
        return _y;
    }
}

const int& vect2::operator[](int index) const{
    return (index == 0) ? _x : _y;
}

bool vect2::operator==(const vect2& other) const{
    return (_x == other._x && _y == other._y);
}

bool vect2::operator!=(const vect2& other) const {
    return !(*this == other);
}

vect2& vect2::operator++() {
    *this = *this + 1;
    return *this;
}

vect2 vect2::operator++(int) {
    vect2 tmp = *this;
    ++(*this);
    return tmp;
}

vect2& vect2::operator--() {
    *this = *this - 1;
    return *this;
}

vect2 vect2::operator--(int) {
    vect2 tmp = *this;
    --(*this);
    return tmp;
}

vect2 operator*(const vect2& lhs, const vect2& rhs) {
    vect2 tmp = lhs;
    tmp *= rhs;
    return tmp;
}

vect2 operator*(const vect2& lhs, int scalar) {
    vect2 tmp = lhs;
    tmp *= scalar;
    return tmp;
}

vect2 operator*(int scalar, const vect2& rhs) {
    return (rhs * scalar);
}

vect2 operator-(const vect2& lhs, const vect2& rhs) {
    vect2 tmp = lhs;
    tmp -= rhs;
    return tmp;
}

vect2 operator-(const vect2& lhs, int scalar) {
    vect2 tmp = lhs;
    tmp -= scalar;
    return tmp;
}

vect2 operator-(int scalar, const vect2& rhs) {
    return vect2(scalar, scalar) - rhs; // mystique
}

vect2 operator+(const vect2& lhs, const vect2& rhs) {
    vect2 tmp = lhs;
    tmp += rhs;
    return tmp;
}

vect2 operator+(const vect2& lhs, int scalar) {
    vect2 tmp = lhs;
    tmp += scalar;
    return tmp;
}

vect2 operator+(int scalar, const vect2& rhs) {
    return (rhs + scalar);
}

vect2& vect2::operator*=(int scalar) {
    _x *= scalar;
    _y *= scalar;
    return *this;
}

vect2& vect2::operator*=(const vect2& other) {
    _x *= other._x;
    _y *= other._y;
    return *this;
}

vect2& vect2::operator-=(int scalar) {
    _x -= scalar;
    _y -= scalar;
    return *this;
}

vect2& vect2::operator-=(const vect2& other) {
    _x -= other._x;
    _y -= other._y;
    return *this;
}

vect2& vect2::operator+=(int scalar) {
    _x += scalar;
    _y += scalar;
    return *this;
}

vect2& vect2::operator+=(const vect2& other) {
    _x += other._x;
    _y += other._y;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const vect2& v) {
    os << "{" << v[0] << ", " << v[1] << "}";
    return os;
}
