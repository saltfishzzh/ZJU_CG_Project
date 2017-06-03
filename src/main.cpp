#include <iostream>



// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//using namespace glm;

#include "Triangle.h"
#include "Rectangle.h"
#include "Grid.h"
#include "Mesh.h"

#include <array>


// Window dimensions
const GLuint WIDTH = 1200, HEIGHT = 900;




// The MAIN function, from here we start the application and run the game loop

GLFWwindow*  createWindow() {
	// Init GLFW
	glfwInit();

	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (nullptr == window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		//return EXIT_FAILURE;
		return NULL;
	}

	glfwMakeContextCurrent(window);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		//return EXIT_FAILURE;
		return NULL;
	}

	// Define the viewport dimensions
	glViewport(0, 0, screenWidth, screenHeight);
	return window;
}



int main() {

	GLFWwindow *window = createWindow();

	// Projection matrix : 45бу Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(glm::radians(60.0f), 4.0f / 3.0f, 0.1f, 101.0f);
	// Or, for an ortho camera :
	//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(0, -50, 75), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)   
		
	);
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around


	std::array<GLfloat, 16> vs5 = {
		-10.0, 5.0, 0.0,
		-10.0, -5.0, 0.0,
		10.0, -5.0, 0.0,
		10.0, 5.0, 0.0
	};
	Grid r1 = Grid();
	Rectangle r2 = Rectangle(vs5);

	// model
	Mesh *mesh = new Mesh("C:/Users/zzx20/Documents/git/ZJU_CG_Project/src/checkers.obj");
	// Game loop
	while (!glfwWindowShouldClose(window)) {
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		
		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Enable depth test
		glEnable(GL_DEPTH_TEST);
		// Accept fragment if it closer to the camera than the former one
		glDepthFunc(GL_LESS);

		// Cull triangles which normal is not towards the camera
		glEnable(GL_CULL_FACE);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		

		/*std::vector<GLfloat> vs4 = {
			-10.0, 5.0, 0.0,
			-10.0, -5.0, 0.0,
			10.0, -5.0, 0.0,
			10.0, 5.0, 0.0
		};*/
		mesh->render();
		//r1.draw(MVP);
		r1.draw(MVP);


		//std::array<GLfloat, 9> vs1 = { -1.0f, 100.0f, 0.0f, // Left
		//								1.0f, -1.0f, 0.0f, // Right
		//								1.0f,  100.0f, 0.0f  // Top
		//};
		//std::array<GLfloat, 9> vs2 = { -1.0f, 100.0f, 0.0f, // Left
		//	-1.0f, -1.0f, 0.0f, // Right
		//	1.0f, -1.0f, 0.0f  // Top
		//};
		//std::array<GLfloat, 9> vs3 = { -1.0f, 100.0f, 1.0f, // Left
		//	1.0f, 100.0f, -1.0f, // Right
		//	1.0f, 100.0f, 1.0f  // Top
		//};
		//Triangle t1 = Triangle(vs1);
		//Triangle t2 = Triangle(vs2);
		//Triangle t3 = Triangle(vs3);
		//t1.draw(MVP);
		//t2.draw(MVP);
		//t3.draw(MVP);

		


		// Swap the screen buffers
		glfwSwapBuffers(window);
	}

	

	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();

	return EXIT_SUCCESS;
}
