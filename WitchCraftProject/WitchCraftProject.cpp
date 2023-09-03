#include <iostream>
#include "Texture.h"
#include <vector>
#include "Cube.h"
#include "Geometry.h"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH  1200

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
float horizontal_directions = 0;
float vertical_directions = 0;
float resize = 0;
float lastX = 400, lastY = 300;
bool firstMouse = false;
const float cameraSpeed = 0.05f; // adjust accordingly
const float gravity = 0.098f;
float velocity = 0.5f;

glm::vec3 cameraPos = glm::vec3(3.0f, 3.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 direction;
glm::vec3 cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));

float yaw = 1;
float pitch = 1;



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
}
void processInput(GLFWwindow* window)
{


	//EXTRA COMPUTATION MAYBE FIX LATER ? 
	//TODO: MAKE ANOTHER TRICK TO FIX THE EXTRA COMPUTATION IN HERE!
	cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraRight, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraRight, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;


	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
		cameraPos.y += cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
		cameraPos.y -= cameraSpeed;


	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		horizontal_directions -= 0.01f;

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		horizontal_directions += 0.01f;

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		vertical_directions += 0.01f;

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		vertical_directions -= 0.01f;

}




struct vec2 {
	float v0, v1;
};

struct vec3 {
	float v0, v1, v2;
};

struct vec4 {
	float v0, v1, v2, v3;
};

struct Vertex {
	vec3 Position;
	vec2 TexturePosition;
	float TextureIndex;
};



static std::vector<Vertex> CreateCube(float x, float y)
{

	float size = 1.0f;
	//FRONT_FACE
	Vertex v0;
	v0.Position = { -0.5f + x, -0.5f, -0.5f };
	v0.TexturePosition = { 0.0f, 0.0f };
	v0.TextureIndex = 1.0f;
	Vertex v1;
	v1.Position = { 0.5f, -0.5f, -0.5f };
	v1.TexturePosition = { 1.0f, 0.0f };
	v1.TextureIndex = 1.0f;
	Vertex v2;
	v2.Position = { 0.5f, 0.5f, -0.5f };
	v2.TexturePosition = { 1.0f, 1.0f };
	v2.TextureIndex = 1.0f;
	Vertex v3;
	v3.Position = { 0.5f, 0.5f, -0.5f };
	v3.TexturePosition = { 1.0f, 1.0f };
	v3.TextureIndex = 1.0f;
	Vertex v4;
	v4.Position = { -0.5f, 0.5f, -0.5f };
	v4.TexturePosition = { 0.0f, 1.0f };
	v4.TextureIndex = 1.0f;
	Vertex v5;
	v5.Position = { -0.5f, -0.5f, -0.5f };
	v5.TexturePosition = { 0.0f, 0.0f };
	v5.TextureIndex = 1.0f;

	//BACK_FACE
	Vertex v6;
	v6.Position = { -0.5f, -0.5f,  0.5f };
	v6.TexturePosition = { 0.0,0.0 };
	v6.TextureIndex = 1.0f;
	Vertex v7;
	v7.Position = { 0.5f, -0.5f,  0.5f };
	v7.TexturePosition = { 1.0f,0.0f };
	v7.TextureIndex = 1.0f;
	Vertex v8;
	v8.Position = { 0.5f,  0.5f,  0.5f };
	v8.TexturePosition = { 1.0f,1.0f };
	v8.TextureIndex = 1.0f;
	Vertex v9;
	v9.Position = { 0.5f,0.5f,0.5f };
	v9.TexturePosition = { 1.0f,1.0f };
	v9.TextureIndex = 1.0f;
	Vertex v10;
	v10.Position = { -0.5f,  0.5f,  0.5f };
	v10.TexturePosition = { 0.0f, 1.0f };
	v10.TextureIndex = 1.0f;
	Vertex v11;
	v11.Position = { -0.5f, -0.5f,  0.5f };
	v11.TexturePosition = { 0.0f, 0.0f };
	v11.TextureIndex = 1.0f;
	//SIDES
	Vertex v12;
	v12.Position = { -0.5f,  0.5f,  0.5f };
	v12.TexturePosition = { 1.0f, 1.0f };
	v12.TextureIndex = 1.0f;
	Vertex v13;
	v13.Position = { -0.5f,  0.5f, -0.5f };
	v13.TexturePosition = { 0.0f, 1.0f };
	v13.TextureIndex = 1.0f;
	Vertex v14;
	v14.Position = { -0.5f, -0.5f, -0.5f };
	v14.TexturePosition = { 0.0f, 0.0f };
	v14.TextureIndex = 1.0f;
	Vertex v15;
	v15.Position = { -0.5f, -0.5f, -0.5f };
	v15.TexturePosition = { 0.0f, 0.0f };
	v15.TextureIndex = 1.0f;
	Vertex v16;
	v16.Position = { -0.5f, -0.5f,  0.5f };
	v16.TexturePosition = { 1.0f, 0.0f };
	v16.TextureIndex = 1.0f;
	Vertex v17;
	v17.Position = { -0.5f,  0.5f,  0.5f };
	v17.TexturePosition = { 1.0f, 1.0f };
	v17.TextureIndex = 1.0f;
	//SIDES_2
	Vertex v18;
	v18.Position = { 0.5f,  0.5f,  0.5f };
	v18.TexturePosition = { 1.0f, 1.0f };
	v18.TextureIndex = 1.0f;
	Vertex v19;
	v19.Position = { 0.5f,  0.5f, -0.5f };
	v19.TexturePosition = { 0.0f, 1.0f };
	v19.TextureIndex = 1.0f;
	Vertex v20;
	v20.Position = { 0.5f, -0.5f, -0.5f };
	v20.TexturePosition = { 0.0f, 0.0f };
	v20.TextureIndex = 1.0f;
	Vertex v21;
	v21.Position = { 0.5f, -0.5f, -0.5f };
	v21.TexturePosition = { 0.0f, 0.0f };
	v21.TextureIndex = 1.0f;
	Vertex v22;
	v22.Position = { 0.5f, -0.5f,  0.5f };
	v22.TexturePosition = { 1.0f, 0.0f };
	v22.TextureIndex = 1.0f;
	Vertex v23;
	v23.Position = { 0.5f,  0.5f,  0.5f };
	v23.TexturePosition = { 1.0f, 1.0f };
	v23.TextureIndex = 1.0f;
	//TOP
	Vertex v24;
	v24.Position = { -0.5f, -0.5f, -0.5f };
	v24.TexturePosition = { 1.0f, 1.0f };
	v24.TextureIndex = 2.0f;
	Vertex v25;
	v25.Position = { 0.5f, -0.5f, -0.5f };
	v25.TexturePosition = { 0.0f, 1.0f };
	v25.TextureIndex = 2.0f;
	Vertex v26;
	v26.Position = { 0.5f, -0.5f,  0.5f };
	v26.TexturePosition = { 0.0f, 0.0f };
	v26.TextureIndex = 2.0f;
	Vertex v27;
	v27.Position = { 0.5f, -0.5f,  0.5f };
	v27.TexturePosition = { 0.0f, 0.0f };
	v27.TextureIndex = 2.0f;
	Vertex v28;
	v28.Position = { -0.5f, -0.5f,  0.5f };
	v28.TexturePosition = { 1.0f, 0.0f };
	v28.TextureIndex = 2.0f;
	Vertex v29;
	v29.Position = { -0.5f, -0.5f, -0.5f };
	v29.TexturePosition = { 1.0f, 1.0f };
	v29.TextureIndex = 2.0f;
	//BUTTOM
	Vertex v30;
	v30.Position = { -0.5f,  0.5f, -0.5f };
	v30.TexturePosition = { 1.0f, 1.0f };
	v30.TextureIndex = 0.0f;
	Vertex v31;
	v31.Position = { 0.5f,  0.5f, -0.5f };
	v31.TexturePosition = { 0.0f, 1.0f };
	v31.TextureIndex = 0.0f;
	Vertex v32;
	v32.Position = { 0.5f,  0.5f,  0.5f };
	v32.TexturePosition = { 0.0f, 0.0f };
	v32.TextureIndex = 0.0f;
	Vertex v33;
	v33.Position = { 0.5f,  0.5f,  0.5f };
	v33.TexturePosition = { 0.0f, 0.0f };
	v33.TextureIndex = 0.0f;
	Vertex v34;
	v34.Position = { -0.5f,  0.5f,  0.5f };
	v34.TexturePosition = { 1.0f, 0.0f };
	v34.TextureIndex = 0.0f;
	Vertex v35;
	v35.Position = { -0.5f,  0.5f, -0.5f };
	v35.TexturePosition = { 1.0f, 1.0f };
	v35.TextureIndex = 0.0f;

	return { v0,v1,v2,v3,v4,v5
		    ,v6,v7,v8,v9,v10,v11
		    ,v12,v13,v14,v15,v16
		    ,v17,v18,v19,v20,v21
		    ,v22,v23,v24,v25,v26
		    ,v27,v28,v29,v30,v31
			,v32,v33,v34,v35};
} 

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "the lagacy", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "something went wrong with glad !" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	//HERE IS THE DRAWING DETAILS

	//float* vertices = Geometry::MakeCubeVertices();

	//float be[216];

	//for (int i = 0; i < sizeof(be); i++)
		//be[i] = {vertices[i]};
	float vertices[250];

	unsigned int indecies[] =
	{
		0,1,2,
		2,3,1,
		4,5,6,
		6,7,5,
		5,4,0,
		2,5,6,

	};

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int EAO;
	glGenBuffers(1, &EAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EAO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indecies), &indecies, GL_STATIC_DRAW);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), nullptr, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);




	Shader shader("VertexShader.shader", "FragmentShader.shader");

	Texture texutre("Assets/surfaceTexture.jpg", GL_RGB);
	Texture texutre2("Assets/sideTexture.jpg", GL_RGB);
	Texture texutre3("Assets/dirtTexture.jpg", GL_RGB);


	auto loc = glGetUniformLocation(shader.shader_program, "textureFrag");
	int samplers[3] = { 0,1,2 };
	glUniform1iv(loc, 3, samplers);

	shader.UnBind();
	glBindVertexArray(0);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	/* Make the window's context current */

	/* Loop until the user closes the window */

	int size = 10;
	std::vector<Cube> cubes;
	int counter = 0;
	for (unsigned int i = 1; i < size; i++)
	{
		for (unsigned int j = 1; j < size; j++)
		{
			for (unsigned int k = 1; k < size; k++)
			{
				counter++;
				Cube cube(glm::vec3(i, j, k));
				cubes.push_back(cube);
			}
		}
	}


	for (unsigned int i = 0; i < cubes.size() - 1; i++)
	{
		if (cubes[i].GetPosition().y < cubes[i + 1].GetPosition().y)
			cubes[i + 1].Transform(glm::vec3(3, 3, 3));
	}
	float num = 0.1f;
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.8, 1, 1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSetCursorPosCallback(window, mouse_callback);

		shader.Bind();
		glBindVertexArray(VAO);

		std::vector<Vertex> res = CreateCube(1, 2);
		std::vector<Vertex> res2 = CreateCube(2, 2);
		std::vector<Vertex> res3 = CreateCube(3, 2);
		std::vector<Vertex> res4 = CreateCube(4, 2);

		memcpy(vertices, res.data(),res.size() * sizeof(Vertex));
		memcpy(vertices, res2.data(),res2.size() * sizeof(Vertex));
		memcpy(vertices, res3.data(),res3.size() * sizeof(Vertex));
		memcpy(vertices, res4.data(),res4.size() * sizeof(Vertex));


		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

		Cube cube(glm::vec3(3,3,3));
		cube.Update(shader.shader_program);



		texutre.Bind();
		texutre2.Bind();
		texutre3.Bind();
		//glBindTexture(0, texutre.GetTextureId());
		//glBindTexture(1, texutre2.GetTextureId());



		//models
		/*for (unsigned int i = 0; i < cubes.size(); i++)
		{
			cubes[i].Update(shader.shader_program);
		}*/



		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && cubes.size() > 0)
			cubes.pop_back();

		if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		{
			Cube cube(cameraPos);
			cube.Rotate(pitch, glm::vec3(0, 0, 1));
			cubes.push_back(cube);
		}

		glm::mat4 view;
		view = glm::lookAt(cameraPos, cameraFront + cameraPos, cameraUp);

		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), 1200.f / 800.f, 0.1f, 10000.0f);

		int viewLoc = glGetUniformLocation(shader.shader_program, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projectionLoc = glGetUniformLocation(shader.shader_program, "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));



		glBindVertexArray(0);

		processInput(window);
		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}