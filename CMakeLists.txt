cmake_minimum_required(VERSION 3.12)

project(function-filter VERSION 0.1 LANGUAGES CXX)

add_library(Utils SHARED
        include/function-filter/Info.hpp
        include/function-filter/Marker.hpp
        include/function-filter/Filter.hpp

        src/Info.cpp
        src/Marker.cpp
        src/Filter.cpp
        )
add_library(function-filter::Utils ALIAS Utils)

find_package(LLVM 7.0 REQUIRED CONFIG)
find_package(nlohmann_json REQUIRED)

target_include_directories(Utils
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${LLVM_INCLUDE_DIRS})

if ($ENV{CLION_IDE})
    include_directories("/usr/include/llvm-7.0/")
    include_directories("/usr/include/llvm-c-7.0/")
endif ()



target_compile_features(Utils PRIVATE cxx_std_17 cxx_range_for cxx_auto_type)
target_compile_options(Utils PRIVATE -fno-rtti)

##
## INSTALL
## install header files, generate and install cmake config files for find_package()
##
include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/function-filter)

install(
        TARGETS Utils
        EXPORT function-filter-targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
        DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
        EXPORT function-filter-targets
        NAMESPACE function-filter::
        DESTINATION ${INSTALL_CONFIGDIR}
)

##
## Config Version file
##
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/function-filterConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
        ${CMAKE_CURRENT_LIST_DIR}/cmake/function-filterConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/function-filterConfig.cmake
        INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/function-filterConfigVersion.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/function-filterConfig.cmake
        DESTINATION ${INSTALL_CONFIGDIR}
        )

##
## Export
##
export(
        EXPORT function-filter-targets
        NAMESPACE function-filter::
        FILE ${CMAKE_CURRENT_BINARY_DIR}/function-filterTargets.cmake
)

export(PACKAGE function-filter)