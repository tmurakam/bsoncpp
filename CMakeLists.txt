cmake_minimum_required(VERSION 3.13)
project(bsoncpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(bsoncpp
        src/BsonElement.cpp
        src/BsonValues.cpp
        src/Document.cpp
        src/BsonArray.cpp
        src/BsonUtils.cpp include/ObjectId.hpp src/ObjectId.cpp)

add_executable(sample sample/main.cpp)
target_link_libraries(sample bsoncpp)
