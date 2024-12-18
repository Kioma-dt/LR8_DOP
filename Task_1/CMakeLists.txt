cmake_minimum_required(VERSION 3.28)
project("MyProject")
set(CMAKE_CXX_STANDART 20)
#set(CMAKE_CXX_CPPLINT "cpplint")

option (ENABLE_ASAN "Enable AddressSantitizer" OFF)
option (ENABLE_TSAN "Enable ThreadSanitizer" OFF)
option (ENABLE_LSAN "Enable LekaSanitizer" OFF)
set(SANITIZE_FLAGS "")
set(SANITIZE_LINK_FLAGS "")


if (ENABLE_ASAN)
    set(SANITIZE_FLAGS "-fsanitize=address")
    set(SANITIZE_LINK_FLAGS  "-fsanitize=address")

endif()

if (ENABLE_TSAN)
    set(SANITIZE_FLAGS "-fsanitize=thread")
    set(SANITIZE_LINK_FLAGS "-fsanitize=thread")

endif()

if (ENABLE_LSAN)
    set(SANITIZE_FLAGS "-fsanitize=leak")
    set(SANITIZE_LINK_FLAGS "-fsanitize=leak")

endif()

if (SANITIZE_FLAGS)
    add_compile_options(${SANITIZE_FLAGS})
    add_link_options(${SANITIZE_LINK_FLAGS})
endif()


add_executable(main main.cpp Functions.cpp Functions.h Struct.h)

