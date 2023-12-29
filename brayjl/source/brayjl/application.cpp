#include "application.hpp"

namespace brayjl {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		while (!window.shouldClose()) {
			window.update();
		}
	}
}