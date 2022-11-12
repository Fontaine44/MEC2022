# Pre CQI 2023 - Debugging - 10 pts

## Context
The debugging challenge is used to evaluate your competencies to debug an existing application. You will have to debug a karaoke app.

## Required Software
* Your system may run any operating system you like. However we suggest **Linux**. Either way, you will need the following programs:
  * A c++ compiler, for example: **gcc**, **clang**, **MSCV (Visual Studio)**
  * **cmake**

## Delivery
You must deliver an archive containing the files in `debug/`

## Instructions

* You must fix the code located in `src` to make it compile and pass the tests
* The `CMakeLists.txt` file do not contain any errors and must not be modified.
* The tests located in `tests/` do not contain any errors and must not be modified. All compilation errors and test errors must be fixed by modifying the code in `sec/`

## Compiling and running tests

### Compilation
```shell script
mkdir build
cd build
cmake ..
cmake --build .
```

### Running the tests
```shell script
# In the build directory
./test/karaoke_test
```
