//
// Created by meili on 6/2/2024.
//

#ifndef MINI_MARIO_VEC2_H
#define MINI_MARIO_VEC2_H

#include "Vector.h"

namespace MiniMario {
    namespace Math {
        class Vec2 : public Vector<2, float> {

        public:
            Vec2(float x, float y);
        };
    }
} // MiniMario

#endif //MINI_MARIO_VEC2_H
