/* date = April 10, 2024 6:50 PM */

#ifndef MINI_MARIO_VERTEXBUFFER_H
#define MINI_MARIO_VERTEXBUFFER_H

#include <vector>
#include <string>
#include "glad/gl.h"

namespace MiniMario {
    namespace Renderer {
        /**
         * A class that stores vertex data, shader data, and layout information.
         */
        class VertexBuffer {
        public:
            /**
             * A helper class for declaring the layout of a VertexBuffer's data.
             */
            class LayoutElement {
            public:
                std::string name;
                size_t count;
            };

            /**
             * Creates an empty vertex buffer with no layout.
             * This is not advised, stick with the explicitly-sized constructor.
             */
            VertexBuffer() = default;

            /**
             * Creates a Vertex Buffer with `count` vertices and a given layout. Note that the size of the vertexData
             * float array is equal to count * (sum of layout counts).
             */
            VertexBuffer(size_t count, const std::vector<LayoutElement> &layout);
        private:
            // raw vertices
            std::vector<float> vertexData;
            // the ordering of the vertices
            std::vector<size_t> elementData;
            // the data layout of a single vertex
            std::vector<LayoutElement> layout;
            // the GLSL code for processing vertices
            std::string vertexShader;
            // the GLSL code for rendering triangles
            std::string fragmentShader;

            GLuint vao, vbo, ibo, programID, vertexID, fragmentID;
        };

    } // Renderer
} // MiniMario

#endif //MINI_MARIO_VERTEXBUFFER_H
