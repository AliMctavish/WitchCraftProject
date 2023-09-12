#pragma once
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

static std::array<Vertex, 6> CreateGroundVoxel(float x, float y, float z, float buttomTex)
{
	//BUTTOM
	Vertex v30;
	v30.Position = { -0.5f + x,  0.5f + y, -0.5f + z };
	v30.TexturePosition = { 1.0f, 1.0f };
	v30.TextureIndex = buttomTex;
	Vertex v31;
	v31.Position = { 0.5f + x,  0.5f + y, -0.5f + z };
	v31.TexturePosition = { 0.0f, 1.0f };
	v31.TextureIndex = buttomTex;
	Vertex v32;
	v32.Position = { 0.5f + x,  0.5f + y,  0.5f + z };
	v32.TexturePosition = { 0.0f, 0.0f };
	v32.TextureIndex = buttomTex;
	Vertex v33;
	v33.Position = { 0.5f + x,  0.5f + y,  0.5f + z };
	v33.TexturePosition = { 0.0f, 0.0f };
	v33.TextureIndex = buttomTex;
	Vertex v34;
	v34.Position = { -0.5f + x,  0.5f + y,  0.5f + z };
	v34.TexturePosition = { 1.0f, 0.0f };
	v34.TextureIndex = buttomTex;
	Vertex v35;
	v35.Position = { -0.5f + x,  0.5f + y, -0.5f + z };
	v35.TexturePosition = { 1.0f, 1.0f };
	v35.TextureIndex = buttomTex;


	return { v30,v31,v32,v33,v34,v35 };
}

float last_x, last_y, last_z;

void CheckWall(float x, float y, float z)
{

}

static std::array<Vertex, 6> CreateWallVoxel(float x, float y, float z, float frontTex)
{

	z += 1;

	//FRONT_FACE
	Vertex v0;
	v0.Position = { -0.5f + x, -0.5f + y, -0.5f + z };
	v0.TexturePosition = { 0.0f, 0.0f };
	v0.TextureIndex = frontTex;
	Vertex v1;
	v1.Position = { 0.5f + x, -0.5f + y, -0.5f + z };
	v1.TexturePosition = { 1.0f, 0.0f };
	v1.TextureIndex = frontTex;
	Vertex v2;
	v2.Position = { 0.5f + x, 0.5f + y, -0.5f + z };
	v2.TexturePosition = { 1.0f, 1.0f };
	v2.TextureIndex = frontTex;
	Vertex v3;
	v3.Position = { 0.5f + x, 0.5f + y, -0.5f + z };
	v3.TexturePosition = { 1.0f, 1.0f };
	v3.TextureIndex = frontTex;
	Vertex v4;
	v4.Position = { -0.5f + x, 0.5f + y, -0.5f + z };
	v4.TexturePosition = { 0.0f, 1.0f };
	v4.TextureIndex = frontTex;
	Vertex v5;
	v5.Position = { -0.5f + x, -0.5f + y , -0.5f + z };
	v5.TexturePosition = { 0.0f, 0.0f };
	v5.TextureIndex = frontTex;


	return { v0,v1,v2,v3,v4,v5 };
}

static std::array<Vertex, 12> CreateVoxel(float x, float y, float z, float buttomTex, float sidesTex)
{
	//FRONT_FACE
	Vertex v0;
	v0.Position = { -0.5f + x, -0.5f + y, -0.5f + z };
	v0.TexturePosition = { 0.0f, 0.0f };
	v0.TextureIndex = sidesTex;
	Vertex v1;
	v1.Position = { 0.5f + x, -0.5f + y, -0.5f + z };
	v1.TexturePosition = { 1.0f, 0.0f };
	v1.TextureIndex = sidesTex;
	Vertex v2;
	v2.Position = { 0.5f + x, 0.5f + y, -0.5f + z };
	v2.TexturePosition = { 1.0f, 1.0f };
	v2.TextureIndex = sidesTex;
	Vertex v3;
	v3.Position = { 0.5f + x, 0.5f + y, -0.5f + z };
	v3.TexturePosition = { 1.0f, 1.0f };
	v3.TextureIndex = sidesTex;
	Vertex v4;
	v4.Position = { -0.5f + x, 0.5f + y, -0.5f + z };
	v4.TexturePosition = { 0.0f, 1.0f };
	v4.TextureIndex = sidesTex;
	Vertex v5;
	v5.Position = { -0.5f + x, -0.5f + y , -0.5f + z };
	v5.TexturePosition = { 0.0f, 0.0f };
	v5.TextureIndex = sidesTex;

	//BUTTOM
	Vertex v30;
	v30.Position = { -0.5f + x,  0.5f + y, -0.5f + z };
	v30.TexturePosition = { 1.0f, 1.0f };
	v30.TextureIndex = buttomTex;
	Vertex v31;
	v31.Position = { 0.5f + x,  0.5f + y, -0.5f + z };
	v31.TexturePosition = { 0.0f, 1.0f };
	v31.TextureIndex = buttomTex;
	Vertex v32;
	v32.Position = { 0.5f + x,  0.5f + y,  0.5f + z };
	v32.TexturePosition = { 0.0f, 0.0f };
	v32.TextureIndex = buttomTex;
	Vertex v33;
	v33.Position = { 0.5f + x,  0.5f + y,  0.5f + z };
	v33.TexturePosition = { 0.0f, 0.0f };
	v33.TextureIndex = buttomTex;
	Vertex v34;
	v34.Position = { -0.5f + x,  0.5f + y,  0.5f + z };
	v34.TexturePosition = { 1.0f, 0.0f };
	v34.TextureIndex = buttomTex;
	Vertex v35;
	v35.Position = { -0.5f + x,  0.5f + y, -0.5f + z };
	v35.TexturePosition = { 1.0f, 1.0f };
	v35.TextureIndex = buttomTex;

	return { v30,v31,v32,v33,v34,v35,v0,v1,v2,v3,v4,v5 };
}


static std::array<Vertex, 36> CreateCube(float x, float y, float z, float topTex, float buttomTex, float sidesTex)
{
	float size = 1.0f;
	//FRONT_FACE
	Vertex v0;
	v0.Position = { -0.5f + x, -0.5f + y, -0.5f + z };
	v0.TexturePosition = { 0.0f, 0.0f };
	v0.TextureIndex = sidesTex;
	Vertex v1;
	v1.Position = { 0.5f + x, -0.5f + y, -0.5f + z };
	v1.TexturePosition = { 1.0f, 0.0f };
	v1.TextureIndex = sidesTex;
	Vertex v2;
	v2.Position = { 0.5f + x, 0.5f + y, -0.5f + z };
	v2.TexturePosition = { 1.0f, 1.0f };
	v2.TextureIndex = sidesTex;
	Vertex v3;
	v3.Position = { 0.5f + x, 0.5f + y, -0.5f + z };
	v3.TexturePosition = { 1.0f, 1.0f };
	v3.TextureIndex = sidesTex;
	Vertex v4;
	v4.Position = { -0.5f + x, 0.5f + y, -0.5f + z };
	v4.TexturePosition = { 0.0f, 1.0f };
	v4.TextureIndex = sidesTex;
	Vertex v5;
	v5.Position = { -0.5f + x, -0.5f + y , -0.5f + z };
	v5.TexturePosition = { 0.0f, 0.0f };
	v5.TextureIndex = sidesTex;

	//BACK_FACE
	Vertex v6;
	v6.Position = { -0.5f + x, -0.5f + y,  0.5f + z };
	v6.TexturePosition = { 0.0,0.0 };
	v6.TextureIndex = sidesTex;
	Vertex v7;
	v7.Position = { 0.5f + x, -0.5f + y,  0.5f + z };
	v7.TexturePosition = { 1.0f,0.0f };
	v7.TextureIndex = sidesTex;
	Vertex v8;
	v8.Position = { 0.5f + x,  0.5f + y,  0.5f + z };
	v8.TexturePosition = { 1.0f,1.0f };
	v8.TextureIndex = sidesTex;
	Vertex v9;
	v9.Position = { 0.5f + x,0.5f + y,0.5f + z };
	v9.TexturePosition = { 1.0f,1.0f };
	v9.TextureIndex = sidesTex;
	Vertex v10;
	v10.Position = { -0.5f + x,  0.5f + y,  0.5f + z };
	v10.TexturePosition = { 0.0f, 1.0f };
	v10.TextureIndex = sidesTex;
	Vertex v11;
	v11.Position = { -0.5f + x, -0.5f + y,  0.5f + z };
	v11.TexturePosition = { 0.0f, 0.0f };
	v11.TextureIndex = sidesTex;
	//SIDES
	Vertex v12;
	v12.Position = { -0.5f + x,  0.5f + y,  0.5f + z };
	v12.TexturePosition = { 1.0f, 1.0f };
	v12.TextureIndex = sidesTex;
	Vertex v13;
	v13.Position = { -0.5f + x,  0.5f + y, -0.5f + z };
	v13.TexturePosition = { 0.0f, 1.0f };
	v13.TextureIndex = sidesTex;
	Vertex v14;
	v14.Position = { -0.5f + x, -0.5f + y, -0.5f + z };
	v14.TexturePosition = { 0.0f, 0.0f };
	v14.TextureIndex = sidesTex;
	Vertex v15;
	v15.Position = { -0.5f + x, -0.5f + y, -0.5f + z };
	v15.TexturePosition = { 0.0f, 0.0f };
	v15.TextureIndex = sidesTex;
	Vertex v16;
	v16.Position = { -0.5f + x, -0.5f + y,  0.5f + z };
	v16.TexturePosition = { 1.0f, 0.0f };
	v16.TextureIndex = sidesTex;
	Vertex v17;
	v17.Position = { -0.5f + x,  0.5f + y,  0.5f + z };
	v17.TexturePosition = { 1.0f, 1.0f };
	v17.TextureIndex = sidesTex;
	//SIDES_2
	Vertex v18;
	v18.Position = { 0.5f + x,  0.5f + y,  0.5f + z };
	v18.TexturePosition = { 1.0f, 1.0f };
	v18.TextureIndex = sidesTex;
	Vertex v19;
	v19.Position = { 0.5f + x,  0.5f + y, -0.5f + z };
	v19.TexturePosition = { 0.0f, 1.0f };
	v19.TextureIndex = sidesTex;
	Vertex v20;
	v20.Position = { 0.5f + x, -0.5f + y, -0.5f + z };
	v20.TexturePosition = { 0.0f, 0.0f };
	v20.TextureIndex = sidesTex;
	Vertex v21;
	v21.Position = { 0.5f + x, -0.5f + y, -0.5f + z };
	v21.TexturePosition = { 0.0f, 0.0f };
	v21.TextureIndex = sidesTex;
	Vertex v22;
	v22.Position = { 0.5f + x, -0.5f + y,  0.5f + z };
	v22.TexturePosition = { 1.0f, 0.0f };
	v22.TextureIndex = sidesTex;
	Vertex v23;
	v23.Position = { 0.5f + x,  0.5f + y,  0.5f + z };
	v23.TexturePosition = { 1.0f, 1.0f };
	v23.TextureIndex = sidesTex;
	//TOP
	Vertex v24;
	v24.Position = { -0.5f + x, -0.5f + y, -0.5f + z };
	v24.TexturePosition = { 1.0f, 1.0f };
	v24.TextureIndex = topTex;
	Vertex v25;
	v25.Position = { 0.5f + x, -0.5f + y, -0.5f + z };
	v25.TexturePosition = { 0.0f, 1.0f };
	v25.TextureIndex = topTex;
	Vertex v26;
	v26.Position = { 0.5f + x, -0.5f + y,  0.5f + z };
	v26.TexturePosition = { 0.0f, 0.0f };
	v26.TextureIndex = topTex;
	Vertex v27;
	v27.Position = { 0.5f + x, -0.5f + y,  0.5f + z };
	v27.TexturePosition = { 0.0f, 0.0f };
	v27.TextureIndex = topTex;
	Vertex v28;
	v28.Position = { -0.5f + x, -0.5f + y,  0.5f + z };
	v28.TexturePosition = { 1.0f, 0.0f };
	v28.TextureIndex = topTex;
	Vertex v29;
	v29.Position = { -0.5f + x, -0.5f + y, -0.5f + z };
	v29.TexturePosition = { 1.0f, 1.0f };
	v29.TextureIndex = topTex;
	//BUTTOM
	Vertex v30;
	v30.Position = { -0.5f + x,  0.5f + y, -0.5f + z };
	v30.TexturePosition = { 1.0f, 1.0f };
	v30.TextureIndex = buttomTex;
	Vertex v31;
	v31.Position = { 0.5f + x,  0.5f + y, -0.5f + z };
	v31.TexturePosition = { 0.0f, 1.0f };
	v31.TextureIndex = buttomTex;
	Vertex v32;
	v32.Position = { 0.5f + x,  0.5f + y,  0.5f + z };
	v32.TexturePosition = { 0.0f, 0.0f };
	v32.TextureIndex = buttomTex;
	Vertex v33;
	v33.Position = { 0.5f + x,  0.5f + y,  0.5f + z };
	v33.TexturePosition = { 0.0f, 0.0f };
	v33.TextureIndex = buttomTex;
	Vertex v34;
	v34.Position = { -0.5f + x,  0.5f + y,  0.5f + z };
	v34.TexturePosition = { 1.0f, 0.0f };
	v34.TextureIndex = buttomTex;
	Vertex v35;
	v35.Position = { -0.5f + x,  0.5f + y, -0.5f + z };
	v35.TexturePosition = { 1.0f, 1.0f };
	v35.TextureIndex = buttomTex;

	return { v0,v1,v2,v3,v4,v5
			,v6,v7,v8,v9,v10,v11
			,v12,v13,v14,v15,v16
			,v17,v18,v19,v20,v21
			,v22,v23,v24,v25,v26
			,v27,v28,v29,v30,v31
			,v32,v33,v34,v35 };
}