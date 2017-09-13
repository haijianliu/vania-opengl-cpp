
#version 330 core

out vec4 fragColor;

in vec2 texCoord;

uniform sampler2D texColor;

void main() {
	fragColor = texture(texColor, texCoord);
}
