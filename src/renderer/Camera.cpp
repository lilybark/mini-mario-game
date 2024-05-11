/* date = May 11, 2024 10:56 AM */

#include "Camera.h"

namespace MiniMario {
    namespace Renderer {
        Camera::Camera() {
            this->position = Math::Vec3(0.0f, -1.0f, 0.0f);
            this->gimbalRotation = Math::Vec3();
            this->projection = Math::Mat4();
        }


    } // Renderer
} // MiniMario