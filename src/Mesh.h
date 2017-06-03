#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h> //Use GLFW to open a window cross-platform and render with OpenGL
#include <assimp\Importer.hpp>
#include <assimp\postprocess.h>
#include <assimp\scene.h>
#include <assimp\mesh.h>



#include <vector>

class Mesh
{
public:
	struct MeshEntry {
		static enum BUFFERS {
			VERTEX_BUFFER, TEXCOORD_BUFFER, NORMAL_BUFFER, INDEX_BUFFER
		};
		GLuint vao;
		GLuint vbo[4];

		unsigned int elementCount;

		MeshEntry(aiMesh *mesh);
		~MeshEntry();

		void render();
	};

	std::vector<MeshEntry*> meshEntries;

public:
	Mesh(const char *filename);
	~Mesh(void);

	void render();
};
