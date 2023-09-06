#include <iostream>
#include "Texture.h"
#include <vector>
#include "Cube.h"
#include <array>
#include "Geometry.h"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH  1200

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
float horizontal_directions = 1;
float vertical_directions = 0;
float resize = 0;
float lastX = 400, lastY = 300;
bool firstMouse = false;
const float cameraSpeed = 0.05f; // adjust accordingly
const float gravity = 0.098f;
const int data_size = 173200;

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
		horizontal_directions -= 0.1f;

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		horizontal_directions += 0.01f;

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		vertical_directions += 0.01f;

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		vertical_directions -= 0.01f;

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

	//float* vertices = Geometry::MakeCubevertices();

	//float be[216];

	//for (int i = 0; i < sizeof(be); i++)
		//be[i] = {vertices[i]};
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * data_size, nullptr, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(5 * sizeof(float)));
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

	int size = 6;
	std::vector<Cube> cubes;
	int counter_x = 1;
	int counter_z = 1;
	for (unsigned int i = 1; i < size; i++)
	{
		counter_z += 10;
		for (unsigned int j = 1; j < size; j++)
		{
			counter_x += 10;
			Cube cube(glm::vec3(counter_x, 0, counter_z));
			cubes.push_back(cube);
		}
		counter_x = 1;
	}


	/*for (unsigned int i = 0; i < cubes.size() - 1; i++)
	{
		if (cubes[i].GetPosition().y < cubes[i + 1].GetPosition().y)
			cubes[i + 1].Transform(glm::vec3(3, 3, 3));
	}*/
	float num = 0.1f;
	const int data_counter = 15;
	std::vector<Vertex> vertices;

	while (!glfwWindowShouldClose(window))
	{
		size_t rizos = 0;

		for (int i = 1; i < data_counter; i++) {
			for (int j = 1; j < data_counter + 5; j++) {
				for (int k = 1; k < 10; k++)
				{
					if (k == 9)
					{
						std::array<Vertex, 36> rizo = CreateCube(i * horizontal_directions, k * horizontal_directions, j * horizontal_directions,2.0f,0.0f,1.0f);
						vertices.insert(vertices.end(), rizo.begin(), rizo.end());
					}
					else
					{
						std::array<Vertex, 36> rizo = CreateCube(i * horizontal_directions, k * horizontal_directions, j * horizontal_directions, 0.0f, 0.0f, 2.0f);
						vertices.insert(vertices.end(), rizo.begin(), rizo.end());
					}
				}
			}
		}

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());

		glClearColor(0.8, 1, 1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSetCursorPosCallback(window, mouse_callback);

		shader.Bind();
		glBindVertexArray(VAO);

		//Cube cube(glm::vec3(1, 1, 1));
		//cube.Update(shader.shader_program);


		for (auto cube : cubes)
		{
			cube.Update(shader.shader_program);
		}



		texutre.Bind();
		texutre2.Bind();
		texutre3.Bind();

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
		vertices.clear();
	}

	glfwTerminate();
	return 0;
}