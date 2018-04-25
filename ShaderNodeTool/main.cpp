
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm\glm.hpp>
#include <glm/ext.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Shader.h"
#include <iostream>
#include "Mesh.h"
#include "Utility.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window,Shader *shader);


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//testing, these should not be global
float InnerTesselationLevel = 1.0;
float OuterTesselationLevel = 1.0;



int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4.6);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

														 // glfw window creation
														 // --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}


	//OpenGL version
	std::cout << glGetString(GL_VERSION) << std::endl;

	//Shader shader("SimpleVertexShader.vs", "SimpleFragmentShader.fs");
	//Shader shader("SimpleVertexShader.vs", "SimpleFragmentShader.fs","TrianglesToPoints.gs");
	Shader shader("SimpleVertexShader.vs", "SimpleFragmentShader.fs", "TrianglesToPoints.gs", "SimpleTesControl.tcs", "SimpleTesEval.tes");

	//Make Path relevant
	char path[] = "D:\GithubProjects\ShaderNodeTool\ShaderNodeTool\Resources\Models\TeddyBear.obj";

	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	//std::vector<float>  verts = {
	//	-0.5f, -0.5f, 0.0f,  // bottom left
	//	0.5f, -0.5f, 0.0f,  // bottom right
	//	-0.5f,  0.5f, 0.0f,   // top left 
	//	0.5f,  0.5f, 0.0f,  // top right
	//	
	//};

	std::vector<float> verts = {
		
		// front
		-0.5, -0.5,  0.5,
		0.5, -0.5, 0.5,
		0.5, 0.5,  0.5,
		-0.5,  0.5,  0.5,
		// back
		-0.5, -0.5, -0.5,
		0.5, -0.5, -0.5,
		0.5,  0.5, -0.5,
		-0.5,  0.5, -0.5,
	
	};

	/*std::vector<float> verts = {
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		0.5f, -0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		0.5f,  0.5f,  0.5f,
		0.5f,  0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f,  0.5f,
		0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,
		0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f
	};*/
	//std::vector<float> normals = {

	//	// front
	//	0.0, 0.0,  1.0,
	//	0.5, -0.5, 0.5,
	//	0.5, 0.5,  0.5,
	//	-0.5,  0.5,  0.5,
	//	// back
	//	-0.5, -0.5, -0.5,
	//	0.5, -0.5, -0.5,
	//	0.5,  0.5, -0.5,
	//	-0.5,  0.5, -0.5,

	//};


	/*std::vector<unsigned int> indices = {
		0, 1, 2,
		1, 3, 2
	};*/
	std::vector<unsigned int> indices = {  
		// note that we start from 0
		// front
		0, 1, 2,
		2, 3, 0,
		// top
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// bottom
		4, 0, 3,
		3, 7, 4,
		// left
		4, 5, 1,
		1, 0, 4,
		// right
		3, 2, 6,
		6, 7, 3,  
	};

	//is it even beneficial to convert to vec3? 
	Mesh test(util::Arrays3ToVec3(verts),indices);
	
	
	//setup uniforms


	shader.use();
	// create transformations
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	
	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 2.0f), //camera pos
		glm::vec3(0.0f, 0.0f, 0.0f), //camera target
		glm::vec3(0.0f, 1.0f, 0.0f)); //up
	//view = glm::translate(view, glm::vec3(0.0f, -1.0f, 0.0f));
	/*view = glm::rotate(view,glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, -1.0f, -3.0f));*/
	
	projection = glm::perspective(glm::radians(60.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
	// retrieve the matrix uniform locations
	unsigned int modelLoc = glGetUniformLocation(shader.ID, "Model");
	unsigned int viewLoc = glGetUniformLocation(shader.ID, "View");
	unsigned int projLoc = glGetUniformLocation(shader.ID, "Projection");
	// pass them to the shaders (3 different ways)
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));


	float color[] = {1.0,1.0,0.0,1.0};
	
	int vertexColorLocation = glGetUniformLocation(shader.ID, "InputCol");
	glUniform4f(vertexColorLocation,color[0],color[1], color[2], color[3]);
	//shader.setFloat("test",0.5);
	shader.setFloat("TessLevelInner", 1.0);
	shader.setFloat("TessLevelOuter", 1.0);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glPatchParameteri(GL_PATCH_VERTICES, 3);
	// uncomment this call to draw in wireframe polygons.
	 glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	/* glEnable(GL_CULL_FACE);
	 glCullFace(GL_FRONT);
	 glFrontFace(GL_CCW);*/

	const double maxFPS = 60.0;
	const double maxPeriod = 1.0 / maxFPS;
	// approx ~ 16.666 ms
	double lastTime = glfwGetTime();
	double initTime = glfwGetTime();
	int framerate = 0;
	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{

		double time = glfwGetTime();
		double deltaTime = time - lastTime;
	

		if (time - initTime >= 1.0) {
			//std::cout << "FPS: " << framerate << std::endl;
			framerate = 0;
			initTime = time;
		}

		if (deltaTime >= maxPeriod) {
			lastTime = time;
			framerate++;
			// code here gets called with max FPS
		
			// input
			// -----
			processInput(window,&shader);
			
			// render
			// ------
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// draw our first triangle
			//glUseProgram(shaderProgram);
			shader.use();
			test.Draw();
			// glBindVertexArray(0); // no need to unbind it every time 

			// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
			// -------------------------------------------------------------------------------
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	
	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window,Shader *shader)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);


	//inrease Inner tess level
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_RELEASE) {
		InnerTesselationLevel++;
		shader->setFloat("TessLevelInner", InnerTesselationLevel);
	}
		
	//decrease Inner tess level
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_RELEASE) {
		if (InnerTesselationLevel>1.0)
			InnerTesselationLevel--;
		shader->setFloat("TessLevelInner", InnerTesselationLevel);
	}
		
	//increase Outer tess level
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_RELEASE)
	{
		OuterTesselationLevel++;
		shader->setFloat("TessLevelOuter", OuterTesselationLevel);
	}
	//decreate Outer Tess Level
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_RELEASE) {
		if (OuterTesselationLevel>1.0)
			OuterTesselationLevel--;
		shader->setFloat("TessLevelOuter", OuterTesselationLevel);
	}
		
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}



