// Con6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glm\glm.hpp>
#include <glm\mat4x4.hpp>
#include <glm\geometric.hpp>
#include <glm\gtx\projection.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\vec4.hpp>
#include <glm\vec3.hpp>

using namespace glm;
void test1()
{
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 
		(float) 800 / (float) 600, 0.0f, 0.001f);

	glm::mat4 ModelView = glm::mat4(1.0f);
	ModelView = glm::translate(ModelView, glm::vec3(0.0f, 0.0f, -18.0f));
	ModelView = glm::rotate(ModelView, 15.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 mvp = Projection * ModelView;
	glm::vec4 vertex = glm::vec4(-1.5f, -1.0f, 0.0f, 1);

	glm::vec4 v0 = ModelView * vertex;
	glm::vec4 v1 = mvp * vertex;
}


int _tmain(int argc, _TCHAR* argv[])
{
	test1();

	return 1;

	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 
		(float) 4 / (float)3, 0.1f, 100.0f);

	glm::mat4 View = glm::lookAt(
		glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
		glm::vec3(0,0,0), // and looks at the origin
		glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
		);

	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 mvp = Projection * View * Model; // Remember, matrix multiplication is the other way around
	glm::vec4 vertex = glm::vec4(0, 0, -1, 1);

	glm::vec4 v = mvp * vertex;
	return 0;
}

