# OpenCV — C++ Exercises

This repository contains personal OpenCV exercises written in C++.

## Overview

Small C++ programs demonstrating common computer-vision techniques using OpenCV and CMake for builds.

## Prerequisites (macOS)

- Homebrew
- A modern C++ compiler (`clang++` or `g++`) supporting C++17
- `cmake` and `pkg-config`
- OpenCV 4.x (install via Homebrew):

```bash
brew install opencv cmake pkg-config
```

Make sure Homebrew's OpenCV is discoverable by CMake (Homebrew typically links OpenCV to `/usr/local` or `/opt/homebrew`).

## Build with CMake

1. From the repository root create and enter a build directory:

```bash
mkdir -p build && cd build
cmake ..
cmake --build . --config Release
```

2. To run the example:

```bash
./example path/to/image.jpg
```

## Minimal `CMakeLists.txt`

Use this `CMakeLists.txt` at the repository root to build `example.cpp`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(opencv_exercises LANGUAGES CXX)
find_package(OpenCV REQUIRED)
add_executable(example example.cpp)
target_compile_features(example PRIVATE cxx_std_17)
target_link_libraries(example PRIVATE ${OpenCV_LIBS})
```

## Quick compile (no CMake)

Compile directly using `pkg-config`:

```bash
clang++ -std=c++17 `pkg-config --cflags opencv4` example.cpp -o example `pkg-config --libs opencv4`
./example path/to/image.jpg
```

## Example usage

- `example.cpp` loads an image, converts it to grayscale, shows it, and writes `output.png` in the current directory.

## Repository layout

- `example.cpp` — minimal C++ exercise program
- `CMakeLists.txt` — build file
- `data/` — add images here for exercises (optional)

## Next steps

Tell me if you want additional examples (filters, edge detection, feature matching), a CI workflow, or automated build scripts.
