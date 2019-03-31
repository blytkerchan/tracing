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
	EXPORT TracingTargets
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	DESTINATION lib
	)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/tracing/tracing-config-version.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

export(EXPORT TracingTargets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/tracing/tracing-targets.cmake"
	NAMESPACE Vlinder::
)
configure_file(tracing-config.cmake "${CMAKE_CURRENT_BINARY_DIR}/tracing/tracing-config.cmake"
	COPYONLY
)

set(ConfigPackageLocation lib/cmake/tracing)
install(EXPORT TracingTargets
	FILE tracing-targets.cmake
	NAMESPACE Vlinder::
	DESTINATION ${ConfigPackageLocation}
)
install(
	FILES tracing-config.cmake "${CMAKE_CURRENT_BINARY_DIR}/tracing/tracing-config-version.cmake"
	DESTINATION ${ConfigPackageLocation}
	COMPONENT Devel
)

