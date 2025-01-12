#include <GL/gl.h>

#include <GLFW/glfw3.h>
#include "Graphics/GLFW_standart_functions.h"
#include <stdio.h>

void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
