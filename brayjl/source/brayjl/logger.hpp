#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <memory>

namespace brayjl {
	class Logger {
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return m_CoreLogger; }
	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
	};
}

#define BRAYJL_CORE_TRACE(...)		::brayjl::Logger::getCoreLogger()->trace(__VA_ARGS__);
#define BRAYJL_CORE_INFO(...)		::brayjl::Logger::getCoreLogger()->info(__VA_ARGS__);
#define BRAYJL_CORE_WARN(...)		::brayjl::Logger::getCoreLogger()->warn(__VA_ARGS__);
#define BRAYJL_CORE_ERROR(...)		::brayjl::Logger::getCoreLogger()->error(__VA_ARGS__);
#define BRAYJL_CORE_CRITICAL(...)	::brayjl::Logger::getCoreLogger()->critical(__VA_ARGS__);

#endif // !LOGGER_HPP