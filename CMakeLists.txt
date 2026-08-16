cmake_minimum_required(VERSION 3.23)
project(SyncSlate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_net CONFIG REQUIRED)

add_executable(main
    SyncSlateClient.cpp
)

target_link_libraries(main PRIVATE
    SDL3::SDL3
    $<IF:$<TARGET_EXISTS:SDL3_net::SDL3_net>,SDL3_net::SDL3_net,SDL3_net::SDL3_net-static>
)