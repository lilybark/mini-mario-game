/* date = May 10, 2024 10:07 AM */

#include "Rectangle.h"
#include "renderer/RendererController.h"

namespace MiniMario {
    void Rectangle::render() {
        using namespace Math;
        Vec3 corners[] = {
                this->pos + this->scale / 2.0f,
                this->pos + Vec3(-this->scale[0], this->scale[1], 0) / 2.0f,
                this->pos - this->scale / 2.0f,
                this->pos - Vec3(-this->scale[0], this->scale[1], 0) / 2.0f
        };

        for (Vec3 corner : corners) {
            float vertex[10];
            // insert position.
            vertex[0] = corner[0];
            vertex[1] = corner[1];
            vertex[2] = corner[2];

            // insert color. We will change this once Entities get colors.
            vertex[3] = 1.0f;
            vertex[4] = 1.0f;
            vertex[5] = 1.0f;
            vertex[6] = 1.0f;

            // we currently don't have textures. set texture UVs and IDs to 0
            vertex[7] = 0.0f;
            vertex[8] = 0.0f;

            vertex[9] = 0.0f;

            MiniMario::Renderer::RendererController::get()->pushVertex(&vertex[0]);
        }
    }

    Rectangle::Rectangle() {
        using namespace Math;
        this->pos = Vec3(0.0, 0.0, 0.0);
        this->scale = Vec3(0.5, 0.5, 0.5);
    }

    void Rectangle::update(double) {
        this->render();
    }
} // MiniMario