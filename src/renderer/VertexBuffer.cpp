/* date = April 10, 2024 6:50 PM */

#include "VertexBuffer.h"

#include <fstream>
#include <iostream>
#include <cstring>

namespace MiniMario {
    namespace Renderer {
        VertexBuffer::VertexBuffer(size_t count, const std::vector<LayoutElement> &layout) {
            this->layout = std::vector<LayoutElement>(layout);
            size_t floatsPerVertex = 0;
            for (const auto& el : this->layout) {
                floatsPerVertex += el.count;
            }

            this->vertexData = (float *) malloc(count * floatsPerVertex * sizeof(float));

            this->elementData = (int *) malloc(count * 6 / 4 * sizeof(int));

            // create OpenGL buffer objects
            glGenBuffers(1, &this->vbo);
            glGenBuffers(1, &this->ebo);
            glGenVertexArrays(1, &this->vao);

            // the following deals with shader code compilation
            {
                // read vertex shader code

                // open file
                auto t = std::ifstream("../assets/shaders/default.vert");

                if (t.bad()) {
                    // could not find file, quitting!
                    std::cout << "Couldn't find vertex file!" << std::endl;
                    exit(-1);
                }


                std::filebuf *t_buffer = t.rdbuf();

                // get file size
                std::size_t size = t_buffer->pubseekoff(0, std::ifstream::end, std::ifstream::in);
                t_buffer->pubseekpos(0, std::ifstream::in);

                // create string from file contents
                char *f_buffer = new char[size];
                t_buffer->sgetn(f_buffer, static_cast<std::streamsize>(size));
                this->vertexShader = std::string(f_buffer);
                delete[] f_buffer;

                //std::cout << "Vertex shader code: " << std::endl << vertexShader << std::endl;

                this->vertexID = glCreateShader(GL_VERTEX_SHADER);

                // compile vertex shader code
                // TODO: we can have a message here that prints what shader we're compiling

                int vertexLength = (int) this->vertexShader.length();
                const char *vertexCodePtr = (const char *) this->vertexShader.c_str();
                glShaderSource(this->vertexID, 1,
                               &vertexCodePtr, &vertexLength);

                glCompileShader(this->vertexID);

                GLint result = GL_FALSE;
                GLint logLength = 0;
                glGetShaderiv(this->vertexID, GL_COMPILE_STATUS, &result);
                glGetShaderiv(this->vertexID, GL_INFO_LOG_LENGTH, &logLength);

                // if gl has something to say, we better listen
                if (logLength > 0) {
                    std::vector<char> errorMessage(logLength + 1);
                    glGetShaderInfoLog(this->vertexID, logLength, nullptr, errorMessage.data());
                    // TODO: this is a great place to print the error message!!
                    std::cout << std::string(errorMessage.data()) << std::endl;
                    exit(-1);
                }
                // and now we have successful compilation!
            }

            // read fragment shader code
            {
                // open file
                auto t = std::ifstream("../assets/shaders/default.frag");
                std::filebuf *t_buffer = t.rdbuf();

                // get file size
                std::size_t size = t_buffer->pubseekoff(0, std::ifstream::end, std::ifstream::in);
                t_buffer->pubseekpos(0, std::ifstream::in);

                // create string from file contents
                char *f_buffer = new char[size];
                t_buffer->sgetn(f_buffer, static_cast<std::streamsize>(size));
                this->fragmentShader = std::string(f_buffer);
                delete[] f_buffer;

                // compile fragment shader
                // TODO: this is also a great place to have a logging message

                this->fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

                int fragmentLength = (int) this->fragmentShader.length();
                const char* fragmentCodePtr = (const char *) this->fragmentShader.c_str();
                glShaderSource(this->fragmentID, 1,
                               &fragmentCodePtr, &fragmentLength);

                glCompileShader(this->fragmentID);

                GLint result = GL_FALSE;
                GLint logLength = 0;
                glGetShaderiv(this->fragmentID, GL_COMPILE_STATUS, &result);
                glGetShaderiv(this->fragmentID, GL_INFO_LOG_LENGTH, &logLength);

                if (logLength > 0) {
                    std::vector<char> errorMessage(logLength + 1);
                    glGetShaderInfoLog(this->fragmentID, logLength, nullptr, errorMessage.data());
                    // TODO: this is an excellent place to print errorMessage!
                    // MeiLi, your logging library would be great here!
                    std::cout << std::string(errorMessage.data()) << std::endl;
                    exit(-1);
                }
            }

            // now that we've compiled our shaders, lets create our zipped program!
            this->programID = glCreateProgram();
            glAttachShader(this->programID, this->vertexID);
            glAttachShader(this->programID, this->fragmentID);

            glLinkProgram(this->programID);

            GLint result = GL_FALSE;
            GLint logLength = 0;
            glGetShaderiv(this->programID, GL_COMPILE_STATUS, &result);
            glGetShaderiv(this->programID, GL_INFO_LOG_LENGTH, &logLength);

            if (logLength > 0) {
                std::vector<char> errorMessage(logLength + 1);
                glGetShaderInfoLog(this->programID, logLength, nullptr, errorMessage.data());
                // TODO: this is an excellent place to print errorMessage!
                // MeiLi, your logging library would also be great here!
                std::cout << std::string(errorMessage.data()) << std::endl;
                exit(-1);
            }
        }

        void VertexBuffer::bindBuffer() const {
            glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
        }

        void VertexBuffer::uploadBuffer() {
            glBufferData(GL_ARRAY_BUFFER,
                         static_cast<long>(this->numVertices*10*sizeof(float)),
                         this->vertexData,
                         GL_DYNAMIC_DRAW);

            // every triangle has three vertices. when rendering a quad, we're working with four contiguous vertices.
            this->elementCount = 0;

            for (int i = 0; i < this->numVertices / 4; i++) {
                this->elementData[i*6]   = (3 + i*6);
                this->elementData[i*6+1] = (2 + i*6);
                this->elementData[i*6+2] = (0 + i*6);
                this->elementData[i*6+3] = (0 + i*6);
                this->elementData[i*6+4] = (2 + i*6);
                this->elementData[i*6+5] = (1 + i*6);

                this->elementCount += 6;
            }

            glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                         static_cast<long>(this->numVertices / 4 * 6 * sizeof(int)),
                         this->elementData,
                         GL_DYNAMIC_DRAW);
        }

        void VertexBuffer::insertVertex(const float *data) {
            // TODO: function that queries number of floats per vertex in place of "10" literal
            size_t floatOffset = numVertices * 10;
            // note that pointer arithmetic here implicitly resizes floatOffset by a factor of sizeof(float)
            memcpy((float *) this->vertexData + floatOffset, data, 10*sizeof(float));

            this->numVertices++;
        }

        void VertexBuffer::attachShader() const {
            glUseProgram(this->programID);
        }

        void VertexBuffer::bindArray() const {
            glBindVertexArray(this->vao);
        }

        void VertexBuffer::enableAttributes() {
            size_t offset = 0;
            for (int i = 0; i < this->layout.size(); i++) {
                glVertexAttribPointer(i,
                                      (GLint) (this->layout[i].count),
                                      GL_FLOAT,
                                      GL_TRUE,
                                      10*sizeof(float),
                                      (void *) offset);
                glEnableVertexAttribArray(i);
                offset += this->layout[i].count * sizeof(float);
            }
        }

        void VertexBuffer::render() const {
            glDrawElements(GL_TRIANGLES, (GLint) this->elementCount, GL_UNSIGNED_INT, nullptr);
        }

        void VertexBuffer::disableAttributes() {
            for (int i = 0; i < this->layout.size(); i++) {
                glDisableVertexAttribArray(i);
            }
        }

        void VertexBuffer::unbind() {
            glUseProgram(0);
            glBindVertexArray(0);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        void VertexBuffer::clear() {
            this->elementCount = 0;
            this->numVertices = 0;
        }


    } // Renderer
} // MiniMario