file(
    GLOB_RECURSE TEST_SOURCES
    CONFIGURE_DEPENDS *.cpp
)

set(EXEC_NAME unit)
set(LIB_NAME ${PROJECT_NAME}_lib)
set(COMPILE_OPTIONS -fmodules -Wall -Wextra -Wpedantic -Werror)

add_executable(${EXEC_NAME} ${TEST_SOURCES})
target_compile_options(${EXEC_NAME} PRIVATE ${COMPILE_OPTIONS})

target_link_libraries(
    ${EXEC_NAME}
    PRIVATE
    ${LIB_NAME}
    GTest::gtest_main
)

add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME})
