#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>
#include <iostream>

class Vector2
{
public:
    Vector2();
    Vector2(float x, float y);

    Vector2 &add(const Vector2 &vec);
    Vector2 &subtract(const Vector2 &vec);
    Vector2 &multiply(const Vector2 &vec);
    Vector2 &divide(const Vector2 &vec);
    float magnitude() const;
    Vector2 Normalized() const;
    Vector2 Project(const Vector2 vec,const Vector2 onto) const;
    Vector2 Normal() const;
    Vector2 Reflect(const Vector2 v, const Vector2 r);

    friend Vector2 operator+(const Vector2 &vec1, const Vector2 &vec2);
    friend Vector2 operator+(const Vector2 &vec, float scalar);
    friend Vector2 operator+(float scalar, const Vector2 &vec);
    friend Vector2 operator+(const Vector2 &vec, int scalar);
    friend Vector2 operator+(int scalar, const Vector2 &vec);

    friend Vector2 operator-(const Vector2 &vec1, const Vector2 &vec2);
    friend Vector2 operator-(const Vector2 &vec, float scalar);
    friend Vector2 operator-(float scalar, const Vector2 &vec);
    friend Vector2 operator-(const Vector2 &vec, int scalar);
    friend Vector2 operator-(int scalar, const Vector2 &vec);

    friend Vector2 operator*(const Vector2 &vec1, const Vector2 &vec2);
    friend Vector2 operator*(const Vector2 &vec, float scalar);
    friend Vector2 operator*(float scalar, const Vector2 &vec);
    friend Vector2 operator*(const Vector2 &vec, int scalar);
    friend Vector2 operator*(int scalar, const Vector2 &vec);

    friend Vector2 operator/(const Vector2 &vec1, const Vector2 &vec2);
    friend Vector2 operator/(const Vector2 &vec, float scalar);
    friend Vector2 operator/(float scalar, const Vector2 &vec);
    friend Vector2 operator/(const Vector2 &vec, int scalar);
    friend Vector2 operator/(int scalar, const Vector2 &vec);

    Vector2 &operator+=(const Vector2 &vec);
    Vector2 &operator-=(const Vector2 &vec);
    Vector2 &operator*=(const Vector2 &vec);
    Vector2 &operator/=(const Vector2 &vec);
    Vector2 &operator*=(float scalar);

    friend bool operator==(const Vector2 &vec1, const Vector2 &vec2);
    friend bool operator!=(const Vector2 &vec1, const Vector2 &vec2);

    Vector2 &zero();

    float x;
    float y;

    friend std::ostream &operator<<(std::ostream &stream, const Vector2 &vec);
};

#endif
