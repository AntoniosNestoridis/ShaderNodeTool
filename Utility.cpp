<<<<<<< HEAD:ShaderNodeTool/Utility.cpp
#include "Utility.h"

#include <iostream>
std::vector<Vertex> util::Arrays3ToVec3(std::vector<float> VertexInfo)
{
	std::vector<Vertex> VertVector;
	
	
	for (int i = 0; i < VertexInfo.size();i=i+5) {

		Vertex vert;
		vert.Position = glm::vec3(VertexInfo[i], VertexInfo[i+1], VertexInfo[i+2]);
		vert.TexCoords = glm::vec2(VertexInfo[i + 3], VertexInfo[i + 4]);
		VertVector.push_back(vert);
	}
	return VertVector;
}


=======
#include "Utility.h"

#include <iostream>
std::vector<Vertex> util::Arrays3ToVec3(std::vector<float> positions)
{
	std::vector<Vertex> VertVector;
	//std::cout << sizeof(positions) << " " << sizeof(positions[0]) << " " << sizeof(positions) / sizeof(positions[0]) << std::endl;
	int counter = 0;
	glm::vec3 TempVert;
	for (std::vector<float>::iterator it = positions.begin(); it != positions.end(); it++){

		TempVert[counter] = *it;
		counter++;

		if (counter == 3) {
			Vertex vert;
			vert.Position = TempVert;
			VertVector.push_back(vert);
			counter = 0;
		}
	}
	return VertVector;
}


>>>>>>> parent of 7c7367a... Before Shaderlang:ShaderNodeTool/ShaderNodeTool/Utility.cpp
