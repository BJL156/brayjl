#include "brayjl.hpp"

class Sandbox : public brayjl::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

brayjl::Application* createApplication() {
	return new Sandbox();
}