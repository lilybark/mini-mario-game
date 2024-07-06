# Windows
Todo :D

# Linux
A build in a linux-based distribution should follow a straightforward build using a CMake environment. Open a terminal and run these commands:

```shell
mkdir build
cd build
cmake ..
cmake --build .
```

Note: some distros don't have `libegl1-mesa-dev` installed. This will trigger an error with CMake's automatic OpenGL package finder. Fix this by installing

Some other errors that may occur:

- "wayland-scanner" not found: install `libwayland-dev`
- Could NOT find PkgConfig: install `pkg-config`
- Package 'xkbcommon', required by 'virtual:world', not found: install `libxkbcommon-dev`
- Here are some easy-to-find packages to install: `libxrandr-dev`, `libxinerama`, `libxcursor`, `libxi`

If any other packages need to be installed, let us know via an issue on GitHub.