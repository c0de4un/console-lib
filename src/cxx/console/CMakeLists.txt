# // ------------------------------------------------------------------------------
#
# This is simple utility-lib for console api (Windows & Linux).
# 
# @Features:
# - colors using platform-specific console api ;
# - localization (encoding) help (to avoid ifdef and other platfomr-specific code) ;
# - drawing primities using console-output ;
#
# License: see "LICENSE" file.
# Tools: Visual Studio Community, Ninja, CMake, MSVC || CLang || GCC.
# API: C/C++.
# Platforms: Any with C++.
# 
# // ------------------------------------------------------------------------------

# =================================================================================
# CMake Meta-Data
# =================================================================================

# CMake-Version
cmake_minimum_required ( VERSION 3.6 FATAL_ERROR )

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "console-lib" )

# Project Version
set ( PROJECT_VERSION 0.1.1 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION "Console-helper utility lib." LANGUAGES C CXX )

# C Version
#set ( CMAKE_C_STANDARD 99 )

# C++ Version
#set ( CMAKE_CXX_STANDARD 11 )

# Make Build Libs & Executables to be position-independent, like SHARED libs.
#set ( CMAKE_POSITION_INDEPENDENT_CODE ON )

# =================================================================================
# CONFIGS
# =================================================================================

# CMake include-files dir (Global variable for all sub-projects).
if ( NOT DEFINED PROJECT_CMAKE_INCLUDES_DIR )
	set ( PROJECT_CMAKE_INCLUDES_DIR "${CMAKE_SOURCE_DIR}/cmake" )
endif ( NOT DEFINED PROJECT_CMAKE_INCLUDES_DIR )

# Platform-specific
if ( NOT DEFINED PROJECT_PLATFORM_DETECTED )
	include ( "${PROJECT_CMAKE_INCLUDES_DIR}/platform.cmake" )
endif ( NOT DEFINED PROJECT_PLATFORM_DETECTED )

# Paths
if ( NOT DEFINED PROJECT_BIN_DIR )
	include ( "${PROJECT_CMAKE_INCLUDES_DIR}/paths.cmake" )
endif ( NOT DEFINED PROJECT_BIN_DIR )

# =================================================================================
# HEADERS
# =================================================================================

# CONFIGS
set ( PROJECT_HEADERS
	"cfg/defines_cfg.hpp" )

# CORE
set ( PROJECT_HEADERS ${PROJECT_HEADERS}
	# CORE
	"core/ConsoleFactory.hpp"
	"core/Console.hpp"
	"core/BaseConsole.hpp"
	"core/IConsole.hxx" )

# =================================================================================
# SOURCES
# =================================================================================

set ( PROJECT_SOURCES
	# CORE
	"core/ConsoleFactory.cpp"
	"core/Console.cpp"
	"core/BaseConsole.cpp" )

# =================================================================================
# MODULES
# =================================================================================

# PLATFORM
if ( WIN32 OR WIN64 ) # WINDOWS
	include ( "windows/windows.cmake" )
elseif ( LINUX ) # LINUX
	include ( "linux/linux.cmake" )
else ( WIN32 OR WIN64 ) # ?
	# ERROR
	message ( FATAL_ERROR "${PROJECT_NAME} - can't include proper platform-implementation, configuration required !" )
endif ( WIN32 OR WIN64 )

# =================================================================================
# BUILD
# =================================================================================

# Add STATIC Library-Object
add_library ( console_lib STATIC ${PROJECT_HEADERS} ${PROJECT_SOURCES} )

# Configure STATIC Library-Object
set_target_properties ( console_lib PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BIN_DIR}"
)

# INFO
message ( STATUS "${PROJECT_NAME} - STATIC Library Build Complete. Use <console_lib> CMake-variable to link." )