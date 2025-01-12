cmake_minimum_required(VERSION 3.10)

project(Graphics VERSION 0.1 LANGUAGES C)

add_library(${PROJECT_NAME} STATIC GLFW_standart_functions.c Transform.c Draw.c)

cmake_policy(SET CMP0072 NEW)

find_package(OpenGL)

if(NOT ${OpenGL_FOUND})
	message(SEND_ERROR "OpenGL not found")
endif()

find_library(GLFW_LIB NAMES glfw)

if(NOT GLFW_LIB)
	message(SEND_ERROR "can't find glfw library")
endif()

target_link_libraries(${PROJECT_NAME} OpenGL::GL)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Headers)

add_custom_command(
	TARGET ${PROJECT_NAME} 
	POST_BUILD
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND}
	ARGS -E copy_directory "${CMAKE_SOURCE_DIR}/Headers/Graphics" "${CMAKE_BINARY_DIR}/lib/Graphics"
  	COMMENT "Copying Bundle Stuff"
)

