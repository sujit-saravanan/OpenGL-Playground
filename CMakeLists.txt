cmake_minimum_required(VERSION 3.23.2)

project(OpenGLRetro)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/glfw)
add_library(glad STATIC libs/glad/glad.cpp)
target_include_directories(glad PUBLIC libs/glad/include)

add_library(shaders STATIC libs/shaders/shaders.cpp)
target_include_directories(shaders PUBLIC libs/shaders/include)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)


target_link_libraries(${PROJECT_NAME} PUBLIC glad)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

target_link_libraries(shaders PUBLIC glad)
target_link_libraries(${PROJECT_NAME} PUBLIC shaders)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL)

target_precompile_headers(${PROJECT_NAME} PUBLIC libs/glm/glm.hpp)
target_include_directories(${PROJECT_NAME} PUBLIC libs/glm)