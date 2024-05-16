/* date = May 10, 2024 10:07 AM */

#ifndef MINI_MARIO_RECTANGLE_H
#define MINI_MARIO_RECTANGLE_H

#include "Entity.h"

namespace MiniMario {

    class Rectangle : public Entity {
    public:
        Rectangle();
        ~Rectangle() override;

        void render() override;
        void update(double) override;
        // TODO: implement
        void transform(Math::Mat4 &transform) override {}

        Math::Vec4 &getColor();
        void setColor(const Math::Vec4 &c);

    private:
        Math::Vec4 color;
    };

} // MiniMario

#endif //MINI_MARIO_RECTANGLE_H
