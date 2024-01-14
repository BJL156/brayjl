#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>

#include "brayjl/utils.hpp"
#include "brayjl/logger.hpp"

#include <string>
#include <iostream>

namespace brayjl {
	class Shader {
	public:
		Shader(std::string vertexFilepath, std::string fragmentFilepath);
		Shader();
		~Shader();

		void init(std::string vertexFilepath, std::string fragmentFilepath);
		
		void use() { glUseProgram(m_Id); }
	private:
		void createShaderProgram(std::string& vertexFilepath, std::string& fragmentFilepath);

		unsigned int m_Id;
	};
}

#endif // !SHADER_HPP