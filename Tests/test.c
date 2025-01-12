#include <GLFW/glfw3.h>

#include "Graphics/GLFW_standart_functions.h"
#include "Graphics/Draw.h"

#include <stdio.h>

int main(int argc, char** argv)
{
	glfwInit();

	GLFWmonitor* monitor  = glfwGetPrimaryMonitor();

	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "My Title", monitor, NULL);

	glfwMakeContextCurrent(window);

	//glfwSetFramebufferSizeCallback(window,&glfw_framebuffer_size_callback);

	glMatrixMode(GL_PROJECTION);
	glOrtho(0,mode->width,0,mode->height,-1,-1);
	glMatrixMode(GL_MODELVIEW);
	
	printf("width: %d\nheight: %d\n",mode->width,mode->height);

	struct Transform transform = {{0,0},{0,0}};
	int width = 100;
	//create test checker image
	
	


	while (!glfwWindowShouldClose(window))
    	{
        	/* Render here */
        	glClear(GL_COLOR_BUFFER_BIT);

		//DrawRectangle(&width,&height,&transform);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
		glBegin(GL_TRIANGLE_FAN);


		glVertex2f(0,0.5f);
		glVertex2f(0.5f,0);
		glVertex2f(0,-0.5f);
		glVertex2f(-0.5f,0);

		glEnd();


        	/* Swap front and back buffers */
        	glfwSwapBuffers(window);

        	/* Poll for and process events */
        	glfwPollEvents();
    	}

	return 0;
}
