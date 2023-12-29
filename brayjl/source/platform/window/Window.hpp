#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glfw/glfw3.h>

#include "brayjl/logger.hpp"

#include <cstdint>
#include <string>

namespace brayjl {
	class Window {
	public:
		Window(std::uint32_t width, std::uint32_t height, std::string name);
		~Window();

		void update();

		bool shouldClose() { return glfwWindowShouldClose(m_Window); }

	private:
		void createGlfwWindow();

		std::uint32_t m_Width;
		std::uint32_t m_Height;
		std::string m_Name;
		GLFWwindow* m_Window;
	};
}

#endif // !WINDOW_HPP