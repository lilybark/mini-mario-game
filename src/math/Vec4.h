/* date = May 05, 2024 9:09 AM */

#ifndef MINI_MARIO_VEC4_H
#define MINI_MARIO_VEC4_H

#include "Vector.h"

namespace MiniMario {
    namespace Math {

        class Vec4 : public Vector<4, float> {
        public:
            Vec4() : Vector() {}

            explicit Vec4(const float array[4]);

            Vec4 operator+(const Vec4 &other);
            Vec4 operator*(float);
        };

    } // Math
} // MiniMario

#endif //MINI_MARIO_VEC4_H
