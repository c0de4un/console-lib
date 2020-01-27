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
set ( PROJECT_NAME "console-lib-demo" )

# Project Version
set ( PROJECT_VERSION 1.0.0 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION "Console-helper utility lib demo." LANGUAGES C CXX )

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
set ( PROJECT_CMAKE_INCLUDES_DIR "${CMAKE_SOURCE_DIR}/cmake" )

# Platform-specific
include ( "${PROJECT_CMAKE_INCLUDES_DIR}/platform.cmake" )

# Paths
include ( "${PROJECT_CMAKE_INCLUDES_DIR}/paths.cmake" )

# =================================================================================
# HEADERS
# =================================================================================

set ( PROJECT_HEADERS
	"src/cxx/demo/main.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( PROJECT_SOURCES
	"src/cxx/demo/main.cpp" )

# =================================================================================
# MODULES
# =================================================================================

# console-lib
add_subdirectory ( "src/cxx/console" )

# Tests

# Demo

# =================================================================================
# BUILD EXECUTABLE
# =================================================================================

# Add Executable-Object
add_executable ( console_demo ${PROJECT_HEADERS} ${PROJECT_SOURCES} )

# Include public (interface) headers of console-lib.
target_include_directories ( console_demo PUBLIC "src/cxx/console" )

# Configure Executable-Object
set_target_properties ( console_demo PROPERTIES
	OUTPUT_NAME "console_util_demo"
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BIN_DIR}"
	VERSION ${PROJECT_VERSION} )

# Link Executable
target_link_libraries ( console_demo console_lib )