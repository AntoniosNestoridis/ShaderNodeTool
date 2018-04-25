#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>



struct Vertex {

	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};


class Mesh
{

private:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	unsigned int VAO, VBO, EBO;
	//Setup Mesh -- OpenGL only for now
	void SetupMesh();
public:
	//constructor
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
	//destructor
	~Mesh();
	//Convert Data -> array to Vertices 
	

	//draw the mesh
	void Draw();
	//change the shader program associated with the mesh
	void SetShader();
};

