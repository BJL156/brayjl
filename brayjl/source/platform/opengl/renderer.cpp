#include "renderer.hpp"

namespace brayjl {
	Renderer::Renderer(bool initialize) {
		if (!initialize) return;
		init();
	}

	Renderer::~Renderer() {
		glDeleteBuffers(1, &m_Vbo);
		glDeleteBuffers(1, &m_Ebo);
		glDeleteVertexArrays(1, &m_Vao);
	}

	void Renderer::init() {
		m_Shader.init("resources/shaders/example.vert", "resources/shaders/example.frag");
		generateVertexData();
	}
	
	void Renderer::draw() {
		m_Shader.use();

		glBindVertexArray(m_Vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ebo);

		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void Renderer::generateVertexData() {
		glGenBuffers(1, &m_Vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glGenVertexArrays(1, &m_Vao);
		glBindVertexArray(m_Vao);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glGenBuffers(1, &m_Ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}