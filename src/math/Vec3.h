/* date = May 05, 2024 10:28 AM */

#ifndef MINI_MARIO_VEC3_H
#define MINI_MARIO_VEC3_H

#include <cstdlib>
#include "Vec4.h"

namespace MiniMario {
    namespace Math {

        class Vec3 : public Vector<3, float> {
        public:
            Vec3() : Vector() {}
            Vec3(float x, float y, float z);
            explicit Vec3(const Vec4 &other);
            explicit Vec3(const float array[3]);
            // does not need to be explicit
            Vec3(const Vector<3, float>&);

            Vec3 cross(const Vec3 &other);
        };

    } // Math
} // MiniMario

#endif //MINI_MARIO_VEC3_H
