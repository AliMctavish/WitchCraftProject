#pragma once


class Geometry {
public : 
	static float* MakeCubeVertices()
	{
		float vertices[] =
		{
			//3 FACES             //2D TEXTURE  //INDEX
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,	//FRONT_FACE
			 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f,	//FRONT_FACE
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,	//FRONT_FACE
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,	//FRONT_FACE
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f,	//FRONT_FACE
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,	//FRONT_FACE

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, ////BACK_FACE
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, ////BACK_FACE
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, ////BACK_FACE
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, ////BACK_FACE
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f, ////BACK_FACE
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, ////BACK_FACE

			-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, //SIDES
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f, //SIDES
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, //SIDES
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, //SIDES
			-0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, //SIDES
			-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, //SIDES

			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, //SIDES
			 0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f, //SIDES
			 0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, //SIDES
			 0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, //SIDES
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, //SIDES
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, //SIDES

			-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 2.0f, //TOP
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 2.0f, //TOP
			 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 2.0f, //TOP
			 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 2.0f, //TOP
			-0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 2.0f, //TOP
			-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 2.0f, //TOP

			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, //BUTTOM
			 0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, //BUTTOM
			 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f, //BUTTOM
			 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f, //BUTTOM
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, //BUTTOM
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, //BUTTOM
		};
		return vertices;
	}













};