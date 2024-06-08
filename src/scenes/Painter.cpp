//
// Created by meili on 6/1/2024.
//

#include "Painter.h"
#include "input/Keyboard.h"
#include "entities/Rectangle.h"
#include "input/Mouse.h"

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
        using Key = Keyboard::Key;

        auto *r = dynamic_cast<Rectangle *>(entities[0]);
        if (Keyboard::isPressed(Key::W)) {
            r->translate({0.0,(float) dt*SPEED,0.0});
        }
        if (Keyboard::isPressed(Key::S)) {
            r->translate({0.0, (float) -dt*SPEED, 0.0});
        }
        if (Keyboard::isPressed(Key::A)) {
            r->translate({(float) -dt*SPEED,0.0,0.0});
        }
        if (Keyboard::isPressed(Key::D)) {
            r->translate({(float) dt*SPEED,0.0,0.0});
        }
        using Button = Mouse::Button;

        if (Mouse::isPressed(Button::LEFT)) {
            r->setColor({1.0f, 0.0f, 0.0f, 1.0f});
        } else {
            r->setColor({1.0f, 1.0f, 1.0f, 1.0f});
        }


        this->uploadCamera();

        for (Entity *e : this->entities) {
            e->update(dt);
        }
    }

    void Painter::stop() {

    }
} // MiniMario