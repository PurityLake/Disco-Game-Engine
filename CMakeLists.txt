cmake_minimum_required(VERSION 3.12)

project(GameEngine)

set(PROJECT_NAME GameEngine)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Add source files
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.cpp)
	
# Add header files
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLFW3 REQUIRED)

set(LIBS ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} ${GLFW3_LIBRARY})

include_directories(
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/include"
)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${LIBS})