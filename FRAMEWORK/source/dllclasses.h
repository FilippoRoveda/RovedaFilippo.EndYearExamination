#pragma once

#ifdef DLL_EXPORT
#define DECLSPEC __declspec(dllexport)
#else 
#define DECLSPEC __declspec(dllimport)
#endif
