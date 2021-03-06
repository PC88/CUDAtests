#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"

#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"
#include "imgui\imgui_impl_opengl3.h"

#include "tests\TestClearColor.h"
#include "tests\TestMenu.h"
#include "tests\TestDist_v1.h"
#include "tests\TestDist_v2.h"

#include <GL\glew.h>
#include <GLFW/glfw3.h>
// note: the types for tutorial functions are using primitive types and not the OpenGL typedefs for them, GL_ENUM etc.

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
	{
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // changed to Core over Compat, VAO`s added -PC

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // sets frame rate = refresh rate

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error!" << std::endl;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;
	{ // this scope exists to deal with the issue of GL`s error being infinite looped - TODO heap allocate so this dose not exist -PC
		

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// IMGUI setup, more modern iteration that video`s -PC
		ImGui::CreateContext();
		ImGui_ImplOpenGL3_Init("#version 130"); // explicit version statement - PC
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui::StyleColorsDark();

		Test* currentTest = nullptr;
		TestMenu* testMenu = new TestMenu(currentTest);
		currentTest = testMenu;

		testMenu->RegisterTest<TestClearColor>("Clear Color");
		testMenu->RegisterTest<TestDist_v1>("dist_v1");
		testMenu->RegisterTest<TestDist_v2>("dist_v2");

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // cheap can be removed later -PC
			glClear(GL_COLOR_BUFFER_BIT);

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			if (currentTest)
			{
				currentTest->OnUpdate(0.0f);
				currentTest->OnRender();
				ImGui::Begin("Test");
				if (currentTest != testMenu && ImGui::Button("<-"))
				{
					delete currentTest;
					currentTest = testMenu;
				}
				currentTest->OnImGuiRender();
				ImGui::End();
			}

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
		delete currentTest;
		if (currentTest != testMenu)
		{
			delete testMenu;
		}
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}
