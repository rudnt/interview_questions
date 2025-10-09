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
    ${PROJECT_NAME}_lib
    GTest::gtest_main
)

add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME})
