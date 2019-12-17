#ifndef tracing_prologue_hpp
#define tracing_prologue_hpp

#ifndef TRACING_API
#	ifdef _MSC_VER
#		ifdef tracing_EXPORTS
#			define TRACING_API __declspec(dllexport)
#		else
#			define TRACING_API __declspec(dllimport)
#		endif
#	else
#		define TRACING_API
#	endif
#endif

#endif

