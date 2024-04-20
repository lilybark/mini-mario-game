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

            void bindBuffer() const;

            void uploadBuffer();

            void insertVertex(const float *data); // dubious; can easily lead to UB if data isn't allocated long enough.

            void attachShader() const;

            void bindArray() const;

            void enableAttributes();

            void render() const;

            void disableAttributes();

            void unbind();

            void clear();

        private:
            // raw vertex data
            float *vertexData;
            // this plus the layout tells you the length of the vertex data.
            size_t numVertices{};
            // the ordering of the vertices
            int *elementData;
            // the data layout of a single vertex
            std::vector<LayoutElement> layout;
            // the GLSL code for processing vertices
            std::string vertexShader;
            // the GLSL code for rendering triangles
            std::string fragmentShader;

            GLuint vao{}, vbo{}, ebo{}, programID{}, vertexID{}, fragmentID{};
            size_t elementCount{};
        };

    } // Renderer
} // MiniMario

#endif //MINI_MARIO_VERTEXBUFFER_H
