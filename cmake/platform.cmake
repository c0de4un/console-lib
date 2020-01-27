# // ------------------------------------------------------------------------------
#
# This CMake-file contains logic to detect and/or define platform-specific vars.
# 
# // ------------------------------------------------------------------------------

# Global flag, platform detected.
set ( PROJECT_PLATFORM_DETECTED OFF )

# DETECT LINUX
if ( NOT ANDROID AND UNIX AND NOT DEFINED LINUX AND NOT APPLE )
		
	# LINUX ON
	set ( LINUX ON )
	
	# Platform Name
	set ( PROJECT_PLATFORM "LINUX" )
		
	# Add definition.
	add_definitions ( -DLINUX=1 )
	
	# Set Directory Prefix
    set ( PLATFORM_DIR "linux" )
	
	# Platform Detected.
	set ( PROJECT_PLATFORM_DETECTED ON )
	
endif ( NOT ANDROID AND UNIX AND NOT DEFINED LINUX AND NOT APPLE )

# Other platforms.
if ( NOT PROJECT_PLATFORM_DETECTED )
	if ( ANDROID ) # ANDROID
		# Platform Name
		set ( PROJECT_PLATFORM "ANDROID" )
		
		# Add definition.
		add_definitions ( -DANDROID=1 )
	
		# Set Directory Prefix
		set ( PLATFORM_DIR "android" )
	
		# Platform Detected.
		set ( PROJECT_PLATFORM_DETECTED ON )
	elseif ( WIN32 OR WIN64 ) # WINDOWS
			# Platform Name
			set ( PROJECT_PLATFORM "WINDOWS" )
			
			# Add definition.
			add_definitions ( -DWINDOWS=1 )
	
			# Set Directory Prefix
			set ( PLATFORM_DIR "windows" )
	
			# Platform Detected.
			set ( PROJECT_PLATFORM_DETECTED ON )
	elseif ( APPLE ) # APPLE
		# Platform Name
		set ( PROJECT_PLATFORM "APPLE" )
		
		# Add definition.
		add_definitions ( -DAPPLE=1 )
	
		# Set Directory Prefix
		set ( PLATFORM_DIR "apple" )
	
		# Platform Detected.
		set ( PROJECT_PLATFORM_DETECTED ON )
	endif ( ANDROID )
endif ( NOT PROJECT_PLATFORM_DETECTED )

# Check output-results.
if ( NOT PROJECT_PLATFORM_DETECTED )
	# ERROR
	message ( FATAL_ERROR "${PROJECT_NAME} - can't detect platform ! Configuration required." )
else ( NOT PROJECT_PLATFORM_DETECTED )
	# INFO
	message ( STATUS "${PROJECT_NAME} - current platform = ${PROJECT_PLATFORM}" )
endif ( NOT PROJECT_PLATFORM_DETECTED )