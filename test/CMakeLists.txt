cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

find_package(googletest REQUIRED)

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

foreach(NAME ${TESTS})
  get_filename_component(DIRNAME ${NAME} DIRECTORY)
  get_filename_component(BASENAME ${NAME} NAME_WE)
  string(REPLACE / _ CATNAME ${NAME})
  
  set(TEST_NAME test_${CATNAME})
  set(TEST_FILE ${PROJECT_SOURCE_DIR}/test/src/${DIRNAME}/test_${BASENAME}.cpp)
  if(EXISTS ${TEST_FILE})
  else()
    set(TEST_FILE ${PROJECT_SOURCE_DIR}/test/src/${DIRNAME}/test_${CATNAME}.cpp)    
  endif()
  
  add_executable(${TEST_NAME} EXCLUDE_FROM_ALL ${TEST_FILE})
  add_test(${TEST_NAME} bin/${TEST_NAME})
  target_link_libraries(${TEST_NAME} cxx_ply "${LIBRARIES}" googletest::cxx-googletest)

  add_dependencies(check ${TEST_NAME})
  add_dependencies(check_detail ${TEST_NAME})
endforeach(NAME)
