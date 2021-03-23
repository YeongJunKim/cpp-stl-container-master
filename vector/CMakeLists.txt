cmake_minimum_required(VERSION 3.5)

project(train_vector)



include_directories(../commonLib)

# add_library(COMMON_LIB
#     ./../commonLib/Hardware
#     ./../commonLib/Motor
#     ./../commonLib/Pid
#     ./../commonLib/TypeDef
# )

set(SOURCES_TRAIN_VECTOR
    main.cpp
    ./../commonLib/Hardware.cpp
    ./../commonLib/PacketHandler.cpp
)

add_executable(train_vector ${SOURCES_TRAIN_VECTOR})
# target_link_libraries(train_vector COMMON_LIB)