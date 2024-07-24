/* date = May 11, 2024 10:56 AM */

#include "Camera.h"
#include "App.h"
#include "math/Mat3.h"

namespace MiniMario {
    namespace Renderer {
        Camera::Camera() {
            this->position = Math::Vec3(0.0f, 0.0f, -0.5f);
            this->eulerRotation = Math::Vec3(0.0f, 0.0f, 0.0f);
            this->zoom = 20;
        }

        Math::Mat4 Camera::getOrthographicMatrix() const {
            const auto *a = App::get();
            const auto width = static_cast<float>(a->getWidth());
            const auto height = static_cast<float>(a->getHeight());

            return Math::Mat4::orthographic(-width / zoom, width / zoom, -height / zoom, height / zoom, 0, 100);
            //return Math::Mat4::ident();
        }

        Math::Mat4 Camera::getPerspectiveMatrix() const {
            const auto *a = App::get();
            const auto width = static_cast<float>(a->getWidth());
            const auto height = static_cast<float>(a->getHeight());

            return Math::Mat4::perspective(90, width / height, 1, 10*zoom);
        }

        Math::Mat4 Camera::getViewMatrix() const {
            Math::Vec3 eye = this->position;
            // TODO: implement rotation
            Math::Vec3 at = this->position+Math::Vec3{0.0, 0.0, -1.0};
            Math::Vec3 up = {0.0, 1.0, 0.0};

            return Math::Mat4::viewMatrix(eye, at, up);
            //return Math::Mat4::ident();
        }

        void Camera::translate(Math::Vec3 dPos) { this->position = this->position + dPos; }
        void Camera::setRotation(Math::Vec3 rot) { this->eulerRotation = rot; }
        void Camera::rotate(Math::Vec3 dRot) { this->eulerRotation += dRot; }

        void Camera::moveTo(Math::Vec3 pos) {
            this->position = pos;
        }
    } // Renderer
} // MiniMario