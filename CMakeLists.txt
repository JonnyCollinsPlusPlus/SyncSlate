cmake_minimum_required(VERSION 3.23)
project(SyncSlate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_net CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

file(GLOB_RECURSE CLIENTSOURCES CONFIGURE_DEPENDS
    Application/SyncSlateClient/*.cpp
)
file(GLOB_RECURSE SHAREDSOURCES CONFIGURE_DEPENDS
    Application/Shared/*.cpp
)
file(GLOB_RECURSE SERVERSOURCES CONFIGURE_DEPENDS
    Application/SyncSlateServer/*.cpp
)

add_executable(SyncSlateClient ${CLIENTSOURCES} ${SHAREDSOURCES})

target_link_libraries(SyncSlateClient PRIVATE
    SDL3::SDL3
    $<IF:$<TARGET_EXISTS:SDL3_net::SDL3_net>,SDL3_net::SDL3_net,SDL3_net::SDL3_net-static>
    imgui::imgui
)

add_executable(SyncSlateServer ${SERVERSOURCES} ${SHAREDSOURCES})

target_link_libraries(SyncSlateServer PRIVATE
    SDL3::SDL3
    $<IF:$<TARGET_EXISTS:SDL3_net::SDL3_net>,SDL3_net::SDL3_net,SDL3_net::SDL3_net-static>
    imgui::imgui
)