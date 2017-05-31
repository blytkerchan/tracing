#ifndef vlinder_tracing_tracer_hpp
#define vlinder_tracing_tracer_hpp

#include <cstdarg>

namespace Vlinder { namespace Tracing {
class Tracer
{
public :
	struct TraceProxy
	{
		TraceProxy(Tracer *tracer, char const *filename, int line)
			: tracer_(tracer)
			, filename_(filename)
			, line_(line)
		{ /* no-op */ }

		void operator()(char const *fmt, ...) const;

		Tracer *tracer_;
		char const *filename_;
		int line_;
	};
	Tracer() = default;
	Tracer(Tracer const &) = delete;
	Tracer(Tracer &&) = default;
	virtual ~Tracer() = default;

	Tracer& operator=(Tracer const &) = delete;
	Tracer& operator=(Tracer &&) = default;

	TraceProxy trace(char const *filename, int line) { return TraceProxy(this, filename, line); }
	void trace(char const *filename, int line, char const *fmt, ...);
	void trace(char const *fmt, ...);
	virtual void trace(char const *filename, int line, char const *fmt, va_list args) = 0;
	virtual void trace(char const *fmt, va_list args) = 0;
};
}}
extern Vlinder::Tracing::Tracer *tracer__;

#endif
