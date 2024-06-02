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

        Mat4::Mat4(const SquareMatrix<4, float> &other) {
            for (int i = 0; i < 16; i++) {
                this->data[i] = other.data[i];
            }
        }

        Mat4 Mat4::orthographic(float left, float right, float top, float bottom, float near, float far) {
            Mat4 ret{};
            float rldiff = right - left;
            float tbdiff = top - bottom;
            float fndiff = far - near;

            ret.data[0] = 2.0f / rldiff;
            ret.data[3] = -(right + left) / rldiff;

            ret.data[5] = 2.0f / tbdiff;
            ret.data[7] = -(top + bottom) / tbdiff;

            ret.data[10] = -2.0f / fndiff;
            ret.data[11] = -(far + near) / fndiff;

            ret.data[15] = 1.0;

            return ret;
        }

        const float DEGTORAD = 3.1415926535 / 180.0;

        Mat4 Mat4::perspective(float fov, float aspect, float near, float far) {
            Mat4 ret{};

            float tangent = tan(fov/2 * DEGTORAD);
            float top = near * tangent;
            float right = top * aspect;

            ret.data[0] = near / right;
            ret.data[5] = near / top;
            ret.data[10] = -(far + near) / (far - near);
            ret.data[11] = (-2*far*near) / (far - near);
            ret.data[14] = -1;

            return ret;
        }

        Mat4 Mat4::viewMatrix(const Vec3 &camPos, const Vec3 &at, const Vec3 &up) {
            Vec3 z = camPos - at;
            z = z.normal();
            Vec3 x = up.cross(z).normal();
            Vec3 y = up;

            Mat4 ret{};

            ret.data[0] = x[0];
            ret.data[1] = x[1];
            ret.data[2] = x[2];
            ret.data[3] = -x.dot(camPos);
            ret.data[4] = y[0];
            ret.data[5] = y[1];
            ret.data[6] = y[2];
            ret.data[7] = -y.dot(camPos);
            ret.data[8] = z[0];
            ret.data[9] = z[1];
            ret.data[10] = z[2];
            ret.data[11] = -z.dot(camPos);
            ret.data[15] = 1.0;

            return ret.transpose();
        }

        Mat4 Mat4::transpose() {
            Mat4 ret;
            ((SquareMatrix<4,float> *)this)->transpose(ret);
            return ret;
        }

        Mat4 Mat4::operator*(const float other) {
            Mat4 ret{};
            this->scalarMul(other, ret);
            return ret;
        }


    } // Math
} // MiniMario