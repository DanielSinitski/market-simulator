# bench/CMakeLists.txt
add_executable(hello_bench hello_bench.cpp)

# Link against Google Benchmark and your engine (for the Stopwatch later)
target_link_libraries(hello_bench PRIVATE benchmark::benchmark engine)