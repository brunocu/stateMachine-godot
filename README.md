# State Machine in Godot

![Version](https://img.shields.io/static/v1?label=version&message=1.0.0-alpha&color=yellow&style=flat-square)
[![Dependency](https://img.shields.io/static/v1?label=godot&message=3.2-stable&color=informational&style=flat-square)](https://github.com/godotengine/godot/releases/tag/3.2-stable)
[![Dependency](https://img.shields.io/static/v1?label=godot-cpp&message=3.2&color=informational&style=flat-square)](https://github.com/GodotNativeTools/godot-cpp/tree/3.2)

Simple state machine example using [Godot engine](https://godotengine.org/) with GDNative scripts using `godot-cpp` C++ bindings.

Exercise on class overloading and pointer to member function.

## State Machine

![Progress](https://img.shields.io/static/v1?label=progress&message=20%&color=red&style=flat-square)

The state machine will consist of multiple automaton which follow the diagram below.

![States](https://github.com/brunocu/stateMachine-godot/raw/master/diagram.png)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.


### Prerequisites

You must have a compiled version of the godot engine version `3.2-stable`.

### Setting up

It is recommended you download the project using git as seen below. Alternatively if you download the source code directly from github you also need to download [godot-cpp](https://github.com/GodotNativeTools/godot-cpp) and [godot_headers](https://github.com/GodotNativeTools/godot_headers).

```
git clone --recursive https://github.com/brunocu/stateMachine-godot.git
```

### Generating bindings

| **godot-cpp** | [GitHub](https://github.com/GodotNativeTools/godot-cpp) |
|---|---|

See the **godot-cpp** README for generating the C++ bindings.

## Building

### Windows

For building in windows the `VSBuild` folder is included. Make sure you have all C++ tools installed and open `VSBuild/VSBuild.sln`.

Build the project and `VSBuild.dll` will be generated inside `finiteGodot/bin/`.

### Linux

Make sure you have `Python 3.X` and [Scons](https://github.com/SCons/scons).

```
mkdir finiteGodot/bin/
scons p=linux
```
> Add `target=release` for a release build. You also need to build release bindings.

## Authors

Written by **Bruno Campos**.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

Big thanks to the godot community and the godot-cpp maintainers.