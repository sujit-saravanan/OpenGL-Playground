#include "physics.h"

glm::mat4 proj  = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
glm::mat4 view  = glm::translate(glm::mat4(1.0f), glm::vec3(0, 1, 0));

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void update(GLFWwindow* window, float physicsTime){
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        std::cout << "Key W has been pressed\n";
    }
}