#include "../include/lupine.h"

int main() {
    const char* name = "name";
    Lupine lupine(name, 800, 600); 
    if(lupine.err == -1) {
        return -1;
    }

    lupine.registerKey(GLFW_KEY_ESCAPE, [&lupine](){ glfwSetWindowShouldClose(lupine.window, true); });

    lupine.registerTriangle(glm::vec3(3,-2,0),glm::vec3(1,-1,0),glm::vec3(-1,-2,0),
            glm::vec3(0,1,1),glm::vec3(1,1,1),glm::vec3(1,1,1));
    lupine.registerTriangle(glm::vec3(3,-2,0),glm::vec3(-3,-2,0),glm::vec3(1,2,0),
            glm::vec3(0,1,1),glm::vec3(1,1,1),glm::vec3(1,1,1));

    while (!glfwWindowShouldClose(lupine.window)) {
        lupine.processInput();

        lupine.background(124, 152, 194, 255);

        lupine.use();

        lupine.render();

        glfwSwapBuffers(lupine.window);
        glfwPollEvents();
    }

    return 0;
}