/* date = July 15, 2024 9:34 PM */

#ifndef BOX_H
#define BOX_H
#include "Entity.h"
#include "renderer/RendererController.h"

namespace MiniMario {

    class Box : public Entity, public Renderer::Renderable {
    public:
        Box();
        ~Box() override = default;
        void render() override;
        void update(double dt) override;
        void transform(Math::Mat4 &trans) override {}

        const Math::Vec3 &getPos() const;
        const Math::Vec3 &getScale() const;
        const Math::Vec4 &getColor() const;

        void setPos(const Math::Vec3& pos);
        void setScale(const Math::Vec3& s);
        void setColor(const Math::Vec4& c);

    private:
        // 0, 1, 2, 3 : up +z
        // 0, 4, 5, 1 : back +y
        // 7, 6, 5, 4 : down -z
        // 3, 2, 6, 7 : front -y
        // 2, 1, 5, 6 : left -x
        // 0, 3, 7, 4 : right +x
        constexpr static int boxLayout[36] = {
            3, 2, 0, 0, 2, 1,
            1, 5, 0, 0, 5, 4,
            4, 5, 7, 7, 5, 6,
            7, 6, 3, 3, 6, 2,
            6, 2, 5, 5, 2, 1,
            4, 7, 0, 0, 7, 3,
        };
    };

} // MiniMario

#endif //BOX_H
