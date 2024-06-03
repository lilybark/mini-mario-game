//
// Created by meili on 6/2/2024.
//

#include "Vec2.h"

namespace MiniMario {
    Math::Vec2::Vec2(float x, float y) : Vector() {
        this->data[0] = x; this->data[1] = y;
    }
} // MiniMario