file(GLOB SHIELD_LIB_FILES lib/*.c)
file(GLOB SHIELD_EXE_FILES exe/*.c)

add_library(shield-slave SHARED ${SHIELD_LIB_FILES})

add_executable(shield ${SHIELD_EXE_FILES})
target_link_libraries(shield shield-slave)
