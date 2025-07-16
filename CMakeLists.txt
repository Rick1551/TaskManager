cmake_minimum_required(VERSION 3.20)  # Necesario para C++20
project(TaskManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Opciones para Visual Studio (Windows)
if (MSVC)
    add_compile_options(/W4 /WX)  # Máximo nivel de warnings y tratarlos como errores
endif()

# Archivos fuente
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# Ejecutable principal
add_executable(TaskManager ${SOURCES})

# Si usas librerías externas (ej: nlohmann/json para persistencia en JSON)
# find_package(nlohmann_json REQUIRED)
# target_link_libraries(TaskManager PRIVATE nlohmann_json::nlohmann_json)