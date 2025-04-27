cmake_minimum_required(VERSION 3.15)
project(BlinkLedSim C)

# ustawiamy, żeby CMake szukał pakietów w katalogu MSYS2-Mingw64
# (zmodyfikuj, jeśli masz SDL2 w innym miejscu)
set(CMAKE_PREFIX_PATH "C:/msys64/mingw64")

# wymagana biblioteka SDL2
find_package(SDL2 REQUIRED)

# jeśli CMake jej nie znalazł, możesz dopisać ścieżki ręcznie:
# if (NOT SDL2_FOUND)
#   message(STATUS "SDL2 not found by find_package, falling back to manual paths")
#   set(SDL2_INCLUDE_DIRS "C:/msys64/mingw64/include/SDL2")
#   set(SDL2_LIBRARIES
#       "C:/msys64/mingw64/lib/libSDL2main.a"
#       "C:/msys64/mingw64/lib/libSDL2.dll.a"
#   )
#   set(SDL2_FOUND TRUE)
# endif()

if (SDL2_FOUND)
  message(STATUS "SDL2 include: ${SDL2_INCLUDE_DIRS}")
  message(STATUS "SDL2 libs: ${SDL2_LIBRARIES}")
else()
  message(FATAL_ERROR "SDL2 not found!")
endif()



# Dodaj katalog z nagłówkami
include_directories(${SDL2_INCLUDE_DIRS})

# wszystkie pliki źródłowe
file(GLOB SRC 
  "${PROJECT_SOURCE_DIR}/src/*.c"
)

# definiujemy wykonwyalny
add_executable(${PROJECT_NAME} ${SRC})

# linkujemy SDL2
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

# żeby przy uruchamianiu w IDE SDL2.dll była obok .exe
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_PREFIX_PATH}/bin/SDL2.dll"
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
