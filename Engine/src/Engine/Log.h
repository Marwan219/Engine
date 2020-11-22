#pragma once

#include<memory>
#include"Core.h"
#include"spdlog/spdlog.h"

namespace Engine {
	class ENGINE_API Log
	{
	public:
		static void Init();

		inline  static std::shared_ptr<spdlog::logger> & GetCorelogger() { return s_Corelogger; }
		inline  static std::shared_ptr<spdlog::logger> & GetClientlogger() { return s_Clientlogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Corelogger;
		static std::shared_ptr<spdlog::logger> s_Clientlogger;
		 
	};
 
	
}

//core logs macros

#define EG_CORE_TRACE(...)		::Engine::Log::GetCorelogger()->trace(__VA_ARGS__)
#define EG_CORE_INFO(...)		::Engine::Log::GetCorelogger()->info(__VA_ARGS__)
#define EG_CORE_WARN(...)		::Engine::Log::GetCorelogger()->warn(__VA_ARGS__)
#define EG_CORE_ERROR(...)		::Engine::Log::GetCorelogger()->error(__VA_ARGS__)
#define EG_CORE_FATAL(...)		::Engine::Log::GetCorelogger()->fatal(__VA_ARGS__)

//client logs macros


#define EG_TRACE(...)		::Engine::Log::GetClientlogger()->trace(__VA_ARGS__)
#define EG_INFO(...)		::Engine::Log::GetClientlogger()->info(__VA_ARGS__)
#define EG_WARN(...)		::Engine::Log::GetClientlogger()->warn(__VA_ARGS__)
#define EG_ERROR(...)		::Engine::Log::GetClientlogger()->error(__VA_ARGS__)
#define EG_FATAL(...)		::Engine::Log::GetClientlogger()->fatal(__VA_ARGS__)
