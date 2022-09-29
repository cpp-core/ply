cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

cpp_core_find_package(GTest
  URL https://github.com/cpp-core/googletest
  VERSION v1.12.0
  EXCLUDE_FROM_ALL
  )
find_package(Threads REQUIRED)

set(TESTS
  color
  contour
  enum
  generate
  heatmap
  layout
  line
  margin
  marker
  ohlc
  pad
  range_slider
  scatter
  scatter3d
  scene
  title
  xaxis
  yaxis
  zaxis
  )

set(LIBRARIES
  ply
  GTest::gtest
  Threads::Threads
  )

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/configure_tests.cmake)
configure_tests("" "${LIBRARIES}" ${TESTS})
