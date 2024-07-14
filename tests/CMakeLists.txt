cmake_minimum_required(VERSION 3.28)

project(stipp)

include(FetchContent)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "")
option(STIPP_UB_TRAITS "Enable testing of type traits that may have undefined behavior" OFF)

FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0
)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(CTest)
include(Catch)
enable_testing()

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_compile_features(tests PRIVATE cxx_std_20)
target_include_directories(tests PRIVATE "${PROJECT_SOURCE_DIR}/..")
if(STIPP_UB_TRAITS)
    target_compile_definitions(tests PRIVATE -DSTIPP_UB_TRAITS)
endif()

catch_discover_tests(tests)
