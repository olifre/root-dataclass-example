[![CI and read test](https://github.com/olifre/root-dataclass-example/actions/workflows/test-compile-and-run.yml/badge.svg)](https://github.com/olifre/root-dataclass-example/actions/workflows/test-compile-and-run.yml)

# root-dataclass-example
An example of writing a custom class to a file and reading it back with autoloaded libraries.

## Purpose

This repository contains C++ code defining a simple custom data class `TestObj`, and a tool `write_test` writing out a file with the objects of this custom class. 

For compilation of the data class into a library, it uses the `CMake` macros provided by [ROOT](https://root.cern/) which generate dictionaries, PCMs and especially `rootmap` files. This allows the `root` tool to autoload the respective library containing the custom data class when reading back the file. 

The GitHub actions workflow illustrates how the pieces can work together.
