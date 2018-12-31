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
set_target_properties(tracing PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(tracing PROPERTIES SOVERSION 1)
install(
	TARGETS tracing
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	DESTINATION lib
	)

