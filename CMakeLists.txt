cmake_minimum_required(VERSION 3.20)
project(opengl_engine_01)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add OpenGL for graphics
find_package(OpenGL REQUIRED)


# Add GoogleTest for testing
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# Main project build
add_executable(opengl_engine_01
    src/main.cpp
    include/glad/glad.c
    include/config.h

    #glmath
    src/glmath/glmath.cpp       include/glmath/glmath.h

    src/glmath/vec2.cpp         include/glmath/vec2.h
    src/glmath/vec3.cpp         include/glmath/vec3.h
    src/glmath/vec4.cpp         include/glmath/vec4.h
    src/glmath/vec_functions.cpp        include/glmath/vec_functions.h

    src/glmath/mat2.cpp         include/glmath/mat2.h
    src/glmath/mat3.cpp         include/glmath/mat3.h
    src/glmath/mat4.cpp         include/glmath/mat4.h
    src/glmath/mat_functions.cpp        include/glmath/mat_functions.h


    # Model
    src/Model/mesh.cpp          include/Model/mesh.h
    src/Model/object.cpp        include/Model/object.h
    src/Model/transform.cpp     include/Model/transform.h
    src/Model/meshes_manager.cpp        include/Model/meshes_manager.h


    # View
    src/View/camera.cpp         include/View/camera.h
    src/View/render.cpp         include/View/render.h
    src/View/shader.cpp         include/View/shader.h


    
    # Controller
    src/Controller/engine.cpp   include/Controller/engine.h
    src/Controller/input.cpp    include/Controller/input.h
)
target_include_directories(opengl_engine_01 PRIVATE include)



target_link_libraries(opengl_engine_01
    OpenGL::GL
    glfw
)


# Setup testing 
# Glmath
enable_testing()
add_executable(GLmath_UnitTest
    #glmath
    src/glmath/glmath.cpp       include/glmath/glmath.h

    src/glmath/vec2.cpp         include/glmath/vec2.h
    src/glmath/vec3.cpp         include/glmath/vec3.h
    src/glmath/vec4.cpp         include/glmath/vec4.h
    src/glmath/vec_functions.cpp        include/glmath/vec_functions.h

    src/glmath/mat2.cpp         include/glmath/mat2.h
    src/glmath/mat3.cpp         include/glmath/mat3.h
    src/glmath/mat4.cpp         include/glmath/mat4.h
    src/glmath/mat_functions.cpp        include/glmath/mat_functions.h


    # Tests
    tests/glmath_tests/mat2_test.cpp
    tests/glmath_tests/mat3_test.cpp
    tests/glmath_tests/mat4_test.cpp

    tests/glmath_tests/vec2_test.cpp
    tests/glmath_tests/vec3_test.cpp
    tests/glmath_tests/vec4_test.cpp


)

target_include_directories(GLmath_UnitTest PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(GLmath_UnitTest GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(GLmath_UnitTest)