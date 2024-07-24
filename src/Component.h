/* date = July 15, 2024 7:33 PM */

#ifndef COMPONENT_H
#define COMPONENT_H
#include <type_traits>

#include "math/Vec3.h"

namespace MiniMario {

    /**
     * An interface meant to
     *
     */
    class Component {
    public:
        virtual void start() = 0;
        virtual void update(double) = 0;
        virtual void stop() = 0;
        virtual ~Component() = default;
        Component() = default;
    };

    class Transform : public Component {
    public:
        void start() override {}
        void update(double) override {}
        void stop() override {}

        const Math::Vec3 &getPos() const;
        void translate(const Math::Vec3 &dr);
        void moveTo(const Math::Vec3 &r);

        const Math::Vec3 &getScale() const;
        void deform(const Math::Vec3 &dv);
        void setScale(const Math::Vec3 &v);

        // Rotations are a TODO
    protected:
        Math::Vec3 pos, whd, rot;
    };

    class Color : public Component {
    public:
        Color() : color({0.0, 0.0, 0.0, 0.0}) {}
        void start() override {}
        void update(double) override {}
        void stop() override {}

        const Math::Vec4 &getColor() const;
        void setColor(const Math::Vec4 &c);

        // for ergonomic's sake, I'm leaving this public
        union {
            struct {
                float r{}, g{}, b{}, a{};
            };
            Math::Vec4 color;
        };

    };

    template<typename T>
    class ComponentFactory {
    public:

        static T *generate() {
            static_assert(std::is_base_of_v<Component, T>, "type parameter of this class must derive from Component");
            return new T();
        }

        ComponentFactory operator=(ComponentFactory& other) = delete;

    private:
        ComponentFactory() = default;
        friend class Component;
    };

} // MiniMario

#endif //COMPONENT_H
