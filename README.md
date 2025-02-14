# Template-TUI
*A template project for FTXUI-based TUIs.*

<p align="center">
  <a href="#"><img src="https://img.shields.io/badge/c++-%2300599C.svg?style=flat&logo=c%2B%2B&logoColor=white"></img></a>
  <a href="https://opensource.org/license/gpl-3-0"><img src="https://img.shields.io/github/license/forgottosave/FTXUI_Template?color=black"></img></a>
  <a href="#"><img src="https://img.shields.io/github/stars/forgottosave/FTXUI_Template"></img></a>
  <a href="#"><img src="https://img.shields.io/github/forks/forgottosave/FTXUI_Template"></img></a>
  <a href="#"><img src="https://img.shields.io/github/repo-size/forgottosave/FTXUI_Template"></img></a>
  <a href="https://github.com/forgottosave/FTXUI_Template/graphs/contributors"><img src="https://img.shields.io/github/contributors/forgottosave/FTXUI_Template?color=blue"></img></a>
  <a href="https://github.com/forgottosave/FTXUI_Template/issues"><img src="https://img.shields.io/github/issues/forgottosave/FTXUI_Template"></img></a>
<br/>
  <a href="https://github.com/forgottosave/FTXUI_Template/issues/new">Report a Bug</a> ·
  <a href="https://github.com/forgottosave/FTXUI_Template/issues/new">Request a Feature</a> ·
  <a href="https://github.com/forgottosave/FTXUI_Template/fork">Fork the Repo</a> ·
  <a href="https://github.com/forgottosave/FTXUI_Template/compare">Submit a Pull Request</a>
</br>
</p>

-------------

## The Template

This repository is meant to serve as a template for FTXUI-based TUIs. It features:

* a complete CMake configuration
* a clear C++-style class hierarchy
* doxygen
* argument parsing 

## Build instructions

**"Normal" build:**

To build the Template-TUI on your system, just follow the default CMake workflow:
```bash
mkdir build
cd build
cmake ..
cmake --build . --parallel
# The binary will be located in `./bin/template-tui`.
# To install, use `make install DESTDIR=<target_destination>`
```

**Webassembly build:**

The Webassembly build requires [emscripten](https://github.com/emscripten-core/emsdk) to be installed!
```bash
mkdir build_emscripten && cd build_emscripten
emcmake cmake ..
make -j
./run_webassembly.py
(visit localhost:8000)
```
