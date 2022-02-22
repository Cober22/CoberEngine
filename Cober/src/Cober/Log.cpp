#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Cober {

	std::shared_ptr<logger> Log::s_CoreLogger;
	std::shared_ptr<logger> Log::s_ClientLogger;

	// Initialise format logging
	void Log::Init() 
	{
		set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = stdout_color_mt("COBER");
		s_CoreLogger->set_level(level::trace);

		s_ClientLogger = stdout_color_mt("APP");
		s_CoreLogger->set_level(level::trace);
	}

}