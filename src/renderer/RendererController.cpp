/* date = April 07, 2024 4:13 PM */

#include "RendererController.h"

namespace MiniMario {
    namespace Renderer {

        RendererController *RendererController::get() {
            if (RendererController::_inst == nullptr) {
                _inst = new RendererController();
            }

            return _inst;
        }

        void RendererController::init() {
            // ...
        }

        void RendererController::update(double) {
            // ...
        }

        void RendererController::close() {
            // ...
        }

        RendererController *RendererController::_inst = nullptr;

        RendererController::RendererController() {
            const auto DEFAULT_LAYOUT = std::vector<VertexBuffer::LayoutElement>{
                    VertexBuffer::LayoutElement{"position", 3},
                    VertexBuffer::LayoutElement{"color", 4},
                    VertexBuffer::LayoutElement{"texUV", 2},
                    VertexBuffer::LayoutElement{"texID", 1},
                    };

            vertexBuffer = VertexBuffer(2<<13, DEFAULT_LAYOUT);
        }
    }
}