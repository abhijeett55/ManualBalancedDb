#ifndef BECNHMARK_HPP
#define BECNHMARK_HPP

#include <chrono>


inline auto now() {
    return std::chrono::high_resolution_clock::now();
}


inline double time_diff( const std::chrono::high_resolution_clock::time_points& end, const std::chrono::high_resolution_clock::time_points& start) {
    return std::chrono::duration<double>(end - start).count();
}