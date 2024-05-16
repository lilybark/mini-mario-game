/* date = May 05, 2024 9:09 AM */

#ifndef MINI_MARIO_VEC4_H
#define MINI_MARIO_VEC4_H

#include "Vector.h"

namespace MiniMario {
    namespace Math {

        class Vec4 : public Vector<4, float> {
        public:
            Vec4() : Vector() {}

            Vec4(const float w, const float x, const float y, const float z);
            explicit Vec4(const float array[4]);
            Vec4(const Vector<4,float> &);
        };

    } // Math
} // MiniMario

#endif //MINI_MARIO_VEC4_H
