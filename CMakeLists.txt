project(AddUserIspConfig)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_VERBOSE_MAKEFILE "OFF")
find_package(Boost REQUIRED COMPONENTS system thread program_options)

include_directories(src)
aux_source_directory(src SRC)
aux_source_directory(src/entity ENTITY)
aux_source_directory(src/repository REPOSITORY)
list(APPEND FULL_SRC
    ${SRC}
    ${ENTITY}
    ${REPOSITORY} )
if(MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHa")
else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -fnon-call-exceptions")
endif()

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${FULL_SRC})
target_link_libraries(${PROJECT_NAME} soci_core)


