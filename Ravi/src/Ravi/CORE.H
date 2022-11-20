#pragma once

#ifdef RV_PLATFORM_WINDOWS
	#ifdef RV_BUILD_DLL
		#define RAVI_API __declspec(dllexport)
	#else
		#define RAVI_API __declspec(dllimport)
	#endif
#else 
	#error Ravi only supports Windows!

#endif

#ifdef RV_ENABLED_ASSERTS
	#define RV_ASSERT(x, ...) { if(!x)) { RV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RV_CORE_ASSERT(x, ...) { if(!x)) { RV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RV_ASSERT(x, ...)
	#define RV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)