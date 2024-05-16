/* date = May 10, 2024 10:49 AM */

#ifndef MINI_MARIO_SCENE_H
#define MINI_MARIO_SCENE_H

#include <vector>
#include "Entity.h"
#include "renderer/Camera.h"

namespace MiniMario {

    class Scene {
    public:
        virtual void start() = 0;
        virtual void update(double) = 0;
        virtual void stop() = 0;
    protected:
        void uploadCamera();

        Renderer::Camera camera{};
        std::vector<Entity *> entities;
        Entity *getEntity(size_t id);
    };

} // MiniMario

#endif //MINI_MARIO_SCENE_H
