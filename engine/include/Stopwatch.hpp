#pragma once
#include <x86intrin.h>
#include <cstdint>

class Stopwatch {
public:
    inline void start() {
        _mm_lfence(); // Prevent instruction reordering
        start_cycles = __rdtsc();
        _mm_lfence();
    }

    inline uint64_t elapsed() const {
        _mm_lfence();
        uint64_t end_cycles = __rdtsc();
        _mm_lfence();
        return end_cycles - start_cycles;
    }

private:
    uint64_t start_cycles = 0;
};