# Gameplay System Proto Tests.

add_executable(GameplaySystemProtoTest
    main.cpp
    GameplaySystemTest.cpp
    GameplaySystemTest.h
    FileTest.cpp
    FileTest.h
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