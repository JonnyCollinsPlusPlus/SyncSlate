cmake_minimum_required(VERSION 3.23)
project(SyncSlate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_net CONFIG REQUIRED)

add_executable(SyncSlateClient
    SyncSlateClient/SyncSlateClient.cpp
)

target_link_libraries(SyncSlateClient PRIVATE
    SDL3::SDL3
    $<IF:$<TARGET_EXISTS:SDL3_net::SDL3_net>,SDL3_net::SDL3_net,SDL3_net::SDL3_net-static>
)


add_executable(SyncSlateServer
    SyncSlateServer/SyncSlateServer.cpp
)

target_link_libraries(SyncSlateServer PRIVATE
    SDL3::SDL3
    $<IF:$<TARGET_EXISTS:SDL3_net::SDL3_net>,SDL3_net::SDL3_net,SDL3_net::SDL3_net-static>
)