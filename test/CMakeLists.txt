cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

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

configure_tests("" "${LIBRARIES}" ${TESTS})
