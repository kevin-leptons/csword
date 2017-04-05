file(GLOB CSWORD_LIB_FILES lib/*.c)
# file(GLOB CSWORD_RES_FILES res/*)
file(GLOB CSWORD_EXE_FILES exe/*.c)

add_library(csword-slave SHARED ${CSWORD_LIB_FILES})
target_link_libraries(csword-slave archive)

add_executable(csword ${CSWORD_EXE_FILES})
target_link_libraries(csword csword-slave)
