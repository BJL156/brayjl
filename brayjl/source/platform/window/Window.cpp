#include "Window.hpp"

namespace brayjl {
	Window::Window(std::uint32_t width, std::uint32_t height, std::string name)
		: m_Width(width), m_Height(height), m_Name(name) {
		BRAYJL_CORE_INFO("creating glfw window ({}, {}) \"{}\".", m_Width, m_Height, m_Name);
		createGlfwWindow();
	}

	Window::~Window() {
		BRAYJL_CORE_WARN("shutting down glfw window.");
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void Window::update() {
		glfwSwapBuffers(m_Window);
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::createGlfwWindow() {
		if (glfwInit() == GLFW_FALSE) {
			BRAYJL_CORE_ERROR("failed to initialize glfw.");
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name.c_str(), nullptr, nullptr);
		if (m_Window == nullptr) {
			BRAYJL_CORE_ERROR("failed to create glfw window.");
		}
		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			BRAYJL_CORE_ERROR("failed to initialize glad.");
		}
	}
}