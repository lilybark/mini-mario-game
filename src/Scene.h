/* date = May 10, 2024 10:49 AM */

#ifndef MINI_MARIO_SCENE_H
#define MINI_MARIO_SCENE_H

#include <vector>
#include "Entity.h"
#include "renderer/Camera.h"

namespace MiniMario {

    class Scene {
    public:
        virtual void start() {};
        virtual void update(double);
        virtual void stop();

        Renderer::Camera *getCamera();

        virtual ~Scene() = default;
    protected:
        void uploadCamera();

        template<typename T>
        T *spawn() {
            static_assert(std::is_base_of_v<Entity, T>, "template parameter for Scene::spawn is not an Entity type!");

            auto e = new T();
            this->entities.push_back(e);

            return e;
        }

        Renderer::Camera camera{};
        std::vector<Entity *> entities;
        Entity *getEntity(size_t id);
    };

} // MiniMario

#endif //MINI_MARIO_SCENE_H
