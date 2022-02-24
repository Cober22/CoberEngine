#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Cober {

	class CB_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core LOG MACROS
#define CB_CORE_TRACE(...)	::Cober::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CB_CORE_INFO(...)	::Cober::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CB_CORE_WARN(...)	::Cober::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CB_CORE_ERROR(...)	::Cober::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CB_CORE_FATAL(...)	::Cober::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CB_TRACE(...)		::Cober::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CB_INFO(...)		::Cober::Log::GetClientLogger()->info(__VA_ARGS__)
#define CB_WARN(...)		::Cober::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CB_ERROR(...)		::Cober::Log::GetClientLogger()->error(__VA_ARGS__)
#define CB_FATAL(...)		::Cober::Log::GetClientLogger()->fatal(__VA_ARGS__)