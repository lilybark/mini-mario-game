/* date = July 15, 2024 7:33 PM */

#include "Component.h"

namespace MiniMario {
    const Math::Vec3 &Transform::getPos() const { return pos; }
    void Transform::translate(const Math::Vec3 &dr) { this->pos += dr; }
    void Transform::moveTo(const Math::Vec3 &r) { this->pos = r; }

    const Math::Vec3 &Transform::getScale() const { return whd; }
    void Transform::deform(const Math::Vec3 &dv) { this->whd += dv; }
    void Transform::setScale(const Math::Vec3 &v) { this->whd = v; }

    const Math::Vec4 &Color::getColor() const { return this->color; }
    void Color::setColor(const Math::Vec4 &c) { this->color = c; }


} // MiniMario