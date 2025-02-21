#include "Vector2.hpp"

Vector2::Vector2() : x(0.0f), y(0.0f) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::Normalized() const {
    float mag = magnitude();
    if (mag > 0) {
        return Vector2(x / mag, y / mag);
    }
    return Vector2(0, 0);
}

Vector2 Vector2::Project(const Vector2 &onto) const {
    float dotProduct = x * onto.x + y * onto.y;
    float ontoMagnitudeSquared = onto.x * onto.x + onto.y * onto.y;
    
    if (ontoMagnitudeSquared == 0) {
        return Vector2(0, 0);
    }
    
    float scale = dotProduct / ontoMagnitudeSquared;
    return Vector2(onto.x * scale, onto.y * scale);
}

bool operator==(const Vector2 &vec1, const Vector2 &vec2) {
    return vec1.x == vec2.x && vec1.y == vec2.y;
}

bool operator!=(const Vector2 &vec1, const Vector2 &vec2) {
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

float Vector2::norm(const Vector2 &vec)
{
    float norm = std::sqrt(vec.x * vec.x + vec.y * vec.y);
    return norm;
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
