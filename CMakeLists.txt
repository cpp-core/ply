cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(ply VERSION 0.1 LANGUAGES CXX)

# Make including this file idempotent
#
if (TARGET ply)
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
  set(CMAKE_DOCS_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/docs)
  
  # Have cmake output the compilation commands
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

# PLY_TEST -- Generate the tests
# PLY_TOOLS -- Build the tools
#
option(PLY_TEST "Generate the tests." OFF)
option(PLY_TOOLS "Build the tools." ON)

message("-- ply: PLY_TEST ${PLY_TEST}")
message("-- ply: PLY_TOOLS ${PLY_TOOLS}")
message("-- ply: CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

# Add our dependencies
#
find_package(mp REQUIRED)
find_package(string REQUIRED)
find_package(util REQUIRED)
find_package(inja REQUIRED)

message("-- ply: using mp: ${mp_DIR}")
message("-- ply: using string: ${string_DIR}")
message("-- ply: using util: ${util_DIR}")
message("-- ply: using inja: ${inja_DIR}")

# Configuration
#
# The config.h contains the base location of the shared artifacts
# which is different for build versus install. We configure the file
# once for each. The install version is later copied to the final
# destination by the install cmake.
#
set(PLY_SHARE_DIR ${PROJECT_SOURCE_DIR}/share)
configure_file(config/config.h.in include/ply/config.h @ONLY)

set(PLY_SHARE_DIR ${CMAKE_INSTALL_PREFIX}/share)
configure_file(config/config.h.in forinstall/config.h @ONLY)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
add_compile_options(-O)
add_compile_options(-stdlib=libc++)
add_link_options(-stdlib=libc++)

set(SOURCES
  ply/generate.cpp
  )

foreach(NAME ${SOURCES})
  list(APPEND FILES "src/${NAME}")
endforeach()

add_library(ply ${FILES})

set(LIBRARIES
  mp::mp
  util::util)

set(PRIVATE_LIBRARIES
  string::string
  pantor::inja)

target_link_libraries(ply
  PUBLIC ${LIBRARIES}
  PRIVATE ${PRIVATE_LIBRARIES})

target_include_directories(ply PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
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
  enable_testing()
  if (NOT TARGET check)
    add_custom_target(check ${CMAKE_CTEST_COMMAND})
    add_custom_target(check_detail ${CMAKE_CTEST_COMMAND} -V)
  endif()
  add_subdirectory(test)
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/install_config.cmake)
install_config(ply)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/ply/config.h DESTINATION include/ply)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ply DESTINATION include)
install(FILES ${PROJECT_BINARY_DIR}/forinstall/config.h DESTINATION include/ply)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/share DESTINATION .)
