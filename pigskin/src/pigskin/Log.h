#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace PigSkin {

	class PS_API Log
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


// Core log macros
#define PS_CORE_TRACE(...) ::PigSkin::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PS_CORE_INFO(...) ::PigSkin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PS_CORE_WARN(...) ::PigSkin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PS_CORE_ERROR(...) ::PigSkin::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PS_CORE_CRITICAL(...) ::PigSkin::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define PS_TRACE(...)         ::PigSkin::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PS_INFO(...)          ::PigSkin::Log::GetClientLogger()->info(__VA_ARGS__)
#define PS_WARN(...)          ::PigSkin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PS_ERROR(...)         ::PigSkin::Log::GetClientLogger()->error(__VA_ARGS__)
#define PS_CRITICAL(...)      ::PigSkin::Log::GetClientLogger()->critical(__VA_ARGS__)