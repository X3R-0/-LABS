#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

struct Vector2 {
    float x;
    float y;

    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}

    Vector2& operator*=(float a);
    Vector2& operator/=(float a);
    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);

    float& operator[](size_t index);
    const float& operator[](size_t index) const;
};

Vector2 operator*(const Vector2& v, float a);
Vector2 operator*(float a, const Vector2& v);
Vector2 operator/(const Vector2& v, float a);
Vector2 operator+(const Vector2& v1, const Vector2& v2);
Vector2 operator-(const Vector2& v1, const Vector2& v2);

std::ostream& operator<<(std::ostream& os, const Vector2& v);

#endif