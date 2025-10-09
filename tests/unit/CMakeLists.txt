file(
    GLOB_RECURSE TEST_SOURCES
    CONFIGURE_DEPENDS *.cpp
)

set(EXEC_NAME unit_tests)

add_executable(${EXEC_NAME} ${TEST_SOURCES})
target_link_libraries( 
    ${EXEC_NAME} 
    PRIVATE
    compiler_flags
    GTest::gtest_main
    ${PROJECT_NAME}_lib
    fixtures_lib
)
target_include_directories(${EXEC_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/tests)

add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME})
