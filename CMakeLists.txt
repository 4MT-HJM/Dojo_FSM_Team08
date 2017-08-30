PROJECT(FSM)

cmake_minimum_required(VERSION 2.6)


set(CMAKE_CXX_FLAGS "-std=c++14")


include_directories("inc")

add_library(FSMModule EXCLUDE_FROM_ALL SHARED src/FSM.cc)

if(EXISTS "${PROJECT_SOURCE_DIR}/googletest/googlemock")
	include_directories("googletest/googletest/include")
	include_directories("googletest/googlemock/include")
	include_directories("googletest/googletest")
	include_directories("googletest/googlemock")
	include_directories("test")
	add_library(gtestgmock googletest/googletest/src/gtest-all.cc googletest/googlemock/src/gmock-all.cc)

	add_executable(FSMTest test/mainTest.cpp test/FSMTest.cc)
	target_link_libraries(FSMTest FSMModule gtestgmock pthread)
endif()
