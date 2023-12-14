cmake_minimum_required(VERSION 3.27)
project(MiniBlock)

set(CMAKE_CXX_STANDARD 17)

add_executable(MiniBlock src/main.cpp
        src/Game.cpp
        headers/Game.h
        src/block/Block.cpp
        headers/block/Block.h
        src/chunk/Chunk.cpp
        headers/chunk/Chunk.h
        src/texture/TextureAtlas.cpp
        headers/texture/TextureAtlas.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:\\SFML\\lib\\cmake\\SFML")
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(${SFML_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/headers)
target_link_libraries(MiniBlock sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
