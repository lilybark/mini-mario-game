/* date = May 12, 2024 5:12 PM */

#include <cstdio>
#include "BouncyRectangles.h"
#include "entities/Rectangle.h"

namespace MiniMario {
    const float rectWidth = 0.2;
    void BouncyRectangles::start() {
        // create rectangles!
        int numLeftRight = 5;
        int numUpDown = 5;

        float horizSpacing = 0.8f / ((static_cast<float>(numLeftRight) - 1) / 2.0f);
        float vertSpacing = 0.8f / ((static_cast<float>(numUpDown) - 1) / 2.0f);

        this->camera.moveTo({0.0, 0.0, 0.1});

        for (int z = 0; z < 10; z++) {
            for (int i = 0; i < numLeftRight; i++) {
                for (int j = 0; j < numUpDown; j++) {
                    auto *r = new Rectangle();

                    r->moveTo({
                                      static_cast<float>(-0.8 + horizSpacing * i),
                                      static_cast<float>(-0.8 + vertSpacing * j),
                                      -2.0f+z*0.2f});
                    r->rescale({rectWidth, rectWidth, 0.5});
                    Math::Vec4 newColor = {
                            r->getPos()[0],
                            r->getPos()[1],
                            r->getPos()[2],
                            1.0
                    };
                    newColor = (newColor + Math::Vec4(1.0)) / 2.0;
                    r->setColor(newColor);

                    this->entities.push_back(r);
                }
            }
        }
    }

    void BouncyRectangles::update(double dt) {
        static double acc = 0;
        acc += dt;

        this->camera.moveTo({(float)cos(acc), (float)sin(acc), (float)sin(2*acc)*2.0f+1.0f});

        // make them bounce!
        this->uploadCamera();

        for (Entity *e : this->entities) {
            //e->rescale({rectWidth, static_cast<float>(rectWidth * sin(acc)), rectWidth});

            e->update(dt);
        }
    }
    void BouncyRectangles::stop() {
        // delete rectangles!
        for (Entity *e : this->entities) {
            delete e;
        }
    }
} // MiniMario