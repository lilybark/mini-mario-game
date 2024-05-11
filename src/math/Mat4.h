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
            Mat4 operator*(const Mat4 &other);
            Vec4 operator*(const Vec4 &other);

            Mat4 orthographic();
            Mat4 perspective();
            Mat4 viewMatrix(const Vec3 &camPos, const Vec3 &eye, const Vec3 &up);
        };

    } // Math
} // MiniMario

#endif //MINI_MARIO_MAT4_H
