
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(ZeekPluginNetmap)

include(ZeekPlugin)

zeek_plugin_begin(Zeek Netmap)
zeek_plugin_cc(src/Plugin.cc)
zeek_plugin_cc(src/Netmap.cc)
zeek_plugin_dist_files(README CHANGES COPYING VERSION zeekctl/netmap.py)
zeek_plugin_end()

file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" VERSION LIMIT_COUNT 1)

if ("${PROJECT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
    # Allows building rpm/deb packages via "make package" in build dir.
    include(ConfigurePackaging)
    ConfigurePackaging(${VERSION})
endif ()
