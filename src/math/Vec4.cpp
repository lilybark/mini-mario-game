/* date = May 05, 2024 9:09 AM */

#include "Vec4.h"

namespace MiniMario {
    namespace Math {
        Vec4::Vec4(const float *array) : Vector() {
            for (int i = 0; i < 4; i++) {
                this->data[i] = array[i];
            }
        }
    } // Math
} // MiniMario