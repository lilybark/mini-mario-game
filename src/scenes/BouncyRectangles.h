/* date = May 12, 2024 5:12 PM */

#ifndef MINI_MARIO_BOUNCYRECTANGLES_H
#define MINI_MARIO_BOUNCYRECTANGLES_H

#include "Scene.h"

namespace MiniMario {

    class BouncyRectangles : public Scene {
        void start() override;
        void update(double dt) override;
        void stop() override;
    };

} // MiniMario

#endif //MINI_MARIO_BOUNCYRECTANGLES_H
