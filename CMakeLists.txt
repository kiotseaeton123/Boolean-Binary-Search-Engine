cmake_minimum_required(VERSION 3.20)
project(21f_final_proj_template)
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(Tests)

#portion included for rapidJSON
Include(FetchContent)

FetchContent_Declare(
        rapidjson
        GIT_REPOSITORY https://github.com/Tencent/rapidjson.git
        GIT_TAG 0d4517f
)

FetchContent_MakeAvailable(rapidjson)
add_library(rapidjson INTERFACE)
target_include_directories(rapidjson INTERFACE ${rapidjson_SOURCE_DIR})

add_executable(21f_final_proj_template main.cpp AVLTree.h porter2_stemmer.cpp porter2_stemmer.h UserInterface.cpp UserInterface.h SearchEngine.cpp SearchEngine.h IndexHandler.cpp IndexHandler.h DocumentParser.cpp DocumentParser.h Document.cpp Document.h)

target_link_libraries(21f_final_proj_template PRIVATE rapidjson)


