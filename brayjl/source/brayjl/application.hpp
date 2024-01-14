#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "platform/window/window.hpp"
#include "platform/opengl/renderer.hpp"

namespace brayjl {
	class Application {
	public:
		Application();
		~Application();

		void run();
	private:
		Window window{ 800, 600, "brayjl engine" };
		Renderer renderer{ true };
	};
}

#endif