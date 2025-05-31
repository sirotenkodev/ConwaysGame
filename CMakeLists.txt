#Убедитесь, что верси 3.5 и выше, если 4.0 то cmake считает что версия ниже, тк проверяет только после .
# на alt-linux у меня из apt встала 3.31 и все ок, а в windows не заметил и поставил 4.0 и долго думал почему
cmake_minimum_required(VERSION 3.24)
project(ConwaysGame)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)
set(BOOST_INCLUDE_LIBRARIES program_options)
set(BOOST_ENABLE_CMAKE ON)
# Конечно лучше conan или vcpkg, но не у всех стоят а это встроенная cmake
FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.26.3
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)

FetchContent_Declare(
    Boost
    GIT_REPOSITORY https://github.com/boostorg/boost.git
    GIT_TAG boost-1.80.0
)

FetchContent_MakeAvailable(SDL2 Boost)

set(SOURCE_HEADERS
    application.h
    cell.h
    gamerender.h
    gamewindow.h
    grid.h
)

set(SOURCE_SOURCES
    application.cpp
    cell.cpp
    gamerender.cpp
    gamewindow.cpp
    grid.cpp
    main.cpp
)


add_executable(${PROJECT_NAME} ${SOURCE_HEADERS} ${SOURCE_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2-static Boost::program_options)
