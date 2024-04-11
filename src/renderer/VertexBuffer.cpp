/* date = April 10, 2024 6:50 PM */

#include "VertexBuffer.h"

#include <fstream>
#include <sstream>

namespace MiniMario {
    namespace Renderer {
        VertexBuffer::VertexBuffer(size_t count, const std::vector<LayoutElement> &layout) {
            this->layout = std::vector<LayoutElement>(layout);
            size_t floatsPerVertex = 0;
            for (const auto& el : this->layout) {
                floatsPerVertex += el.count;
            }

            this->vertexData = std::vector<float>(count * floatsPerVertex);


            // the following deals with shader code compilation
            {
                // read vertex shader code
                auto t = std::ifstream("assets/shaders/default.vert");
                std::stringstream buffer;
                buffer << t.rdbuf();
                this->vertexShader = buffer.str();

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
                    exit(-1);
                }
                // and now we have successful compilation!
            }

            // read fragment shader code
            {
                auto t = std::ifstream("assets/shaders/default.frag");
                std::stringstream buffer;
                buffer << t.rdbuf();
                this->fragmentShader = buffer.str();

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
                exit(-1);
            }
        }
    } // Renderer
} // MiniMario