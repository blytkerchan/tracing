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

