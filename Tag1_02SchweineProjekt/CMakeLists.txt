cmake_minimum_required (VERSION 3.12)

project(Tag1_02SchweineProjekt)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)


add_executable(
	Tag1_02SchweineProjekt 
	source/main.cpp
		source/tiere/Schwein.h source/Stapel.cpp source/Stapel.h source/Dependency.h source/DependencyImpl.h source/MyServiceUsingDependency.h source/OtherDEpendecyImpl.h source/MultipliziererImpl.h source/Multiplizierer.h source/MultipliziererOptimierer.h)


# Add tests
add_subdirectory(tests)

