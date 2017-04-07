	file(GLOB CSWORD_LIB_FILES lib/*.c)
file(GLOB CSWORD_EXE_FILES exe/*.c)

add_library(csword-slave SHARED ${CSWORD_LIB_FILES})
target_link_libraries(csword-slave archive)

add_executable(csword ${CSWORD_EXE_FILES})
target_link_libraries(csword csword-slave)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})
