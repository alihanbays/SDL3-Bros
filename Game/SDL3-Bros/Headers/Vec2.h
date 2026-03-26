//
// Created by Alihan Baysal on 3/25/26.
//

#ifndef SDL3_BROS_VEC2_H
#define SDL3_BROS_VEC2_H
#include <iosfwd>
#include <iostream>
#include <valarray>

struct Vec2
{
    float x;
    float y;

    Vec2 operator-() const
    {
        return Vec2{-x, -y};
    }

    Vec2 operator+(const Vec2& other) const
    {
        return Vec2{x + other.x, y + other.y};
    }

    Vec2 operator-(const Vec2& other) const
    {
        return *this + (-other);
    }

    Vec2 operator/(const Vec2& other) const
    {
        return Vec2{x / other.x, y / other.y};
    }

    Vec2 operator*(const float multiplier) const
    {
        return Vec2{x * multiplier, y * multiplier};
    }

    Vec2 operator/(const float divisor) const
    {
        if (divisor == 0.0f)
        {
            return Vec2{0, 0};
        }

        return Vec2{x / divisor, y / divisor};
    }

    Vec2& operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& operator*=(const float multiplier)
    {
        x *= multiplier;
        y *= multiplier;
        return *this;
    }

    Vec2& operator/=(const Vec2& other)
    {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vec2& operator/=(const float divisor)
    {
        x /= divisor;
        y /= divisor;
        return *this;
    }

    float GetLength() const
    {
        return std::sqrt(x * x + y * y);
    }

    float GetDistance(const Vec2& other) const
    {
        return (*this - other).GetLength();
    }

    Vec2 Normalize() const
    {
        return *this / GetLength();
    }

    float Dot(const Vec2 other) const
    {
        return x * other.x + y * other.y;
    }
};

inline Vec2 operator*(float m, const Vec2& v)
{
    return v * m;
}

inline std::ostream& operator<<(std::ostream& os, const Vec2& v)
{
    os << "{" << v.x << ", " << v.y << "}";
    return os;
}

#endif //SDL3_BROS_VEC2_H
