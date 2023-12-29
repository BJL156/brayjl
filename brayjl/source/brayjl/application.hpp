#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "platform/window/Window.hpp"

namespace brayjl {
	class Application {
	public:
		Application();
		~Application();

		void run();
	private:
		Window window{ 800, 600, "brayjl engine" };
	};
}

#endif