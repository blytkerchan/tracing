#ifndef vlinder_tracing_stderrerrtracer_hpp
#define vlinder_tracing_stderrerrtracer_hpp

#include "tracer.hpp"

namespace Vlinder { namespace Tracing {
class StdErrTracer : public Tracer
{
public :
	/*virtual */void trace(char const *filename, int line, char const *fmt, va_list args)/* = 0*/;
	/*virtual */void trace(char const *fmt, va_list args)/* = 0*/;
};
}}

#endif

