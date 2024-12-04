#include "Vector2.hpp"

Vector2::Vector2() : x(0.0f), y(0.0f) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2 &Vector2::add(const Vector2 &vec)
{
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector2 &Vector2::subtract(const Vector2 &vec)
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vector2 &Vector2::multiply(const Vector2 &vec)
{
    x *= vec.x;
    y *= vec.y;
    return *this;
}

Vector2 &Vector2::divide(const Vector2 &vec)
{
    x /= vec.x;
    y /= vec.y;
    return *this;
}

Vector2 operator+(const Vector2 &vec1, const Vector2 &vec2)
{
    return Vector2(vec1.x + vec2.x, vec1.y + vec2.y);
}
Vector2 operator+(const Vector2 &vec, float scalar)
{
    return Vector2(vec.x + scalar, vec.y + scalar);
}
Vector2 operator+(float scalar, const Vector2 &vec)
{
    return vec + scalar;
}
Vector2 operator+(const Vector2 &vec, int scalar)
{
    return Vector2(vec.x + scalar, vec.y + scalar);
}
Vector2 operator+(int scalar, const Vector2 &vec)
{
    return vec + scalar;
}

Vector2 operator-(const Vector2 &vec1, const Vector2 &vec2)
{
    return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
}
Vector2 operator-(const Vector2 &vec, float scalar)
{
    return Vector2(vec.x - scalar, vec.y - scalar);
}
Vector2 operator-(float scalar, const Vector2 &vec)
{
    return vec - scalar;
}
Vector2 operator-(const Vector2 &vec, int scalar)
{
    return Vector2(vec.x - scalar, vec.y - scalar);
}
Vector2 operator-(int scalar, const Vector2 &vec)
{
    return vec - scalar;
}

Vector2 operator*(const Vector2 &vec1, const Vector2 &vec2)
{
    return Vector2(vec1.x * vec2.x, vec1.y * vec2.y);
}
Vector2 operator*(const Vector2 &vec, float scalar)
{
    return Vector2(vec.x * scalar, vec.y * scalar);
}
Vector2 operator*(float scalar, const Vector2 &vec)
{
    return vec * scalar;
}
Vector2 operator*(const Vector2 &vec, int scalar)
{
    return Vector2(vec.x * scalar, vec.y * scalar);
}
Vector2 operator*(int scalar, const Vector2 &vec)
{
    return vec * scalar;
}

Vector2 operator/(const Vector2 &vec1, const Vector2 &vec2)
{
    return Vector2(vec1.x / vec2.x, vec1.y / vec2.y);
}
Vector2 operator/(const Vector2 &vec, float scalar)
{
    return Vector2(vec.x / scalar, vec.y / scalar);
}
Vector2 operator/(float scalar, const Vector2 &vec)
{
    return vec / scalar;
}
Vector2 operator/(const Vector2 &vec, int scalar)
{
    return Vector2(vec.x / scalar, vec.y / scalar);
}
Vector2 operator/(int scalar, const Vector2 &vec)
{
    return vec / scalar;
}

Vector2 &Vector2::operator+=(const Vector2 &vec)
{
    return add(vec);
}

Vector2 &Vector2::operator-=(const Vector2 &vec)
{
    return subtract(vec);
}

Vector2 &Vector2::operator*=(const Vector2 &vec)
{
    return multiply(vec);
}

Vector2 &Vector2::operator/=(const Vector2 &vec)
{
    return divide(vec);
}

Vector2 &Vector2::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2 &Vector2::zero()
{
    x = 0.0f;
    y = 0.0f;
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Vector2 &vec)
{
    stream << "(" << vec.x << ", " << vec.y << ")";
    return stream;
}