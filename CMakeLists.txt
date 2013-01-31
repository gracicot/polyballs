cmake_minimum_required(VERSION 2.8)

set(EXECUTABLE_NAME "polyballs")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

project(${EXECUTABLE_NAME})
add_definitions("-std=c++0x")

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_executable(${EXECUTABLE_NAME} ${SRC_FILES})

find_package(SFML 1.6 REQUIRED system window graphics network audio)
find_package(SUBGINE REQUIRED system physic collision)
find_package(OpenGL REQUIRED)

target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES} ${SFML_LIBRARIES} ${SUBGINE_LIBRARIES})

install(TARGETS ${EXECUTABLE_NAME} RUNTIME DESTINATION bin)
