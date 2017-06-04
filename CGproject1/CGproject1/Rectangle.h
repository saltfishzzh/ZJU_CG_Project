#pragma once
#include <GL/glew.h>
#include <iostream>
#include <array>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Rectangle {
public:
	Rectangle(std::array<GLfloat, 16> Vertices) :vertices(Vertices) {
		// Build and compile our shader program
		// Vertex shader
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		// Check for compile time errors
		GLint success;
		GLchar infoLog[512];

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		// Fragment shader
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		// Check for compile time errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}



		// Link shaders
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);


		// Check for linking errors
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);



		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);

		glGenBuffers(1, &vertexBuffer);
		// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).

		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);



		//glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

		//glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

		indices = { 0,1,2,3 };
		glGenBuffers(1, &indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0], GL_STATIC_DRAW);

	}

	~Rectangle() {
		glDeleteVertexArrays(1, &vertexArray);
		glDeleteProgram(shaderProgram);
		glDeleteBuffers(1, &vertexBuffer);
	};

	void draw(glm::mat4& MVP) {
		glUseProgram(shaderProgram);

		glUniformMatrix4fv(MatrixHandle, 1, GL_FALSE, &MVP[0][0]);

		MatrixHandle = glGetUniformLocation(shaderProgram, "MVP");
		glBindVertexArray(vertexArray);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);



		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

		// Draw the triangles !
		glDrawElements(
			GL_LINE_LOOP,      // mode
			indices.size(),    // count
			GL_UNSIGNED_SHORT,   // type
			(void*)0           // element array buffer offset
		);
		glDisableVertexAttribArray(0);

		// Properly de-allocate all resources once they've outlived their purpose

	}
private:
	std::array <GLfloat, 16> vertices;
	std::vector <unsigned short> indices;
	GLuint indexBuffer;
	GLuint shaderProgram;
	GLuint MatrixHandle;
	//GLuint 
	GLuint vertexBuffer, vertexArray;
	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"uniform mat4 MVP;\n"
		"void main()\n"
		"{\n"
		"gl_Position = MVP * vec4(position, 1.0);\n"
		"}\0";
	const GLchar* fragmentShaderSource = "#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
};
