#include <iostream>
#include "Texture.h"
#include <vector>
#include "Cube.h"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH  1200

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
float horizontal_directions = 0;
float vertical_directions = 0;
float resize = 0;
bool isMoving = true;
float increase = 0;
float increase2 = 0;
float fov = 0;
float lastX = 400, lastY = 300;
bool firstMouse = false;
const float cameraSpeed = 0.05f; // adjust accordingly
const float gravity = 0.098f;
bool Pressed = false;

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

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		isMoving = false;
	else
		isMoving = true;
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
	
	Texture texutre("surfaceTexture.jpg",GL_RGB);
	Texture texutre2("sideTexture.jpg",GL_RGB);

	glEnable(GL_DEPTH_TEST);

	//HERE IS THE DRAWING DETAILS
	float vertices[] =
	{
		//POSITIONS   //COLORS   //TEXTURE  //SIDE_TEXTURE
		-0.5,-0.5,0,   1,1,1,	 1.0f,1.0f, 1.0f,1.0f, //0
		-0.5, 0.5,0,   1,1,1,	 1.0f,0.0f, 1.0f,0.0f, //1 //FRONT_TOP?
		 0.5, 0.5,0,   1,0,1,	 0.0f,0.0f, 0.0f,0.0f, //2
		 0.5,-0.5,0,   1,1,0,	 0.0f,1.0f, 0.0f,1.0f, //3 //FRONT_SIDE
		 0.5,-0.5,1,   1,0,1,	 1.0f,1.0f, 1.0f,1.0f, //4 //LEFT_SIDE
		 0.5,0.5,1,    1,1,0,	 1.0f,0.0f, 1.0f,0.0f, //5 //LEFT_sIDE_2
		 -0.5,0.5,1,   1,0,1,	 0.0f,0.0f, 0.0f,0.0f, //6
		 -0.5,-0.5,1,  0,1,1,	 0.0f,1.0f, 0.0f,1.0f, //7 //RIGHT_SIDE
		 -0.5,0.5,1,   1,1,0,	 1.0f,1.0f, 0.0f,0.0f, //8
		 0.5,0.5,1,    1,1,1,	 0.0f,1.0f, 0.0f,0.0f, //9 //TOP ? 
		 -0.5,-0.5,1,  0,1,1,	 1.0f,0.0f, 0.0f,0.0f, //10 
		 0.5,-0.5,1,   1,1,0,	 0.0f,0.0f, 0.0f,0.0f, //11
		 -0.5,0.5,0,   1,1,0,	 1.0f,0.0f, 0.0f,0.0f, //12 // THIS IS AN EXTRA TEXUTRE JUST TO FIX STUFF
	};

	unsigned int indecies[] =
	{
		0,1,2,
		2,0,3,
		3,2,4,
		4,2,5,
		0,1,6,
		0,6,7,
		12,2,8,
		8,2,9,
		7,6,5,
		5,7,4,
		0,3,10, //BUTTOM
		10,3,11,//BUTTOM_2
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 10, (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 10, (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 10, (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 10, (void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(3);

	Shader shader("VertexShader.shader", "FragmentShader.shader");

	shader.UnBind();
	glUniform1i(glGetUniformLocation(shader.shader_program, "textureFrag"), 0); // set it manually
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	/* Make the window's context current */

	/* Loop until the user closes the window */


	std::vector<Cube> cubes;

	for (unsigned int i = 1; i < 50; i++)
	{
		for (unsigned int j = 1; j < 50; j++)
		{
			Cube cube(glm::vec3(i, -5, j));
			cube.SetOscillateValue(i + j);
			cubes.push_back(cube);
		}
	}


	Cube cube(glm::vec3(2, 2, 2));
	Cube cube2(glm::vec3(2, 2, 4));
	cube.SetOscillateValue(20);
	cube2.SetOscillateValue(2);
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.9, 1, 1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSetCursorPosCallback(window, mouse_callback);



		shader.Bind();

		if (isMoving)
			increase += 0.001f;

		increase2 += 0.001f;

		glBindVertexArray(VAO);

		//models
		for (unsigned int i = 0; i < cubes.size(); i++)
		{
			cubes[i].Update(shader.shader_program);
			cubes[i].Oscillate();

			if (cameraPos.y > cubes[i].GetPosition().y + 2)
				cameraPos -= cameraUp * 0.00001f;

		}
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !Pressed)
			cubes.pop_back();
		if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && !Pressed)
		{
			Cube cube(cameraPos);
			cube.Rotate(pitch, glm::vec3(0, 0, 1));
			cubes.push_back(cube);
		}
		//gravity 
		cube.Update(shader.shader_program);
		cube2.Update(shader.shader_program);

		cube.Oscillate();
		cube2.Oscillate();

		glm::mat4 view;
		view = glm::lookAt(cameraPos,cameraFront + cameraPos, cameraUp);

		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), 1200.f / 800.f, 0.1f, 100.0f);

		int viewLoc = glGetUniformLocation(shader.shader_program, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projectionLoc = glGetUniformLocation(shader.shader_program, "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		shader.setInt("textureFrag", 0); // or with shader class
		shader.setInt("textureFrag2", 1); // or with shader class

		processInput(window);
		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}