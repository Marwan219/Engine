
#pragma once

#ifdef EG_PLATFORM_WINDOWS 
	#ifdef EG_BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
	#else
		#define	ENGINE_API __declspec(dllimport)
	#endif
#else
	#error Engine supports only windows
#endif



/*
#ifdef EG_DEBUG
	#define EG_ENABLE_ASSERTS
#endif
*/
#ifdef EG_DEBUG
	#define EG_ENABLE_ASSERTS
#endif

//it checks a certain a condition and then logs a message if it fails causes a debug break in other words setting
//a breakpoint, so it breaks the debuuger on this line of code ,so if an assertion fialse can see what has gone wrong 
#ifdef EG_ENABLE_ASSERTS
	#define EG_ASSERT(x, ...) { if(!(x)) { EG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define EG_CORE_ASSERT(x, ...) { if(!(x)) {EG_CORE_ERROR("Assertion Failed {0}" , __VA_ARGS__); __debugbreak();}}
#else
	#define EG_ASSERT(X, ...)
	#define	EG_CORE_ASSERT(x , ...)
#endif //EG_ENABLE_ASSERTS


#define BIT(x) (1 << x)

#define EG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)