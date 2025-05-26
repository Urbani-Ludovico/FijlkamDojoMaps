cmake_minimum_required(VERSION 3.30)

set(CMAKE_C_STANDARD 23)

set(COMPILE_OPTIONS -Wall -Wextra -Wpedantic -Werror)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)
pkg_search_module(CURL REQUIRED libcurl)
pkg_search_module(LIBXML2 REQUIRED libxml-2.0)
pkg_search_module(CJSON REQUIRED libcjson)

project(DojoMaps_GetData C)
add_executable(DojoMaps_GetData
    get_data/src/main.c
    get_data/src/options.c
    get_data/include/options.h
    get_data/src/driver.c
    get_data/include/driver.h
)

target_link_libraries(DojoMaps_GetData PRIVATE
    ${GLIB_LIBRARIES}
    ${CURL_LIBRARIES}
    ${LIBXML2_LIBRARIES}
    ${CJSON_LIBRARIES}
)
target_include_directories(DojoMaps_GetData PRIVATE
    get_data/include
    ${GLIB_INCLUDE_DIRS}
    ${CURL_INCLUDE_DIRS}
    ${LIBXML2_INCLUDE_DIRS}
    ${CJSON_INCLUDE_DIRS}
)
target_compile_options(DojoMaps_GetData PRIVATE
    ${GLIB_CFLAGS_OTHER}
    ${CURL_CFLAGS_OTHER}
    ${LIBXML2_CFLAGS_OTHER}
    ${CJSON_CFLAGS_OTHER}
)

target_compile_options(DojoMaps_GetData PRIVATE ${COMPILE_OPTIONS})