/* Copyright (c) 2017 Ronald Landheer-Cieslak
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
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

		void operator()(bool should_trace, unsigned int parts, char const *fmt, ...) const;

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

	void setMask(unsigned int mask) noexcept { mask_ = mask; };
	unsigned int getMask() const noexcept { return mask_; }

	TraceProxy trace(bool should_trace, unsigned int parts, char const *filename, int line) { return TraceProxy(this, filename, line); }
	void trace(bool should_trace, unsigned int parts, char const *filename, int line, char const *fmt, ...);
	void trace(bool should_trace, unsigned int parts, char const *fmt, ...);
	virtual void trace(char const *filename, int line, char const *fmt, va_list args) = 0;
	virtual void trace(char const *fmt, va_list args) = 0;

private :
	unsigned int mask_ = 0;
};
}}
extern Vlinder::Tracing::Tracer *tracer__;

#endif
