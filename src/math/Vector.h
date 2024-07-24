/* date = May 10, 2024 9:16 AM */

#ifndef MINI_MARIO_VECTOR_H
#define MINI_MARIO_VECTOR_H

#include <cstdlib>
#include <cmath>

namespace MiniMario {
    namespace Math {
        template<size_t N, typename T>
        class Vector {
        public:
            Vector() {
                Vector(0.0);
            }
            explicit Vector(T d) {
                for (int i = 0; i < N; i++) {
                    this->data[i] = d;
                }
            }

            template<size_t N2>
            explicit Vector(const Vector<N2, T> &other) {
                constexpr size_t end = N2 > N ? N : N2;
                for (int i = 0; i < end; i++) {
                    this->data[i] = other->data[i];
                }
            }

            const T &at(size_t idx) const {
                if (idx >= N) {
                    // TODO: error here
                    exit(-1);
                }

                return this->data[idx];
            }

            T dot(const Vector<N,T> &other) const {
                T ret{};
                for (int i = 0; i < N; i++) {
                    ret += this->data[i] * other.data[i];
                }
                return ret;
            }

            T distSquared() const {
                return this->dot(*this);
            }

            T dist() const {
                return sqrt(distSquared());
            }

            Vector<N,T> normal() const {
                return Vector<N,T>(*this / this->dist());
            }

            Vector<N,T> operator+(const Vector<N,T> &other) const {
                Vector<N,T> ret{};
                for (int i = 0; i < N; i++) {
                    ret[i] = this->data[i] + other.data[i];
                }
                return ret;
            }

            Vector<N,T> operator-(const Vector<N,T> &other) const {
                Vector<N,T> ret{};
                for (int i = 0; i < N; i++) {
                    ret[i] = this->data[i] - other.data[i];
                }
                return ret;
            }

            void operator+=(const Vector<N,T> &other) {
                for (int i = 0; i < N; i++) {
                    this->data[i] += other.data[i];
                }
            }

            void operator-=(const Vector<N,T> &other) {
                for (int i = 0; i < N; ++i) {
                    this->data[i] -= other.data[i];
                }
            }

            Vector<N,T> operator*(const T scalar) {
                Vector<N,T> ret{};
                for (int i = 0; i < N; i++) {
                    ret[i] = this[i] * scalar;
                }
                return ret;
            }

            Vector<N,T> operator/(const T scalar) const {
                Vector<N,T> ret{};
                for (int i = 0; i < N; i++) {
                    ret[i] = this->data[i] / scalar;
                }
                return ret;
            }

            void operator*=(const T scalar) {
                for (int i = 0; i < N; ++i) {
                    this->data[i] *= scalar;
                }
            }

            void operator/=(const T scalar) {
                for (int i = 0; i < N; ++i) {
                    this[i] /= scalar;
                }
            }

            T &operator[](size_t i) {
                if (i >= N) {
                    // TODO: error here
                    exit(-1);
                }

                return this->data[i];
            }

            T data[N];
        };
    }
}

#endif //MINI_MARIO_VECTOR_H
