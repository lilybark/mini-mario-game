/* date = April 28, 2024 11:09 PM */

#include "Mat4.h"

#include <cmath>

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

        Mat4::Mat4(const SquareMatrix &other) : SquareMatrix(other) { }

        Mat4 Mat4::orthographic(const float left, const float right,
                                const float top, const float bottom,
                                const float near, const float far)
        {
            Mat4 ret{};
            const float rldiff = right - left;
            const float tbdiff = top - bottom;
            const float fndiff = far - near;

            ret.data[0] = 2.0f / rldiff;
            ret.data[3] = -(right + left) / rldiff;

            ret.data[5] = 2.0f / tbdiff;
            ret.data[7] = -(top + bottom) / tbdiff;

            ret.data[10] = -2.0f / fndiff;
            ret.data[11] = -(far + near) / fndiff;

            ret.data[15] = 1.0;

            return ret;
        }

        constexpr float DEGTORAD = 3.1415926535 / 180.0;

        Mat4 Mat4::perspective(float fov, float aspect, float near, float far) {
            Mat4 ret{};

            const float tangent = std::tan(fov/2 * DEGTORAD);
            const float top = near * tangent;
            const float right = top * aspect;

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

            ret.data[0]  = x[0];
            ret.data[1]  = x[1];
            ret.data[2]  = x[2];
            ret.data[3]  = -x.dot(camPos);
            ret.data[4]  = y[0];
            ret.data[5]  = y[1];
            ret.data[6]  = y[2];
            ret.data[7]  = -y.dot(camPos);
            ret.data[8]  = z[0];
            ret.data[9]  = z[1];
            ret.data[10] = z[2];
            ret.data[11] = -z.dot(camPos);
            ret.data[15] = 1.0;

            return ret.transpose();
        }
        Mat4 Mat4::scale3D(const Vec3 &scaling) {
            Mat4 ret{};

            ret.data[0]  = scaling.at(0);
            ret.data[5]  = scaling.at(1);
            ret.data[10] = scaling.at(2);
            ret.data[15] = 1.0;

            return ret;
        }
        Mat4 Mat4::translate3D(const Vec3 &translating) {
            Mat4 ret = ident();

            ret.data[3] = translating.at(0);
            ret.data[7] = translating.at(1);
            ret.data[11] = translating.at(2);

            return ret;
        }
        Mat4 Mat4::rotate3D(const Vec3 &eulerAngles) {
            Mat4 ret{};

            // this calculation was pulled from this link:
            // https://en.wikipedia.org/wiki/Rotation_matrix#In_three_dimensions

            const float sina = sinf(eulerAngles.at(0));
            const float cosa = sinf(eulerAngles.at(0));
            const float sinb = sinf(eulerAngles.at(1));
            const float cosb = sinf(eulerAngles.at(1));
            const float sinc = sinf(eulerAngles.at(2));
            const float cosc = sinf(eulerAngles.at(2));

            ret.data[0] = cosa*cosb;
            ret.data[1] = cosa*sinb*sinc - sina*cosc;
            ret.data[2] = cosa*sinb*cosc + sina*sinc;

            ret.data[4] = sina*cosb;
            ret.data[5] = sina*sinb*sinc + cosa*cosc;
            ret.data[6] = sina*sinb*cosc - cosa*sinc;

            ret.data[8] = -sinb;
            ret.data[9] = cosb*sinc;
            ret.data[10] = cosb*cosc;

            ret.data[15] = 1.0;

            return ret;
        }

        Mat4 Mat4::transpose() {
            Mat4 ret;
            static_cast<SquareMatrix *>(this)->transpose(ret);
            return ret;
        }

        Mat4 Mat4::operator*(const float other) {
            Mat4 ret{};
            this->scalarMul(other, ret);
            return ret;
        }
    } // Math
} // MiniMario