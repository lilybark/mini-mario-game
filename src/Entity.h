/* date = April 28, 2024 4:18 PM */

#ifndef MINI_MARIO_ENTITY_H
#define MINI_MARIO_ENTITY_H

#include "math/Mat4.h"
#include "math/Vec3.h"

namespace MiniMario {
    /**
     * A virtual class that encapsulates a game object in a limited Entity-Component system (where object functionality
     * is restricted to whatever is defined in this virtual class)
     */
    class Entity {
    public:
        virtual ~Entity();

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
         * @param trans The transformation
         */
        virtual void transform(Math::Mat4 &trans) = 0;

        void translate(const Math::Vec3 &d);
        void moveTo(const Math::Vec3 &d);

        void setRot(const Math::Vec3 &d);

        /**
         * Performs a scaling local to the center of the entity. Under the hood, it resets the `scale` member field.
         * @param s The new scale
         */
        void rescale(const Math::Vec3 &s);

        Math::Vec3 getPos();
        size_t getID();

    protected:
        static size_t _ID;
        Math::Vec3 pos;
        Math::Vec3 scale;
        Math::Vec3 rot;
        size_t id = _ID++;
    };

} // MiniMario

#endif //MINI_MARIO_ENTITY_H
