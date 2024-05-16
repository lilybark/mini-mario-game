/* date = May 09, 2024 8:50 PM */

#ifndef MINI_MARIO_SQUAREMATRIX_H
#define MINI_MARIO_SQUAREMATRIX_H

#include <cstdlib>

namespace MiniMario {
    namespace Math {
        // forward decl
        template<size_t N, typename T>
        class Vector;

        template<size_t N, typename T>
        class SquareMatrix {
        public:
            /**
             * A matrix multiplication, considering `this` to be the left matrix in the operation.
             * <br>
             * This isn't an operator function because the sizes of these matrices may be large, so
             * to give the option for a less copy-and-move implementation, this is left as a generic function.
             * @param other The right matrix in the operation.
             * @param dest Where the result of this operation is stored.
             */
            void matMul(const SquareMatrix<N,T> &other, SquareMatrix<N,T> &dest) {
                for (int j = 0; j < N; j++) {
                    for (int i = 0; i < N; i++) {
                        // can be vectorized if needed
                        dest.data[j*N+i] = 0;
                        for (int k = 0; k < N; k++) {
                            dest.data[j*N+i] += this->data[j*N+k] * other.data[i+k*4];
                        }
                    }
                }
            }
            /**
             * A matrix-vector multiplication.
             * <br>
             * This isn't an operator function because the sizes of these matrices may be large, so
             * to give the option for a less copy-and-move implementation, this is left as a generic function.
             * @param vec The column vector on the right side of the multiplication.
             * @param dest Where the result of this operation is stored.
             */
            void matVecMul(const MiniMario::Math::Vector<N,T> &vec, Vector<N,T> &dest) {
                for (int i = 0; i < N; i++) {
                    dest[i] = 0;
                    for (int j = 0; j < N; j++) {
                        dest[i] += this->data[i*N+j] * vec.data[j];
                    }
                }
            }

            void transpose(SquareMatrix<N,T> &dest) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        dest.data[i*N+j] = this->data[j*N+i];
                    }
                }
            }

            void add(const SquareMatrix<N,T> &other, SquareMatrix<N,T> &dest) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        dest.data[i*N+j] = this->data[i*N+j] + other.data[i*N+j];
                    }
                }
            }
            void sub(const SquareMatrix<N,T> &other, SquareMatrix<N,T> &dest) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        dest.data[i*N+j] = this->data[i*N+j] - other.data[i*N+j];
                    }
                }
            }
            void scalarMul(const T scalar, SquareMatrix<N,T> &dest) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        dest.data[i*N+j] = this->data[i*N+j] * scalar;
                    }
                }
            }
            void scalarDiv(const T scalar, SquareMatrix<N,T> &dest) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        dest.data[i*N+j] = this->data[i*N+j] / scalar;
                    }
                }
            }

            static SquareMatrix<N,T> ident() {
                SquareMatrix<N,T> ret{};
                for (int i = 0; i < N*N; i+=(N+1)) {
                    ret.data[i] = 1.0;
                }

                return ret;
            }


            T data[N*N];
        };

    } // Math
} // Pontilus

#endif //MINI_MARIO_SQUAREMATRIX_H
