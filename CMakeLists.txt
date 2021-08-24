cmake_minimum_required(VERSION 3.16)

set(INKCPP_SOURCE_DIR $ENV{INKCPP_SOURCE_DIR})
if( NOT DEFINED INKCPP_SOURCE_DIR )
set(INKCPP_SOURCE_DIR "${CMAKE_SOURCE_DIR}/../inkcpp")
endif()


if(NOT EXISTS ${INKCPP_SOURCE_DIR})
  message(FATAL_ERROR "Folder ${INKCPP_SOURCE_DIR} does not exist.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(inkpython)

include_directories("${INKCPP_SOURCE_DIR}/inkcpp/include/")
include_directories("${INKCPP_SOURCE_DIR}/shared/public/")
include_directories("${INKCPP_SOURCE_DIR}/shared/private/")
include_directories("${CMAKE_SOURCE_DIR}/src")


file (GLOB SOURCE_FILES "${INKCPP_SOURCE_DIR}/inkcpp/*.cpp")
file (GLOB HEADER_FILES "${INKCPP_SOURCE_DIR}/shared/public/*.h" "${INKCPP_SOURCE_DIR}/shared/private/*.h" "${INKCPP_SOURCE_DIR}/inkcpp/*.h" "${INKCPP_SOURCE_DIR}/inkcpp/include/*.h")
file (GLOB PYTHON_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.h")



set(PYTHON_SITE_PACKAGES $ENV{PYTHON_SITE_PACKAGES})
if( NOT DEFINED PYTHON_SITE_PACKAGES )
find_package (Python3 COMPONENTS Interpreter Development)
set(PYTHON_SITE_PACKAGES "${Python3_SITEARCH}")
endif()

include("${PYTHON_SITE_PACKAGES}/pybind11/share/cmake/pybind11/pybind11Config.cmake")
#find_package(pybind11 REQUIRED)

pybind11_add_module(inkpython 
	${SOURCE_FILES}
	${HEADER_FILES}
	${PYTHON_FILES}
)

target_link_libraries(inkpython PUBLIC)

install(TARGETS inkpython
  COMPONENT python
  LIBRARY DESTINATION ${PYTHON_SITE_PACKAGES}
  )