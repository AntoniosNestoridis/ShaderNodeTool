<<<<<<< HEAD:ShaderNodeTool/Utility.h
#pragma once


#include <vector>
#include "Rendering/Mesh.h"

namespace util {
	
	std::vector<Vertex> Arrays3ToVec3(std::vector<float> positions);
	std::vector<Vertex> Arrays3ToVec3Tex(std::vector<float> positions, std::vector<float> texCoords);

	std::vector<Vertex> ArraysToVec3(float positions[],float normals[]);
	std::vector<Vertex> ArraysToVec3(float positions[],float normals[],float texcoords[]);
	
	std::vector<unsigned int> ArraysToUintVec(unsigned int indices[]);
=======
#pragma once


#include <vector>
#include "Mesh.h"

namespace util {
	
	std::vector<Vertex> Arrays3ToVec3(std::vector<float> positions);
	std::vector<Vertex> ArraysToVec3(float positions[],float normals[]);
	std::vector<Vertex> ArraysToVec3(float positions[],float normals[],float texcoords[]);
	
	std::vector<unsigned int> ArraysToUintVec(unsigned int indices[]);
>>>>>>> parent of 7c7367a... Before Shaderlang:ShaderNodeTool/ShaderNodeTool/Utility.h
};