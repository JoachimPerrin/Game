#include "Vector2.hpp"

Vector2::Vector2() : x(0.0f), y(0.0f) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::magnitude() const
{
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::Normalized() const
{
    float mag = magnitude();
    if (mag > 0)
    {
        return Vector2(x / mag, y / mag);
    }
    return Vector2(0, 0);
}

Vector2 Vector2::Project(const Vector2 vec, const Vector2 onto) const
{
    Vector2 num = vec * onto;
    Vector2 den = onto * onto;
    if (onto != Vector2(0, 0))
        return num / den * onto;
    return Vector2(0, 0);
}

Vector2 Vector2::Reflect(const Vector2 v, const Vector2 r)
{
    Vector2 denom = r * r;
    if (denom == Vector2(0, 0))
        return v; // Évite la division par zéro
    Vector2 proj = (v * r / denom) * r;
    return (proj * 2) - v;
}

Vector2 Vector2::Normal() const
{
    return (Vector2(-y, x));
}

bool operator==(const Vector2 &vec1, const Vector2 &vec2)
{
    return vec1.x == vec2.x && vec1.y == vec2.y;
}

bool operator!=(const Vector2 &vec1, const Vector2 &vec2)
{
    return !(vec1 == vec2);
}

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
    float x;
    float y;
    if (vec2.x == 0)
    {
        x = 0;
    }
    else
    {
        x = vec1.x / vec2.x;
    }
    if (vec2.y == 0)
    {
        y = 0;
    }
    else
    {
        y = vec1.y / vec2.y;
    }
    return Vector2(x, y);
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
