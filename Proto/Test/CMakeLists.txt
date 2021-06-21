# Gameplay System Proto Tests.

add_executable(ProtoTest
    main.cpp
    GameplaySystemTest.cpp
    GameplaySystemTest.h
    FileTest.cpp
    FileTest.h
)

target_include_directories(ProtoTest
  PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    Proto
)

target_link_libraries(ProtoTest
  PUBLIC
    Proto
    GTest::gmock
    GTest::gtest
)