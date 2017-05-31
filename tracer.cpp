#include "tracer.hpp"

namespace Vlinder { namespace Tracing {
void Tracer::TraceProxy::operator()(char const *fmt, ...) const
{
	va_list ap;
	va_start(ap, fmt);
	tracer_->trace(filename_, line_, fmt, ap);
	va_end(ap);

}
void Tracer::trace(char const *filename, int line, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	trace(filename, line, fmt, ap);
	va_end(ap);
}
void Tracer::trace(char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	trace(fmt, ap);
	va_end(ap);
}
}}

Vlinder::Tracing::Tracer * tracer__ __attribute__((weak)) (nullptr);

