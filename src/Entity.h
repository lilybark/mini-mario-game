/* date = April 28, 2024 4:18 PM */

#ifndef MINI_MARIO_ENTITY_H
#define MINI_MARIO_ENTITY_H

#include <cstdio>
#include <vector>


#include "math/Mat4.h"
#include "math/Vec3.h"

namespace MiniMario {
    class Component;
    /**
     * A virtual class that encapsulates a game object in a limited Entity-Component system (where object functionality
     * is restricted to whatever is defined in this virtual class)
     */
    class Entity {
    public:
        virtual ~Entity() = default;

        /**
         * Draw this entity to the screen.
         */
        virtual void render() = 0;
        /**
         * Perform update logic on entity.
         *
         * @param dt A change in time between the last update call and the current one.
         */
        virtual void update(double dt) = 0;
        /**
         * Performs an arbitrary 4x4 matrix transformation on this entity.
         * TODO: This transformation will take the SVD of the upper 3x3 matrix part, and scale/rotate with that part.
         *
         * @param trans The transformation
         */
        virtual void transform(Math::Mat4 &trans) = 0;

        /*
        void translate(const Math::Vec3 &d);

        void moveTo(const Math::Vec3 &d);

        void setRot(const Math::Vec3 &d);

        /**
         * Performs a scaling local to the center of the entity. Under the hood, it resets the `scale` member field.
         * @param s The new scale
          /
        void rescale(const Math::Vec3 &s);
        */

        size_t getID() const;

    protected:
        static size_t ID;
        size_t id = ID++;

        Entity() = default;

        template<typename T>
        void addComponent(T *c) {
            static_assert(std::is_base_of_v<Component, T>, "cannot add non-component type to an entity.");
            this->comps.push_back(dynamic_cast<Component *>(c));
        }

        template<typename T>
        T &getComponent() {
            static_assert(std::is_base_of_v<Component, T>, "cannot get non-component type from an entity.");
            for (auto &c : comps) {
                auto cast = dynamic_cast<T*>(c);
                if (cast != nullptr) {
                    return *cast;
                }
            }

            // TODO: better errors!
            fprintf(stderr, "bad component get!!");
            exit(-1);
        }

        template<typename T>
        const T &getComponent() const {
            static_assert(std::is_base_of_v<Component, T>, "cannot get non-component type from an entity.");
            for (const auto &c : comps) {
                auto cast = dynamic_cast<const T*>(c);
                if (cast != nullptr) {
                    return *cast;
                }
            }

            // TODO: better errors!
            fprintf(stderr, "bad component get!!");
            exit(-1);
        }

        std::vector<Component *> comps;
    };

} // MiniMario

#endif //MINI_MARIO_ENTITY_H
