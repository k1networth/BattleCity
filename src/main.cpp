#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

	int g_windowWidth { 640 };
	int g_windowHeight { 480 };

void glfwWindowResize(GLFWwindow* ptrWindow, int width, int height);

void glfwKeyCallback(GLFWwindow* ptrWindow, int key, int scancode, int action, int mode);

int main()
{
	const char* programName { "Battle City" };

	/* Initialize the library */
	if (!glfwInit())
	{
		std::cerr << "glfwInit() failed!\n";

		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	/* Create a windowed mode window and its OpenGL context */
	GLFWwindow* ptrWindow = glfwCreateWindow(g_windowWidth, g_windowHeight, programName, nullptr, nullptr);

	if (!ptrWindow)
	{
		std::cerr << "glfwCreateWindow() failed!\n";
		glfwTerminate();
		return -1;
	}

	glfwSetWindowSizeCallback(ptrWindow, glfwWindowResize);
	glfwSetKeyCallback(ptrWindow, glfwKeyCallback);

	/* Make the window's context current */
	glfwMakeContextCurrent(ptrWindow);

	if (!gladLoadGL())
	{
		std::cerr << "Can't load GLAD!\n";
		
		return -1;
	}

	std::cout << "Renderer: " << glGetString(GL_RENDERER) << '\n';
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << '\n';

	glClearColor(1, 1, 0, 1);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(ptrWindow))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(ptrWindow);
		
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

void glfwWindowResize(GLFWwindow* ptrWindow, int width, int height)
{
	g_windowWidth = width;
	g_windowHeight = height;
	glViewport(0, 0, g_windowWidth, g_windowHeight);
}

void glfwKeyCallback(GLFWwindow* ptrWindow, int key, int scancode, int action, int mode)
{
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(ptrWindow, GL_TRUE);
	}
}