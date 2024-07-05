cmake_minimum_required(VERSION 3.18)
project(Aegis CXX)

set(CMAKE_CXX_STANDARD 20)
add_executable(aegis)

add_subdirectory(source)
add_subdirectory(src)

find_package(PkgConfig)
pkg_check_modules(Gtk gtkmm-4.0 REQUIRED)
pkg_check_modules(Adwaita libadwaita-1 REQUIRED)

target_include_directories(aegis PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:>
)

target_link_libraries(aegis PRIVATE source ${Gtk_LINK_LIBRARIES} ${Adwaita_LINK_LIBRARIES})
target_include_directories(aegis PRIVATE source ${Gtk_INCLUDE_DIRS} ${Adwaita_INCLUDE_DIRS})
