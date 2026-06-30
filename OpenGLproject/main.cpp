#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>


int main() {

	// initialize the window
	glfwInit();

	//glfw needs these 'hints' to know version, and profile (core)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// (parameters of making a window (in order):
	//width, height, name, full screen?, idk 
	GLFWwindow* window = glfwCreateWindow(800, 800, "openglwindow", NULL, NULL);

	if(window == NULL) // error check incase window fails to create
		{
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
		}

	//contexts tells which functions (the following) should apply to what window
	glfwMakeContextCurrent(window);


	gladLoadGL(); //load needed configs for openGL

	glViewport(0, 0, 800, 800); //area of window opengl renders!

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f); //1st 3 nums colour, last transparency
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);


//since it terminates instantly, while loop keeps it runningtill user ends it themselves!
	while (!glfwWindowShouldClose(window)) 
	{
		//allows window to handle things like resise, and input possiblu
		glfwPollEvents();
	}

	glfwDestroyWindow(window); //destroys the current window u got
	
	glfwTerminate(); //termintates everything glfw related

	return 0;
}