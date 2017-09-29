#include "tracer.hpp"

namespace Vlinder { namespace Tracing {
void Tracer::TraceProxy::operator()(bool should_trace, unsigned int parts, char const *fmt, ...) const
{
	if (should_trace && ((tracer_->getMask() & parts) != 0))
	{
		va_list ap;
		va_start(ap, fmt);
		tracer_->trace(filename_, line_, fmt, ap);
		va_end(ap);
	}
	else
	{ /* ignore */ }
}
void Tracer::trace(bool should_trace, unsigned int parts, char const *filename, int line, char const *fmt, ...)
{
	if (should_trace && ((mask_ & parts) != 0))
	{
		va_list ap;
		va_start(ap, fmt);
		trace(filename, line, fmt, ap);
		va_end(ap);
	}
	else
	{ /* ignore */ }
}
void Tracer::trace(bool should_trace, unsigned int parts, char const *fmt, ...)
{
	if (should_trace && ((mask_ & parts) != 0))
	{
		va_list ap;
		va_start(ap, fmt);
		trace(fmt, ap);
		va_end(ap);
	}
	else
	{ /* ignore */ }
}
}}

Vlinder::Tracing::Tracer *tracer__ __attribute__((weak)) (nullptr);

