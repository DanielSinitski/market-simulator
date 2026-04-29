# presets.cmake

# Standard build types
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -DNDEBUG")

# ASan + UBSan Preset (For active development)
# -fno-omit-frame-pointer is added to get proper stack traces when a bug is found
set(CMAKE_CXX_FLAGS_SANITIZE "-O1 -g -fsanitize=address,undefined -fno-omit-frame-pointer")
set(CMAKE_EXE_LINKER_FLAGS_SANITIZE "-fsanitize=address,undefined")

# TSan Preset (For running tests)
set(CMAKE_CXX_FLAGS_TSAN "-O1 -g -fsanitize=thread -fno-omit-frame-pointer")
set(CMAKE_EXE_LINKER_FLAGS_TSAN "-fsanitize=thread")