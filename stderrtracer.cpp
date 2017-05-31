#include "stderrtracer.hpp"
#include <cstdio>

namespace Vlinder { namespace Tracing {
/*virtual */void StdErrTracer::trace(char const *filename, int line, char const *fmt, va_list args)/* = 0*/
{
	fprintf(stderr, "%s (%d): ", filename, line);
	trace(fmt, args);
}
/*virtual */void StdErrTracer::trace(char const *fmt, va_list args)/* = 0*/
{
	vfprintf(stderr, fmt, args);
}
}}


