
cmake_minimum_required( VERSION 3.16 )
project( ScriptingMachine5 VERSION 1.0 LANGUAGES CXX )

## std::filesystem needs C++17
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

option( SM5_EXAMPLES "Build examples for ScriptingMachine5" OFF )

set( SM5_SOURCES
	"src/Assembly.cpp"
	"src/ErrorWriter.cpp"
	"src/Host.cpp"
	"src/Library.cpp"
	"src/Utility.hpp"

	"src/DotNet/coreclr_delegates.h"
	"src/DotNet/hostfxr.h"
)

set(SM5_HEADERS
	"include/Assembly.hpp"
	"include/ErrorWriter.hpp"
	"include/Host.hpp"
	"include/Library.hpp"

	"include/common.h"
	"include/smv.h")

## VS filters
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SM5_SOURCES} ${SM5_HEADERS} )

## ScriptingMachine5 library
add_library( ScriptingMachine5 STATIC ${SM5_SOURCES} ${SM5_HEADERS} )
target_include_directories( ScriptingMachine5 PUBLIC "include" PRIVATE "src" )

## Examples
if(SM5_EXAMPLES)
	add_subdirectory( examples/Example1_BasicUsage )
	add_subdirectory( examples/Example2_PassingData )
endif()
