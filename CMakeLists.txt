cmake_minimum_required(VERSION 3.22.1)
project(GBEmulator C)
set(SOURCES 
    emulator/main.c 
    lib/cartridge.c 
    lib/registers.c 
    lib/cpu.c
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
find_package(SDL2 REQUIRED)
if (NOT SDL2_FOUND)
    message(FATAL_ERROR "SDL2 not found!")
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2)
