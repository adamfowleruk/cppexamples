# 2.8.2 and above can handle openssl letter versions (E.g. 1.0.1h), which is required to get fixed version of openssl
cmake_minimum_required (VERSION 2.8.2)
project (cppexamples)

# See http://www.cmake.org/cmake/help/cmake_tutorial.html for extra help on this file

# EDITABLE SETTINGS BEGIN

set (cppexamples_VERSION_MAJOR 0)
set (cppexamples_VERSION_MINOR 1)

# EDITABLE SETTINGS END

#set (CMAKE_MODULE_PATH "../cmake/modules")


# SYSTEM DETECTION

# Platform (not compiler) specific settings
if(IOS)

  # The cxx_flags must be set here, because the ios-cmake toolchain file unfortunately sets "-headerpad_max_install_names" which is not a valid clang flag.
  set(CMAKE_CXX_FLAGS "-fvisibility=hidden -fvisibility-inlines-hidden")

  set(BUILD_SHARED_LIBS OFF)
elseif(UNIX) # This includes OSX

  option(BUILD_SHARED_LIBS "Build shared Libraries." ON)
elseif(WIN32)
  option(BUILD_SHARED_LIBS "Build shared Libraries." ON)

  add_definitions(-DUNICODE)

  if(NOT BUILD_SHARED_LIBS)
    # This causes cmake to not link the test libraries separately, but instead hold onto their object files.
    set(TEST_LIBRARY_TARGET_TYPE OBJECT)
  endif()

  set(LIB lib)
else()
  message("-- Unsupported Build Platform.")
endif()

# Casablanca fix for versions before 2.7.0 (CLang issue)
add_definitions("-Wno-error=unused-local-typedefs")
add_definitions("-Wnounused-local-typedefs")

# Compiler (not platform) specific settings
if(("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang") OR IOS)
  message("-- Setting clang options")

  set(WARNINGS "-Wall -Wextra -Wcast-qual -Wconversion -Wformat=2 -Winit-self -Winvalid-pch -Wmissing-format-attribute -Wmissing-include-dirs -Wpacked -Wredundant-decls")
  set(OSX_SUPPRESSIONS "-Wno-overloaded-virtual -Wno-sign-conversion -Wno-deprecated -Wno-unknown-pragmas -Wno-reorder -Wno-char-subscripts -Wno-switch -Wno-unused-parameter -Wno-unused-variable -Wno-deprecated -Wno-unused-value -Wno-unknown-warning-option -Wno-return-type-c-linkage -Wno-unused-function -Wno-sign-compare -Wno-shorten-64-to-32 -Wno-reorder")
  set(WARNINGS "${WARNINGS} ${OSX_SUPPRESSIONS}")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -Wno-return-type-c-linkage -Wno-unneeded-internal-declaration")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-strict-aliasing")
  set(STRICT_CXX_FLAGS ${WARNINGS} "-Werror -pedantic")
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
  message("-- Setting gcc options")

  set(WARNINGS "-Wall -Wextra -Wunused-parameter -Wcast-align -Wcast-qual -Wconversion -Wformat=2 -Winit-self -Winvalid-pch -Wmissing-format-attribute -Wmissing-include-dirs -Wpacked -Wredundant-decls -Wunreachable-code")
  set(LINUX_SUPPRESSIONS "-Wno-deprecated -Wno-unknown-pragmas -Wno-reorder -Wno-unused-function -Wno-char-subscripts -Wno-switch -Wno-unused-but-set-parameter -Wno-deprecated -Wno-unused-value -Wno-unused-local-typedefs")

  set(WARNINGS "${WARNINGS} ${LINUX_SUPPRESSIONS}")
  set(LD_FLAGS "${LD_FLAGS} -Wl,-z,defs")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-strict-aliasing")
  set(STRICT_CXX_FLAGS ${WARNINGS} "-Werror -pedantic")
else()
  message("-- Unknown compiler, success is doubtful.")
endif()



# Have CMake do a search and replace on the version numbers in our config.h file
configure_file (
  "${PROJECT_SOURCE_DIR}/cppexamplesConfig.h.in"
  "${PROJECT_BINARY_DIR}/cppexamplesConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find cppexamplesConfig.h
include_directories("${PROJECT_BINARY_DIR}")


#include_directories (BEFORE ../include /usr/include/libxml2)

add_executable(testpointerwrapper
    testpointerwrapper.cpp
    TestClasses.cpp
)
add_executable(teststringholder
    teststringholder.cpp
    TestClasses.cpp
)
add_executable(teststringreference
    teststringreference.cpp
    TestClasses.cpp
)
target_link_libraries(testpointerwrapper )
target_link_libraries(teststringholder )
target_link_libraries(teststringreference )

