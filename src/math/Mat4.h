/* date = April 28, 2024 11:09 PM */

#ifndef MINI_MARIO_MAT4_H
#define MINI_MARIO_MAT4_H

#include "Vec4.h"
#include "SquareMatrix.h"
#include "Vec3.h"

namespace MiniMario {
    namespace Math {

        class Mat4 : public SquareMatrix<4,float> {
        public:
            Mat4() = default;
            Mat4(const SquareMatrix<4,float> &);

            Mat4 operator*(const Mat4 &other);
            Mat4 operator*(const float other);
            Vec4 operator*(const Vec4 &other);

            Mat4 transpose();

            static Mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
            static Mat4 perspective(float fov, float aspect, float front, float back);
            static Mat4 viewMatrix(const Vec3 &camPos, const Vec3 &eye, const Vec3 &up);

            static Mat4 scale3D(const Vec3 &scaling);
            static Mat4 translate3D(const Vec3 &translating);
            static Mat4 rotate3D(const Vec3 &eulerAngles);
        };

    } // Math
} // MiniMario

#endif //MINI_MARIO_MAT4_H
