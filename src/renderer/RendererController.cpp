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

        void RendererController::update(double) {
            // push vertices
            float verts[40] = {
                    .5, .5, .0, 0., 0., 1., 1., 0., 0., 0.,
                    -.5, .5, .0, 0., 1., 0., 1., 0., 0., 0.,
                    -.5, -.5, .0, 1., 0., 0., 1., 0., 0., 0.,
                    .5, -.5, .0, 1., 1., 0., 1., 0., 0., 0.,
            };

            for (int i = 0; i < 4; i++) {
                this->vertexBuffer->insertVertex((&verts[0]) + i*10);
            }

            this->vertexBuffer->bindArray();
            this->vertexBuffer->bindBuffer();
            this->vertexBuffer->attachShader();

            this->vertexBuffer->bindArray();
            this->vertexBuffer->enableAttributes();

            // TODO: shader uniforms and textures

            this->vertexBuffer->bindArray();
            this->vertexBuffer->bindBuffer();
            this->vertexBuffer->uploadBuffer();

            this->vertexBuffer->render();

            this->vertexBuffer->disableAttributes();

            this->vertexBuffer->unbind();

            this->vertexBuffer->clear();
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

            vertexBuffer = new VertexBuffer(2<<12, DEFAULT_LAYOUT);
        }

        RendererController::~RendererController() {
            delete vertexBuffer;
        }
    }
}