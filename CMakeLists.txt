cmake_minimum_required(VERSION 3.30)

set(CMAKE_C_STANDARD 23)

set(COMPILE_OPTIONS -Wall -Wextra -Wpedantic -Werror)


project(DojoMaps_GetData C)
add_executable(DojoMaps_GetData
    get_data/main.c
)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(DojoMaps_GetData ${CURL_LIBRARIES})

find_package(LibXml2 REQUIRED)
include_directories(${LIBXML2_INCLUDE_DIR})
target_link_libraries(DojoMaps_GetData ${LIBXML2_LIBRARIES})

find_package(cJSON REQUIRED)
include_directories(${LIBCJSON_INCLUDE_DIR})
target_link_libraries(DojoMaps_GetData cjson)

target_compile_options(DojoMaps_GetData PRIVATE ${COMPILE_OPTIONS})