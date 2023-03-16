#pragma once


#ifdef PS_PLATFORM_WINDOWS 
	#ifdef PS_BUILD_DLL
		#define PS_API __declspec(dllexport)
	#else
		#define PS_API __declspec(dllimport)
	#endif // PS_BUILD_DLL

#else
#error PigSkin only supports Windows!

#endif // PS_PLATFORM_WINDOWS 

#define BIT(x) (1 << x)