# Proto directory

add_library(Proto
  STATIC
    GameplaySystem.proto
    File.proto
    Proto.h
)

target_include_directories(Proto
  PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

protobuf_generate(APPEND_PATH TARGET Proto)

target_link_libraries(Proto
  PUBLIC
    protobuf::libprotoc
    protobuf::libprotobuf
)

add_subdirectory(Test)
