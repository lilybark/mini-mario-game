/* date = April 07, 2024 4:13 PM */

#include "RendererController.h"

#include <glad/gl.h>
#include "GLFW/glfw3.h"

namespace MiniMario {
    namespace Renderer {

        RendererController *RendererController::get() {
            if (_inst == nullptr) {
                _inst = new RendererController();
            }

            return _inst;
        }

        void RendererController::update(double) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            this->vertexBuffer->bindArray();
            this->vertexBuffer->bindBuffer();
            this->vertexBuffer->attachShader();

            // buffer thingies
            this->vertexBuffer->uploadMat4("projection", this->projMatrix);
            this->vertexBuffer->uploadMat4("view", this->viewMatrix);
            this->vertexBuffer->uploadFloat("time", (float) glfwGetTime());

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
            this->projMatrix = Math::Mat4::ident();
            this->viewMatrix = Math::Mat4::ident();
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_DEPTH_TEST);

            const auto DEFAULT_LAYOUT = std::vector<VertexBuffer::LayoutElement>{
                    VertexBuffer::LayoutElement{"position", 4},
                    VertexBuffer::LayoutElement{"normal", 3},
                    VertexBuffer::LayoutElement{"color", 4},
                    VertexBuffer::LayoutElement{"texUV", 2},
                    VertexBuffer::LayoutElement{"texID", 1},
                    };

            vertexBuffer = new VertexBuffer(2<<12, DEFAULT_LAYOUT);

        }

        RendererController::~RendererController() {
            delete vertexBuffer;
        }

        void RendererController::pushVertex(const float *data) { this->vertexBuffer->insertVertex(data); }

        void RendererController::pushElementOrder(const int *data, size_t count, size_t vertexOffset) {
            this->vertexBuffer->insertElements(data, count, vertexOffset);
        }

        void RendererController::setProjection(const Math::Mat4 &proj) {
            this->projMatrix = proj;
        }

        void RendererController::setView(const Math::Mat4 &view) {
            this->viewMatrix = view;
        }
    }
}