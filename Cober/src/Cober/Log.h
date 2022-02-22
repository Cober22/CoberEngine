#pragma once

#include <memory>

#include "Core.h";
#include "spdlog/spdlog.h";
using namespace spdlog;

namespace Cober {

	class CB_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<logger> s_CoreLogger;
		static std::shared_ptr<logger> s_ClientLogger;
	};
}

// Core LOG MACROS
#define CORE_TRACE(...)	Cober::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)	Cober::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)	Cober::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)	Cober::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...)	Cober::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TRACE(...)		Cober::Log::GetClientLogger()->trace(__VA_ARGS__)
#define INFO(...)		Cober::Log::GetClientLogger()->info(__VA_ARGS__)
#define WARN(...)		Cober::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ERROR(...)		Cober::Log::GetClientLogger()->error(__VA_ARGS__)
#define FATAL(...)		Cober::Log::GetClientLogger()->fatal(__VA_ARGS__)
