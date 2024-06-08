//
// Created by meili on 6/8/2024.
//

#ifndef MINI_MARIO_BOXEDIN_H
#define MINI_MARIO_BOXEDIN_H

#include "Scene.h"

namespace MiniMario {

    class BoxedIn : public Scene {
    public:
        void start() override;
        void update(double) override;
        void stop() override;
    };

} // MiniMario

#endif //MINI_MARIO_BOXEDIN_H
