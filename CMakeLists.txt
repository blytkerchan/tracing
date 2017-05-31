cmake_minimum_required(VERSION 3.5)
set(VLINDER_USING_CXX14 1)
include(${CMAKE_SOURCE_DIR}/cmake/settings.cmake)

enable_testing()

add_library(tracing SHARED
	stderrtracer.cpp
	stderrtracer.hpp
	tracer.cpp
	tracer.hpp
	)
