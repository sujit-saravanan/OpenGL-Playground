#include "include/initialize.h"
#include "GLDebugMessageCallback.hpp"


void setWindowHints(int major, int minor){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
GLFWwindow* initializeWindow(const char* title, int major, int minor){
    setWindowHints(major, minor);

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, title, glfwGetPrimaryMonitor(), nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    glfwSwapInterval( 0 );

    return window;
}
void initializeOpenGL(int posX, int posY, int width, int height){
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(GLDebugMessageCallback, nullptr);
    glViewport(posX, posY, width, height);
}
void initializeAudio(ma_engine* engine){
    ma_result result = ma_engine_init(nullptr, engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine.");
    }
}