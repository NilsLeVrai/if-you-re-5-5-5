#pragma once

#include <iostream>

class vect2 {

private:
    int _x;
    int _y;

public:
    vect2();
    vect2(int x, int y);

    int& operator[](int index);
    const int& operator[](int index) const;

    vect2& operator++();
    vect2 operator++(int);

    vect2& operator--();
    vect2 operator--(int);

    vect2& operator*=(int scalar);
    vect2& operator*=(const vect2& other);
    vect2& operator-=(int scalar);
    vect2& operator-=(const vect2& other);
    vect2& operator+=(int scalar);
    vect2& operator+=(const vect2& other);

    bool operator==(const vect2& other) const;
    bool operator!=(const vect2& other) const;

};
std::ostream& operator<<(std::ostream& os, const vect2& other);

vect2 operator*(const vect2& lhs, const vect2& rhs);
vect2 operator*(const vect2& lhs, int scalar);
vect2 operator*(int scalar, const vect2& rhs);

vect2 operator-(const vect2& lhs, const vect2& rhs);
vect2 operator-(const vect2& lhs, int scalar);
vect2 operator-(int scalar, const vect2& rhs);

vect2 operator+(const vect2& lhs, const vect2& rhs);
vect2 operator+(const vect2& lhs, int scalar);
vect2 operator+(int scalar, const vect2& rhs);

