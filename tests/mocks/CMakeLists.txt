file(
    GLOB_RECURSE TEST_SOURCES
    CONFIGURE_DEPENDS *.cpp
)

set(LIB_NAME mocks_lib)

add_library(${LIB_NAME} ${TEST_SOURCES})
target_link_libraries( 
    ${LIB_NAME} 
    PRIVATE
    compiler_flags
    GTest::gtest
    ${PROJECT_NAME}_lib
)
target_include_directories(${LIB_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/tests)
