/* date = May 05, 2024 9:09 AM */

#include "Vec4.h"

namespace MiniMario {
    namespace Math {
        Vec4::Vec4(const float *array) : Vector() {
            for (int i = 0; i < 4; i++) {
                this->data[i] = array[i];
            }
        }

        Vec4::Vec4(const float w, const float x, const float y, const float z) : Vector() {
            this->data[0] = w;
            this->data[1] = x;
            this->data[2] = y;
            this->data[3] = z;
        }

        Vec4::Vec4(const Vector<4, float> &other) {
            for (int i = 0; i < 4; i++) {
                this->data[i] = other.data[i];
            }
        }
    } // Math
} // MiniMario