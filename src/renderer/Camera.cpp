/* date = May 11, 2024 10:56 AM */

#include "Camera.h"

namespace MiniMario {
    namespace Renderer {
        Camera::Camera() {
            this->position = Math::Vec3(0.0f, 0.0f, -0.5f);
            this->gimbalRotation = Math::Vec3(0.0f, 0.0f, 1.0f);
            this->projection = Math::Mat4();
        }

        Math::Mat4 Camera::getOrthographicMatrix() {
            // TODO: change this!
            return Math::Mat4::orthographic(-20, 20, -20, 20, 0, 100);
            //return Math::Mat4::ident();
        }

        Math::Mat4 Camera::getPerspectiveMatrix() {
            return Math::Mat4::perspective(90, 4.0/3.0, 1, 10);
        }

        Math::Mat4 Camera::getViewMatrix() {
            Math::Vec3 eye = this->position;
            // TODO: implement rotation
            Math::Vec3 at = this->position+Math::Vec3{0.0, 0.0, -1.0};
            Math::Vec3 up = {0.0, 1.0, 0.0};

            return Math::Mat4::viewMatrix(eye, at, up);
            //return Math::Mat4::ident();
        }

        void Camera::translate(Math::Vec3 dPos) {
            this->position = this->position + dPos;
        }

        void Camera::moveTo(Math::Vec3 pos) {
            this->position = pos;
        }


    } // Renderer
} // MiniMario