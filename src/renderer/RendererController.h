/* date = April 07, 2024 4:13 PM */

#ifndef MINI_MARIO_RENDERERCONTROLLER_H
#define MINI_MARIO_RENDERERCONTROLLER_H


#include "VertexBuffer.h"

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

        public:
            RendererController(RendererController &) = delete;
            ~RendererController();
            static RendererController *get();
            void update(double);
            void close();
        };
    }
}

#endif //MINI_MARIO_RENDERERCONTROLLER_H
