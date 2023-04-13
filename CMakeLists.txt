CMAKE_MINIMUM_REQUIRED ( VERSION 3.2 )
PROJECT (centor-of-mass)
set( TEST_DH_SRCS test/test_dh_parameter.c src/dh_parameter.c )
set( TEST_BODYSENSOR_SRCS test/test_body_sensor.c src/body_sensor.c)
set (TEST_COM_SRCS test/test_centor_of_mass.c src/centor_of_mass.c src/dh_parameter.c src/body_sensor.c)
set ( OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/output )

ADD_COMPILE_OPTIONS ( -g -Wall )
MESSAGE ( ${CMAKE_PROJECT_NAME} )

INCLUDE_DIRECTORIES ( include )
ADD_EXECUTABLE( test_dh_parameter ${TEST_DH_SRCS} )
ADD_EXECUTABLE( test_body_sensor ${TEST_BODYSENSOR_SRCS} )
ADD_EXECUTABLE( test_centor_of_mass ${TEST_COM_SRCS} )

set_target_properties(test_dh_parameter PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set_target_properties(test_body_sensor PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set_target_properties(test_centor_of_mass PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
