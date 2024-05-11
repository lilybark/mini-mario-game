/* date = April 28, 2024 11:09 PM */

#include "Mat4.h"

namespace MiniMario {
    namespace Math {
        Vec4 Mat4::operator*(const Vec4 &other) {
            Vec4 ret{};
            this->matVecMul(other, ret);
            return Vec4{ret};
        }

        Mat4 Mat4::operator*(const Mat4 &other) {
            Mat4 ret{};
            this->matMul(other, ret);
            return ret;
        }


    } // Math
} // MiniMario