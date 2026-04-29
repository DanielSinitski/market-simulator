#include <benchmark/benchmark.h>
#include <vector>
// Benchmark std::vector push_back
static void BM_VectorPushBack(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> v;
        v.reserve(state.range(0));
        for (int i = 0; i < state.range(0); ++i) {
            v.push_back(i);
        }
        benchmark::DoNotOptimize(v.data()); // Prevent compiler from optimizing the loop away
    }
}
BENCHMARK(BM_VectorPushBack)->Range(8, 8<<10);

// Benchmark raw array writes (baseline)
static void BM_RawArrayWrite(benchmark::State& state) {
    for (auto _ : state) {
        int* arr = new int[state.range(0)];
        for (int i = 0; i < state.range(0); ++i) {
            arr[i] = i;
        }
        benchmark::DoNotOptimize(arr);
        delete[] arr;
    }
}
BENCHMARK(BM_RawArrayWrite)->Range(8, 8<<10);

BENCHMARK_MAIN();