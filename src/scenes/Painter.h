//
// Created by meili on 6/1/2024.
//

#ifndef MINI_MARIO_PAINTER_H
#define MINI_MARIO_PAINTER_H

#include "Scene.h"

namespace MiniMario {

    class Painter : public Scene {
    public:
        void start() override;
        void update(double) override;
        void stop() override;
    private:
        Math::Vec4 currentColor;
    };

} // MiniMario

#endif //MINI_MARIO_PAINTER_H
