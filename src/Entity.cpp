/* date = April 28, 2024 4:18 PM */

#include "Entity.h"

namespace MiniMario {
    size_t Entity::_ID = 0;

    void Entity::translate(const Math::Vec3 &d) {
        this->pos += d;
    }

    void Entity::rescale(const Math::Vec3 &s) {
        this->scale = s;
    }

    size_t Entity::getID() {
        return id;
    }
} // MiniMario