include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG 2db1cf3
)
FetchContent_MakeAvailable(Catch2)

add_executable(Tests tests.cpp)

target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)