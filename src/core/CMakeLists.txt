cmake_minimum_required(VERSION 3.27)
                
set(template-tui_include_dirs "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(template-tui_core templatetui.cpp
                            templatetui.hpp)

target_link_libraries(template-tui_core
  PRIVATE ostui::util
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
target_include_directories(template-tui_core
  PUBLIC ${template-tui_include_dirs}
)

add_library(ostui::core ALIAS template-tui_core)
