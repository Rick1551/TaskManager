cmake_minimum_required(VERSION 3.20)
project(TaskManager LANGUAGES CXX)

# Configuraci�n del est�ndar C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Opciones para Visual Studio
if(MSVC)
    add_compile_options(/W4 /WX)
endif()

# Lista expl�cita de archivos fuente (mejor pr�ctica que file(GLOB))
set(SOURCES
    src/main.cpp
    src/Task.cpp
    src/TaskManager.cpp
)

# Crear el ejecutable usando la variable SOURCES
add_executable(TaskManager ${SOURCES})

# Configurar los includes DESPU�S de crear el ejecutable
target_include_directories(TaskManager PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Opcional: Configurar propiedades adicionales
# target_compile_definitions(TaskManager PRIVATE SOME_DEFINITION)
# target_link_libraries(TaskManager PRIVATE some_library)