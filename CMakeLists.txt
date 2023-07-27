CMAKE_MINIMUM_REQUIRED ( VERSION 3.2 )
SET(CMAKE_C_COMPILER /opt/homebrew/bin/aarch64-apple-darwin22-gcc-13)
SET(CMAKE_CXX_COMPILER /opt/homebrew/bin/aarch64-apple-darwin22-g++-13)
project(centor-of-mass)

set( TEST_DH_SRCS test/test_dh_parameter.c src/dh_parameter.c )
set( TEST_BODYSENSOR_SRCS test/test_body_sensor.c src/body_sensor.c)
set (TEST_COM_SRCS test/test_centor_of_mass.c src/centor_of_mass.c src/dh_parameter.c src/body_sensor.c)
set (TEST_BOS_SRCS test/test_base_of_support.c src/base_of_support.c src/body_sensor.c)
set (TEST_FK_SRCS test/test_forward_kinematics.c src/forward_kinematics.c src/dh_parameter.c src/body_sensor.c)
set ( OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/output )
file(MAKE_DIRECTORY ${OUTPUT_DIR})

ADD_COMPILE_OPTIONS ( -g -Wall )
MESSAGE ( ${CMAKE_PROJECT_NAME} )

INCLUDE_DIRECTORIES ( include )
ADD_EXECUTABLE( test_dh_parameter ${TEST_DH_SRCS} )
ADD_EXECUTABLE( test_body_sensor ${TEST_BODYSENSOR_SRCS} )
ADD_EXECUTABLE( test_centor_of_mass ${TEST_COM_SRCS} )
ADD_EXECUTABLE( test_base_of_support ${TEST_BOS_SRCS} )
ADD_EXECUTABLE( test_forward_kinematics ${TEST_FK_SRCS} )

set_target_properties(test_dh_parameter PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set_target_properties(test_body_sensor PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set_target_properties(test_centor_of_mass PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set_target_properties(test_base_of_support PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set_target_properties(test_forward_kinematics PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

