#version 460 core

out vec4 fragColor;

void main() {
	vec3 col = vec3(1.0, 0.0, 0.0);
	fragColor = vec4(col, 1.0);
}