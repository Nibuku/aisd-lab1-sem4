cmake_minimum_required(VERSION 3.11)

project(bintree CXX)

set(CMAKE_CXX_STANDARD 23)

# Специфичные настройки для компилятора Visual Studio
if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Объявляем библиотеку
add_library(bintree SHARED "include/bintree/bintree.h" "src/bintree.cc" )
target_include_directories(bintree PUBLIC "include")

# Подключаем googletest
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Объявляем тесты
add_executable(bintree_tests "tests/bintree_tests.cc")
target_link_libraries(bintree_tests bintree GTest::gtest_main)
add_executable(task "src/task.cc")
add_executable(stats "src/stats.cc")
target_link_libraries(task bintree)
target_link_libraries(stats bintree)

