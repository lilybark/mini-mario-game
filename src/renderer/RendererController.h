/* date = April 07, 2024 4:13 PM */

#ifndef MINI_MARIO_RENDERERCONTROLLER_H
#define MINI_MARIO_RENDERERCONTROLLER_H


#include "VertexBuffer.h"
#include "math/Mat4.h"

namespace MiniMario {
    namespace Renderer {

        /**
         * Simple renderer class. Currently only supports rendering quads to the screen; this is a 2D Game at the moment.
         */
        class RendererController {
        private:
            RendererController();
            static RendererController *_inst;
            VertexBuffer *vertexBuffer;

            Math::Mat4 projMatrix, viewMatrix;

        public:
            RendererController(RendererController &) = delete;
            ~RendererController();
            static RendererController *get();
            void update(double);
            void close();

            void pushVertex(const float *data);

            void setProjection(Math::Mat4 &mat4);

            void setView(Math::Mat4 &mat4);
        };
    }
}

#endif //MINI_MARIO_RENDERERCONTROLLER_H
