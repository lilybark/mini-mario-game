/* date = May 10, 2024 10:49 AM */

#include "Scene.h"

namespace MiniMario {

    const Entity *Scene::getEntity(size_t id) {
        for (Entity *e : this->entities) {
            if (e && e->getID() == id) {
                return e;
            }
        }

        // TODO: print error
        return nullptr;
    }
} // MiniMario