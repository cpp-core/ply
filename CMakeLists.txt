cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(cxx-ply VERSION 0.1 LANGUAGES CXX)

# Configuration variables.
#
# MASTER_PROJECT - Is this the master project being built?
# PLY_TEST - Build the unit tests?
# PLY_TOOLS - Build the ply tools?
# PLY_CORE - Build the core subproject?
#
set(MASTER_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(MASTER_PROJECT ON)
endif()

set(PLY_CORE_DEFAULT ON)
if(TARGET core)
  set(PLY_CORE_DEFAULT OFF)
endif()

# Possibly override configuration from command line, e.g: -DPLY_TEST=0
#
option(PLY_TEST "Generate the tests." ${MASTER_PROJECT})
option(PLY_TOOLS "Build the tools." ${MASTER_PROJECT})
option(PLY_CORE "Build core subproject." ${PLY_CORE_DEFAULT})

message("cxx-ply: PLY_TEST ${PLY_TEST}")
message("cxx-ply: PLY_TOOLS ${PLY_TOOLS}")
message("cxx-ply: PLY_CORE ${PLY_CORE}")

if(PLY_CORE)
  add_subdirectory(./extern/cxx-core)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_compile_options(-Wall)
add_compile_options(-std=c++2a)
add_compile_options(-fconcepts)
add_compile_options(-O3)

set(SOURCES
  placeholder.cpp
  generate.cpp
  )

foreach(NAME ${SOURCES})
  list(APPEND FILES "src/${NAME}")
endforeach()

add_library(ply ${FILES})
target_link_libraries(ply core)
set_target_properties(ply PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
  )
target_include_directories(ply PUBLIC include)

if(PLY_TOOLS)
  set(TOOLS
    t0)

  foreach(NAME ${TOOLS})
    add_executable(${NAME} src/tools/${NAME}.cpp)
    target_link_libraries(${NAME} ply)
  endforeach()
endif()

if(PLY_TEST)
  include_directories(include)
  enable_testing()
  add_subdirectory(test)
endif()
