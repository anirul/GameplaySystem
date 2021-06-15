# Proto directory

add_library(GameplaySystemProto
  STATIC
    GameplaySystem.proto
    File.proto
    Proto.h
)

target_include_directories(GameplaySystemProto
  PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

protobuf_generate(APPEND_PATH TARGET GameplaySystemProto)

target_link_libraries(GameplaySystemProto
  PUBLIC
    protobuf::libprotoc
    protobuf::libprotobuf
)

add_subdirectory(Test)
