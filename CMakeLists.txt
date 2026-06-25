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

    src/triangle_mesh.cpp include/triangle_mesh.h
    src/glmath.cpp        include/glmath.h
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
    include/glmath.h        src/glmath.cpp

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