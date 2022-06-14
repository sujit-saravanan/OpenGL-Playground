cmake_minimum_required(VERSION 3.23.2)

project(OpenGLRetro)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/glfw)

add_library(glad STATIC libs/glad/glad.cpp)
target_include_directories(glad PUBLIC libs/glad/include)

add_library(glm STATIC libs/glm/glm.cpp)
target_include_directories(glm PUBLIC libs/glm)

add_library(shaders STATIC libs/shaders/shaders.cpp)
target_include_directories(shaders PUBLIC libs/shaders/include)

add_library(miniaudio STATIC libs/miniaudio/miniaudio.c)
target_include_directories(miniaudio PUBLIC libs/miniaudio/include)

add_library(gldebug STATIC libs/debug/GLDebugMessageCallback.cpp)
target_include_directories(gldebug PUBLIC libs/debug/include)

add_library(stb_image STATIC libs/stb_image/stb_image.cpp)
target_include_directories(stb_image PUBLIC libs/stb_image/include)

add_library(initialize STATIC libs/initialize/initialize.cpp)
target_include_directories(initialize PUBLIC libs/initialize/include)

add_library(renderer STATIC libs/renderer/renderer.cpp)
target_include_directories(renderer PUBLIC libs/renderer/include)

add_library(physics STATIC libs/input/physics.cpp)
target_include_directories(physics PUBLIC libs/input/include)


add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)



find_package(OpenGL REQUIRED)
target_link_libraries(shaders PUBLIC glad)
target_link_libraries(gldebug PUBLIC glad)
target_link_libraries(physics PUBLIC glad)
target_link_libraries(physics PUBLIC glfw)
target_link_libraries(physics PUBLIC renderer)


target_link_libraries(initialize PUBLIC miniaudio)
target_link_libraries(initialize PUBLIC gldebug)

target_link_libraries(renderer PUBLIC glm)
target_link_libraries(renderer PUBLIC stb_image)
target_link_libraries(renderer PUBLIC shaders)



target_link_libraries(${PROJECT_NAME} PUBLIC glad)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glm)
target_link_libraries(${PROJECT_NAME} PUBLIC miniaudio)
target_link_libraries(${PROJECT_NAME} PUBLIC stb_image)
target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL)
target_link_libraries(${PROJECT_NAME} PUBLIC initialize)
target_link_libraries(${PROJECT_NAME} PUBLIC renderer)
target_link_libraries(${PROJECT_NAME} PUBLIC physics)
