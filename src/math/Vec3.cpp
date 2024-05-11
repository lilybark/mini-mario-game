/* date = May 05, 2024 10:28 AM */

#include "Vec3.h"

namespace MiniMario {
    namespace Math {
        Vec3::Vec3(const float *array) : Vector() {
            for (int i = 0; i < 3; i++) {
                this->data[i] = array[i];
            }
        }

        Vec3::Vec3(const Vector<3, float> &other) {
            for (int i = 0; i < 3; i++) {
                this->data[i] = other.data[i];
            }
        }

        Vec3::Vec3(float x, float y, float z) : Vector() {
            this->data[0] = x;
            this->data[1] = y;
            this->data[2] = z;
        }

        Vec3::Vec3(const Vec4 &other) : Vector() {
            this->data[0] = other.data[0];
            this->data[1] = other.data[1];
            this->data[2] = other.data[2];
        }

        Vec3 Vec3::cross(const Vec3 &other) {
            return Vec3(
                    this->data[1] * other.data[2] - this->data[2] * other.data[1],
                    this->data[2] * other.data[0] - this->data[0] * other.data[2],
                    this->data[0] * other.data[1] - this->data[1] * other.data[0]
                    );
        }
    } // Math
} // MiniMario