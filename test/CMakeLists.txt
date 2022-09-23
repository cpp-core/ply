cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

find_package(GTest REQUIRED)
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
  string::string
  GTest::gtest
  Threads::Threads
  )

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/configure_tests.cmake)
configure_tests("" "${LIBRARIES}" ${TESTS})
