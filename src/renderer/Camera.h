/* date = May 11, 2024 10:56 AM */

#ifndef MINI_MARIO_CAMERA_H
#define MINI_MARIO_CAMERA_H

#include "math/Mat4.h"
#include "math/Vec3.h"

namespace MiniMario {
    namespace Renderer {

        class Camera {
        public:
            Camera();

            void moveTo(Math::Vec3 pos);
            void translate(Math::Vec3 dPos);

            void setRotate(Math::Vec3 rot);
            void rotate(Math::Vec3 dRot);

            Math::Mat4 getProjectionMatrix();
            Math::Mat4 getPerspectiveMatrix();
        private:
            Math::Mat4 projection;
            Math::Vec3 position;
            Math::Vec3 gimbalRotation;
        };

    } // Renderer
} // MiniMario

#endif //MINI_MARIO_CAMERA_H
