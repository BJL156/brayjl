#include "Shader.hpp"

brayjl::Shader::Shader(std::string vertexFilepath, std::string fragmentFilepath) {
	createShaderProgram(vertexFilepath, fragmentFilepath);
}

brayjl::Shader::Shader() {

}

brayjl::Shader::~Shader() {
	glDeleteProgram(m_Id);
}

void brayjl::Shader::init(std::string vertexFilepath, std::string fragmentFilepath) {
	createShaderProgram(vertexFilepath, fragmentFilepath);
}

void brayjl::Shader::createShaderProgram(std::string& vertexFilepath, std::string& fragmentFilepath) {
	std::string vertexCode = utils::readFile(vertexFilepath);
	std::string fragmentCode = utils::readFile(fragmentFilepath);

	const char* vertexShaderSource = vertexCode.c_str();
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);

	const char* fragmentShaderSource = fragmentCode.c_str();
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);

	m_Id = glCreateProgram();
	glAttachShader(m_Id, vertexShader);
	glAttachShader(m_Id, fragmentShader);
	glLinkProgram(m_Id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}