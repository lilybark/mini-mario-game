/* date = May 12, 2024 5:12 PM */

#include "BouncyRectangles.h"

#include "entities/Box.h"
#include "input/Keyboard.h"
#include "input/Mouse.h"

namespace MiniMario {
    const Math::Vec3 scale = {1.0, 2.0, 2.0};
    const Math::Vec4 color = {0.0, 0.0, 1.0, 1.0};
    static size_t boxID = 0;
    void BouncyRectangles::start() {
        auto *r = this->spawn<Box>();

        r->setPos(Math::Vec3::ZERO);
        r->setScale(scale);
        r->setColor(color);

        boxID = r->getID();

        camera.moveTo({1.0, 1.0, 10.0});
    }

    void BouncyRectangles::update(double dt) {
        static Math::Vec3 iscale = scale;
        using Key = Keyboard::Key;
        auto dtf = static_cast<float>(dt) * 3.0f;
        if (Keyboard::isPressed(Key::W)) {
            camera.translate({0.0, 0.0, -1.0f*dtf});
        }
        if (Keyboard::isPressed(Key::S)) {
            camera.translate({0.0, 0.0, 1.0f*dtf});
        }
        if (Keyboard::isPressed(Key::A)) {
            camera.translate({-1.0f*dtf, 0.0, 0.0});
        }
        if (Keyboard::isPressed(Key::D)) {
            camera.translate({1.0f*dtf, 0.0, 0.0});
        }
        if (Keyboard::isPressed(Key::SPACE)) {
            camera.translate({0.0, 1.0f*dtf, 0.0});
        }
        if (Keyboard::isPressed(Key::LEFT_SHIFT)) {
            camera.translate({0.0, -1.0f*dtf, 0.0});
        }

        iscale[0] = (float) fabs(sqrt(2) * (cos(2 * glfwGetTime()) + sin(2 * glfwGetTime())));
        iscale[1] = (float) fabs(sin(glfwGetTime()));
        iscale[2] = (float) fabs(cos(glfwGetTime()));

        auto r = dynamic_cast<Box *>(this->getEntity(boxID));

        r->setScale(iscale);

        Scene::update(dt);
    }
    void BouncyRectangles::stop() {
        Scene::stop();
    }
} // MiniMario