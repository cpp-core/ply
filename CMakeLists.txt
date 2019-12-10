cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(cxx-ply VERSION 0.1 LANGUAGES CXX)

# Make including this file idempotent
#
if (TARGET cxx_ply)
  return()
endif()

# Configuration variables.
#
# Build the tests and set directories if this is the master project.
#
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(PLY_TEST ON CACHE BOOL "Generate the tests.")
  set(PLY_TOOLS ON CACHE BOOL "Build the tools.")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

# PLY_TEST -- Generate the tests
# PLY_TOOLS -- Build the tools
#
option(PLY_TEST "Generate the tests." OFF)
option(PLY_TOOLS "Build the tools." OFF)

message("-- cxx-ply: PLY_TEST ${PLY_TEST}")
message("-- cxx-ply: PLY_TOOLS ${PLY_TOOLS}")

# Add our dependencies
#
add_subdirectory(./extern/cxx-core)
add_dependencies(cxx_depends cxx_inja)

add_compile_options(-Wall)
add_compile_options(-std=c++2a)
add_compile_options(-fconcepts)
add_compile_options(-O3)

set(SOURCES
  generate.cpp
  )

foreach(NAME ${SOURCES})
  list(APPEND FILES "src/${NAME}")
endforeach()

add_library(cxx_ply ${FILES})
target_link_libraries(cxx_ply cxx_core)
target_include_directories(cxx_ply PUBLIC include)

if(PLY_TOOLS)
  set(TOOLS
    ply_t0
    )

  foreach(NAME ${TOOLS})
    add_executable(${NAME} src/tools/${NAME}.cpp)
    target_link_libraries(${NAME} cxx_ply)
  endforeach()
endif()

if(PLY_TEST)
  enable_testing()
  add_subdirectory(test)
endif()
