set(FIND_SUBGINE_LIB_PATHS
	~/Library/Frameworks
	/Library/Frameworks
	/usr/local
	/usr
	/sw
	/opt/local
	/opt/csw
	/opt)

find_path(SUBGINE_INCLUDE_DIR subgine/system.hpp
	PATH_SUFFIXES include
	PATHS
	~/Library/Frameworks
	/Library/Frameworks
	/usr/local/
	/usr/
	/sw # Fink
	/opt/local/ # DarwinPorts
	/opt/csw/ # Blastwave
	/opt/)

set(SUBGINE_FOUND TRUE)

foreach(FIND_SUBGINE_COMPONENT ${SUBGINE_FIND_COMPONENTS})
	string(TOLOWER ${FIND_SUBGINE_COMPONENT} FIND_SUBGINE_COMPONENT_LOWER)
	string(TOUPPER ${FIND_SUBGINE_COMPONENT} FIND_SUBGINE_COMPONENT_UPPER)
    set(FIND_SUBGINE_COMPONENT_NAME subgine-${FIND_SUBGINE_COMPONENT_LOWER})

	find_library(SUBGINE_${FIND_SUBGINE_COMPONENT_UPPER}_LIBRARY
		NAMES ${FIND_SUBGINE_COMPONENT_NAME}
		PATH_SUFFIXES lib64 lib
		PATHS ${FIND_SUBGINE_LIB_PATHS})

	if (SUBGINE_${FIND_SUBGINE_COMPONENT_UPPER}_LIBRARY)
		set(SUBGINE_LIBRARIES ${SUBGINE_LIBRARIES} "${SUBGINE_${FIND_SUBGINE_COMPONENT_UPPER}_LIBRARY}")
	else()
		set(SUBGINE_FOUND FALSE)
	endif()
	
	MARK_AS_ADVANCED(SUBGINE_${FIND_SUBGINE_COMPONENT_UPPER}_LIBRARY)
endforeach()

if(ENTER_FOREACH AND NOT SUBGINE_FOUND)
		set(SUBGINE_FOUND FALSE)
	message(ERROR "Grosse, grosse, grosse erreur!")
else()
	message("les librairies sont trouve!::${SUBGINE_LIBRARIES}")
endif()