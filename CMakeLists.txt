cmake_minimum_required(VERSION 3.12)

project(store-client VERSION 1.0 LANGUAGES CXX)



add_subdirectory(deps/store-library)

add_executable(client)

target_sources(client
    PRIVATE
    main.cpp
)

target_link_libraries(client
    PRIVATE
    store
)
