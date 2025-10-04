file(
    GLOB_RECURSE MODULES
    CONFIGURE_DEPENDS *.cppm
)

set(EXEC_NAME ${PROJECT_NAME})
set(LIB_NAME ${PROJECT_NAME}_lib)

add_library(${LIB_NAME} STATIC)
target_sources(${LIB_NAME} PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES ${MODULES})
target_link_libraries(${LIB_NAME} PRIVATE compiler_flags)

add_executable(${EXEC_NAME} main.cpp)
target_link_libraries(
    ${EXEC_NAME}
    PRIVATE
    ${LIB_NAME}
    compiler_flags
)
