#include <cstring>
#include <chrono>
#include "initialize.h"
#include "renderer.h"
#include "physics.h"

#define OPENGL_MAJOR_VERSION 4
#define OPENGL_MINOR_VERSION 5
#define POS_X 0
#define POS_Y 0
#define WIDTH 600
#define HEIGHT 600



int main()
{
    GLFWwindow* window = initializeWindow("OpenGL Base Template", OPENGL_MAJOR_VERSION, OPENGL_MINOR_VERSION);
    initializeOpenGL(POS_X, POS_Y, WIDTH, HEIGHT);
    ma_engine engine;initializeAudio(&engine);
    stbi_set_flip_vertically_on_load(true);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    GLuint VAO;
    generateVAO(&VAO);
    defineVAOAttribute(&VAO, 0, 3, 0, GL_FLOAT, GL_FALSE);
    defineVAOAttribute(&VAO, 1, 2, 3 * sizeof(GLfloat), GL_FLOAT, GL_FALSE);

    GLuint textureShader = LoadShader("../res/shaders/shader.vert", "../res/shaders/shader.frag");

    texture test{};
    generateTexture(&test, "../res/textures/god2.png", GL_LINEAR, GL_REPEAT);

    bool music = true;

    auto currentTick = std::chrono::high_resolution_clock::now();

    float renderTime = 0.0f;
    float physicsTime = 0.0f;
    float deltaTime;
    float totalTime;

    unsigned int renderRate = 120;
    unsigned int physicsRate = 120;

    while (!glfwWindowShouldClose(window))
    {
        totalTime += deltaTime;
        deltaTime = std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now()-currentTick).count();
        renderTime += deltaTime/1000.0f;
        physicsTime += deltaTime/1000.0f;
        currentTick = std::chrono::high_resolution_clock::now();

        glfwPollEvents();
        while (physicsTime >= 1.0f/static_cast<float>(physicsRate)){
            update(window, physicsTime);

            physicsTime -= 1.0f/static_cast<float>(physicsRate);
        }

        glm::mat4 vp = proj * view;

        if(music){
            ma_engine_play_sound(&engine, "../res/audio/music/godiscoming.mp3", nullptr);
            std::cout << "playing ../res/audio/music/godiscoming.mp3" << std::endl;
            music = false;
        }

        while (renderTime >= 1.0/static_cast<float>(renderRate)){
            glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);
            renderTime -= 1.0f/static_cast<float>(renderRate);
        }


    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}