cmake_minimum_required(VERSION 3.5)
project(bsoncpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(bsoncpp
        src/BsonElement.cpp
        src/Document.cpp
        src/BsonArray.cpp
        src/BsonUtils.cpp
        src/ObjectId.cpp include/BsonException.hpp)

add_executable(sample sample/main.cpp)
target_link_libraries(sample bsoncpp)
