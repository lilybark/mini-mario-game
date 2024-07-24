/* date = April 28, 2024 4:18 PM */

#include "Entity.h"

namespace MiniMario {
    size_t Entity::ID = 0;

    size_t Entity::getID() const {
        return id;
    }

    /*
    void Entity::translate(const Math::Vec3 &d) {
        this->pos += d;
    }

    void Entity::rescale(const Math::Vec3 &s) {
        this->scale = s;
    }

    Entity::~Entity() = default;

    void Entity::moveTo(const Math::Vec3 &d) {
        this->pos = d;
    }

    Math::Vec3 Entity::getPos() const {
        return this->pos;
    }

    void Entity::setRot(const Math::Vec3 &d) {
        this->rot = d;
    }
    */
} // MiniMario