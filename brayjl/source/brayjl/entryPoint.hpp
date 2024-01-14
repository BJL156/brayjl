#ifndef ENTRY_POINT_HPP
#define ENTRY_POINT_HPP

#include "application.hpp"
#include "logger.hpp"

extern brayjl::Application *createApplication();

int main() {
	brayjl::Logger::init();

	BRAYJL_CORE_INFO("creating application.");
	brayjl::Application* app = createApplication();
	BRAYJL_CORE_INFO("application created successfully.");

	app->run();

	BRAYJL_CORE_WARN("shutting down application.");
	delete app;

	return 0;
}

#endif // !ENTRYPOINT_HPP