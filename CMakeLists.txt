cmake_minimum_required(VERSION 3.24 FATAL_ERROR)
project(ply VERSION 0.1 LANGUAGES CXX)

# Make including this file idempotent
#
if (TARGET ply OR TARGET ply::ply)
  return()
endif()

# If this is the current project.
#
if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
  # Laod the cmake recipes and utilities.
  #
  include(${CMAKE_CURRENT_LIST_DIR}/cmake/load_cmake_helpers.cmake)

  # Generate the tests and tools
  #
  option(PLY_TEST "Generate the tests." ON)
  option(PLY_TOOLS "Build the tools." OFF)

  # compile_commands.json
  #
  symlink_compile_commands()

  # Convenience targets for git operations
  #
  make_submodule_pull_target()

else()
  option(PLY_TEST "Generate the tests." OFF)
  option(PLY_TOOLS "Build the tools." OFF)
endif()

# Put executables in the top-level binary directory
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Output parameters
#
message("-- ply: Install Prefix: ${CMAKE_INSTALL_PREFIX}")
message("-- ply: test ${PLY_TEST}")
message("-- ply: tools ${PLY_TOOLS}")

# The config.h contains the base location of the shared artifacts
# which is different for build versus install. We configure the file
# once for each. The install version is later copied to the final
# destination by the install cmake.
#
set(PLY_SHARE_DIR ${CMAKE_BINARY_DIR}/share)
configure_file(config/config.h.in ${CMAKE_BINARY_DIR}/include/ply/config.h @ONLY)

set(PLY_SHARE_DIR ${CMAKE_INSTALL_PREFIX}/share)
configure_file(config/config.h.in ${CMAKE_BINARY_DIR}/forinstall/include/ply/config.h @ONLY)

# Setup the compilation before adding dependencies
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
add_compile_options(-O)
add_compile_options(-stdlib=libc++)
add_link_options(-stdlib=libc++)

# Add our dependencies
#
add_util()
add_inja()

# Build the library
#
set(SOURCES
  ply/generate.cpp
  )

foreach(NAME ${SOURCES})
  list(APPEND FILES "src/${NAME}")
endforeach()

add_library(ply ${FILES})
add_library(ply::ply ALIAS ply)

# Define the header files for this library.
#
file(GLOB_RECURSE PUBLIC_INCLUDE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} include/*.h)
target_sources(ply PUBLIC FILE_SET HEADERS BASE_DIRS include FILES ${PUBLIC_INCLUDE_FILES})

target_link_libraries(ply PUBLIC util::util PRIVATE pantor::inja)

target_include_directories(ply PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

if(PLY_TOOLS)
  set(TOOLS
    ply_t0
    ply_t1
    )

  foreach(NAME ${TOOLS})
    add_executable(${NAME} src/tools/${NAME}.cpp)
    target_link_libraries(${NAME} ply)
  endforeach()
endif()

if(PLY_TEST)
  add_gtest()
  add_subdirectory(test)
endif()

install_config(ply)
install(FILES ${CMAKE_BINARY_DIR}/forinstall/include/ply/config.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ply)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/share DESTINATION .)
