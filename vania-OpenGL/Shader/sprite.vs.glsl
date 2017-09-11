
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;
out vec3 WorldPos;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;


void main()
{
	WorldPos = vec3(model * vec4(aPos, 1.0));

	gl_Position = projection * view * vec4(WorldPos, 1.0);
	TexCoord = aTexCoord;
}
