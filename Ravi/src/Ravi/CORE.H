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

#define BIT(x) (1 << x)