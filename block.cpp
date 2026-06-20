#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Simple Vector3 struct
struct Vector3 {
    float x, y, z;
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};

void RenderBlock(Vector3 position, float length, float height, float width) {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);

    glBegin(GL_QUADS);

    // Front face
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f( length, -height, -width);
    glVertex3f(-length, -height, -width);
    glVertex3f(-length,  height, -width);
    glVertex3f( length,  height, -width);

    // Back face
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-length, -height, width);
    glVertex3f( length, -height, width);
    glVertex3f( length,  height, width);
    glVertex3f(-length,  height, width);

    // Right face
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(length, -height,  width);
    glVertex3f(length, -height, -width);
    glVertex3f(length,  height, -width);
    glVertex3f(length,  height,  width);

    // Left face
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-length, -height, -width);
    glVertex3f(-length, -height,  width);
    glVertex3f(-length,  height,  width);
    glVertex3f(-length,  height, -width);

    // Bottom face
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-length, -height, -width);
    glVertex3f( length, -height, -width);
    glVertex3f( length, -height,  width);
    glVertex3f(-length, -height,  width);

    // Top face
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f( length, height, -width);
    glVertex3f(-length, height, -width);
    glVertex3f(-length, height,  width);
    glVertex3f( length, height,  width);

    glEnd();
    glPopMatrix();
}

int main() {
    // Init GLFW
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(800, 600, "Voxel Engine", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }
    glfwMakeContextCurrent(window);

    // Init GLEW
    glewInit();

    // Basic OpenGL setup
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Simple perspective: 60 degree FOV
    float aspect = 800.0f / 600.0f;
    float fov = 1.0f; // roughly 60 degrees in radians
    glFrustum(-aspect * fov, aspect * fov, -fov, fov, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        // Move camera back so we can see the block
        glTranslatef(0.0f, 0.0f, -5.0f);

        // Render a block at origin
        RenderBlock(Vector3(0.0f, 0.0f, 0.0f), 0.5f, 0.5f, 0.5f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}