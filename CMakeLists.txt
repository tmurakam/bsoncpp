cmake_minimum_required(VERSION 3.13)
project(bson)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(bsoncpp
        src/BsonElement.cpp
        src/BsonValue.cpp
        src/Bson.cpp
        src/BsonArray.cpp
        )

add_executable(sample sample/main.cpp)
target_link_libraries(sample bsoncpp)
