/* date = May 10, 2024 10:07 AM */

#include "Rectangle.h"
#include "renderer/RendererController.h"
#include "math/Vec4.h"

namespace MiniMario {
    void Rectangle::render() {
        using namespace Math;
        Vec3 corners[] = {
                this->pos + this->scale / 2.0f,
                this->pos + Vec3(-this->scale[0], this->scale[1], this->scale[2]) / 2.0f,
                this->pos - Vec3(this->scale[0], this->scale[1], -this->scale[2]) / 2.0f,
                this->pos - Vec3(-this->scale[0], this->scale[1], -this->scale[2]) / 2.0f
        };

        for (Vec3 corner : corners) {
            float vertex[11];
            // insert position.
            vertex[0] = corner[0];
            vertex[1] = corner[1];
            vertex[2] = corner[2];
            vertex[3] = 1.0;

            // insert color. We will change this once Entities get colors.
            vertex[4] = this->color[0];
            vertex[5] = this->color[1];
            vertex[6] = this->color[2];
            vertex[7] = this->color[3];

            // we currently don't have textures. set texture UVs and IDs to 0
            vertex[8] = 0.0f;
            vertex[9] = 0.0f;

            vertex[10] = 0.0f;

            MiniMario::Renderer::RendererController::get()->pushVertex(&vertex[0]);
        }
    }

    Rectangle::Rectangle() {
        using namespace Math;
        this->pos = Vec3(0.0, 0.0, 0.0);
        this->scale = Vec3(0.5, 0.5, 0.5);
        this->color = Vec4(1.0, 1.0, 1.0, 1.0);
    }

    void Rectangle::update(double) {
        this->render();
    }

    void Rectangle::setColor(const Math::Vec4 &c) {
        this->color = c;
    }

    Rectangle::~Rectangle() {

    }

    Math::Vec4 &Rectangle::getColor() {
        return this->color;
    }
} // MiniMario