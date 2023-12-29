#include "logger.hpp"

namespace brayjl {
	std::shared_ptr<spdlog::logger> Logger::m_CoreLogger;

	void Logger::init() {
		std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> consoleSink;
		consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

		std::shared_ptr<spdlog::sinks::basic_file_sink_mt> fileSink;
		fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("log.txt", true);

		spdlog::sinks_init_list sinksInitList = {
			consoleSink,
			fileSink
		};

		m_CoreLogger = std::make_shared<spdlog::logger>("brayjl", sinksInitList);
		spdlog::register_logger(m_CoreLogger);
		m_CoreLogger->set_level(spdlog::level::trace);
	}
}