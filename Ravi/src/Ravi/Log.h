#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Ravi {

	class RAVI_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr < spdlog::logger> s_CoreLogger;
		static std::shared_ptr < spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define RV_CORE_TRACE(...) ::Ravi::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RV_CORE_INFO(...)  ::Ravi::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RV_CORE_WARN(...)  ::Ravi::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RV_CORE_ERROR(...) ::Ravi::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RV_CORE_FATAL(...) ::Ravi::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros		 
#define RV_TRACE(...)      ::Ravi::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RV_INFO(...)       ::Ravi::Log::GetClientLogger()->info(__VA_ARGS__)
#define RV_WARN(...)       ::Ravi::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RV_ERROR(...)      ::Ravi::Log::GetClientLogger()->error(__VA_ARGS__)
#define RV_FATAL(...)      ::Ravi::Log::GetClientLogger()->fatal(__VA_ARGS__)