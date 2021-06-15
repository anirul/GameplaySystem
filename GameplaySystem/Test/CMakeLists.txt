# Gameplay System Proto Tests.

add_executable(GameplaySystemProtoTest
    main.cpp
)

target_include_directories(GameplaySystemProtoTest
  PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    GameplaySystemProto
)

target_link_libraries(GameplaySystemProtoTest
  PUBLIC
    GameplaySystemProto
    GTest::gmock
    GTest::gtest
)