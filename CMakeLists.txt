cmake_minimum_required(VERSION 3.10)

project(mini-mario)

find_package(OpenGL REQUIRED)
find_package(Threads REQUIRED)

add_subdirectory(vendor/glfw)

add_executable(mini-mario
        src/App.cpp
        src/App.h
        src/main.cpp
        src/renderer/RendererController.cpp
        src/renderer/RendererController.h

        # instead of creating a whole new target for glad vendors, it may be wise just to include them here.
        vendor/glad/include/glad/gl.h
        vendor/glad/include/KHR/khrplatform.h
        vendor/glad/src/gl.c
        src/renderer/VertexBuffer.cpp
        src/renderer/VertexBuffer.h
        src/Entity.cpp
        src/Entity.h
        src/math/Mat4.cpp
        src/math/Mat4.h
        src/math/Vec4.cpp
        src/math/Vec4.h
        src/math/Vec3.cpp
        src/math/Vec3.h
        src/math/SquareMatrix.h
        src/math/Vector.h
        src/entities/Rectangle.cpp
        src/entities/Rectangle.h
        src/Scene.cpp
        src/Scene.h
        src/renderer/Camera.cpp
        src/renderer/Camera.h
        src/scenes/BouncyRectangles.cpp
        src/scenes/BouncyRectangles.h
        src/input/Keyboard.cpp
        src/input/Keyboard.h
        src/scenes/Painter.cpp
        src/scenes/Painter.h
        src/input/Mouse.cpp
        src/input/Mouse.h
        src/math/Vec2.cpp
        src/math/Vec2.h
        src/scenes/BoxedIn.cpp
        src/scenes/BoxedIn.h
        src/Component.cpp
        src/Component.h
        src/entities/Box.cpp
        src/entities/Box.h
        src/math/Mat3.cpp
        src/math/Mat3.h
)

set_target_properties(mini-mario PROPERTIES POSITION_INDEPENDENT_CODE True)
set_target_properties(mini-mario PROPERTIES LINKER_LANGUAGE CXX)

target_compile_features(mini-mario INTERFACE cxx_std_11)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(mini-mario INTERFACE
        "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

target_link_libraries(mini-mario glfw)

target_include_directories(mini-mario PUBLIC
        "${CMAKE_SOURCE_DIR}/src"
        "${CMAKE_SOURCE_DIR}/vendor/glad/include"
        "${CMAKE_SOURCE_DIR}/vendor/glfw/include"
)
