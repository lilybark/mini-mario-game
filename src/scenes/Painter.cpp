//
// Created by meili on 6/1/2024.
//

#include "Painter.h"
#include "input/Keyboard.h"
#include "entities/Rectangle.h"

namespace MiniMario {
    void Painter::start() {

        auto *r = new Rectangle();
        r->setColor({1.0,1.0,1.0,1.0});
        r->moveTo({0.0, 0.0, -2.0});
        r->rescale({0.5, 0.5, 0.5});

        this->entities.push_back(r);

        this->camera.moveTo({0.0, 0.0, 0.1});
    }

    void Painter::update(double dt) {
        const float SPEED = 3.0;

        auto *r = dynamic_cast<Rectangle *>(entities[0]);
        if (Keyboard::isPressed(Keyboard::Key::W)) {
            r->translate({0.0,(float) dt*SPEED,0.0});
        }
        if (Keyboard::isPressed(Keyboard::Key::S)) {
            r->translate({0.0, (float) -dt*SPEED, 0.0});
        }
        if (Keyboard::isPressed(Keyboard::Key::A)) {
            r->translate({(float) -dt*SPEED,0.0,0.0});
        }
        if (Keyboard::isPressed(Keyboard::Key::D)) {
            r->translate({(float) dt*SPEED,0.0,0.0});
        }
        this->uploadCamera();

        for (Entity *e : this->entities) {
            e->update(dt);
        }
    }

    void Painter::stop() {

    }
} // MiniMario