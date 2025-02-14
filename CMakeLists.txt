cmake_minimum_required(VERSION 3.27)

# Project _____________________________________________________
set(PROJECT_NAME "template-tui")
set(PROJECT_DESCRIPTION "Template for FTXUI-based TUIs.")
set(PROJECT_HOMEPAGE_URL "https://github.com/forgottosave/FTXUI_Template")

project("${PROJECT_NAME}"
  DESCRIPTION "${PROJECT_DESCRIPTION}"
  HOMEPAGE_URL "${PROJECT_HOMEPAGE_URL}"
  LANGUAGES CXX
  VERSION 1.0.0
)

# C++ Standard ________________________________________________
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler Options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror=format-security -pipe -Wconversion")

# Fetch FTXUI _________________________________________________

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG main
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# Project _____________________________________________________
add_subdirectory(src)
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

# Emscripten __________________________________________________
if (EMSCRIPTEN) 
  string(APPEND CMAKE_CXX_FLAGS " -s USE_PTHREADS")
  string(APPEND CMAKE_EXE_LINKER_FLAGS " -s ASYNCIFY")
  string(APPEND CMAKE_EXE_LINKER_FLAGS " -s PROXY_TO_PTHREAD")

  foreach(file "index.html" "run_webassembly.py")
    configure_file("src/${file}" ${file})
  endforeach(file)
endif() 
