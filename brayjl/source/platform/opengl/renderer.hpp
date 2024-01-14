#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "platform/opengl/shader.hpp"

namespace brayjl {
	class Renderer {
	public:
		Renderer(bool initialize);
		~Renderer();

		void init();

		void draw();
	private:
		void generateVertexData();

		Shader m_Shader;
		unsigned int m_Vbo;
		unsigned int m_Vao;
		unsigned int m_Ebo;

		const float vertices[8] = {
			-0.5f, 0.5f,
			-0.5f, -0.5f,
			0.5f, 0.5f,
			0.5f, -0.5f
		};
		const unsigned int indices[6] = {
			0, 1, 2,
			1, 2, 3
		};
	};
}

#endif // !RENDERER_HPP