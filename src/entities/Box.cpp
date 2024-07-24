/* date = July 15, 2024 9:34 PM */


#include "Box.h"

#include <cstring>

#include "Component.h"

namespace MiniMario {
    Box::Box() {
        auto *t = ComponentFactory<Transform>::generate();

        t->setScale({1.0, 1.0, 1.0});
        t->moveTo({0.0, 0.0, 0.0});

        auto *c = ComponentFactory<Color>::generate();

        c->setColor({0.5, 0.5, 0.5, 1.0});

        addComponent(t);
        addComponent(c);
    }

    void Box::render() {
        using namespace Renderer;
        // create eight vertices
        /*


            1-----0
           2+----3|
           |5----+4
           6-----7
         */
        Math::Vec4 corners[8] = {
            { 1.0,  1.0,  1.0, 1.0},
            {-1.0,  1.0,  1.0, 1.0},
            {-1.0, -1.0,  1.0, 1.0},
            { 1.0, -1.0,  1.0, 1.0},
            { 1.0,  1.0, -1.0, 1.0},
            {-1.0,  1.0, -1.0, 1.0},
            {-1.0, -1.0, -1.0, 1.0},
            { 1.0, -1.0, -1.0, 1.0},
        };

        // compute normals on vertices (will use simple method)
        Math::Vec3 normals[8]{};
        for (int i = 0; i < 8; i++) {
            normals[i] = Math::Vec3(corners[i]).normal();
        }
        // multiply vertices by scaling matrix
        Math::Mat4 scale = Math::Mat4::scale3D(this->getScale());
        // Math::Mat4 rot = Math::Mat4::rotate3D(this->getRotation());
        Math::Mat4 translate = Math::Mat4::translate3D(this->getPos());

        Math::Mat4 affine = translate * scale;

        for (auto &corner : corners) {
            corner = affine * corner;
        }

        for (auto &normal : normals) {
            Math::Vec4 tmpnorm = Math::Vec4(normal[0], normal[1], normal[2], 1.0);
            normal = /*rot * */ Math::Vec3(scale * tmpnorm).normal();
        }

        auto oldCount = RendererController::get()->getNumVertices();

        // upload vertices to buffer
        for (int i = 0; i < 8; i++) {
            auto *vertex = new float[4+3+4+2+1];
            auto c = corners[i];
            auto n = normals[i];
            auto col = this->getColor();
            float u = 0.0, v = 0.0;
            float id = 0.0;

            vertex[0] = c[0];
            vertex[1] = c[1];
            vertex[2] = c[2];
            vertex[3] = c[3];

            vertex[4] = n[0];
            vertex[5] = n[1];
            vertex[6] = n[2];

            vertex[7] = col[0];
            vertex[8] = col[1];
            vertex[9] = col[2];
            vertex[10] = col[3];

            vertex[11] = u;
            vertex[12] = v;
            vertex[13] = id;

            RendererController::get()->pushVertex(vertex);

            delete[] vertex;
        }

        // update element layout

        RendererController::get()->pushElementOrder(&boxLayout[0], 36, oldCount);
    }

    void Box::update(double dt) { this->render(); }

    const Math::Vec3 &Box::getPos() const { return this->getComponent<Transform>().getPos(); }
    const Math::Vec3 &Box::getScale() const { return this->getComponent<Transform>().getScale(); }
    const Math::Vec4 &Box::getColor() const { return this->getComponent<Color>().getColor(); }

    void Box::setPos(const Math::Vec3& pos) { this->getComponent<Transform>().moveTo(pos); }
    void Box::setScale(const Math::Vec3& s) { this->getComponent<Transform>().setScale(s); }
    void Box::setColor(const Math::Vec4& c) { this->getComponent<Color>().setColor(c); }
} // MiniMario