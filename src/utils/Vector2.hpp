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
    float norm(const Vector2 &vec);

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

    Vector2 &zero();

    float x;
    float y;

    friend std::ostream &operator<<(std::ostream &stream, const Vector2 &vec);
};

#endif
