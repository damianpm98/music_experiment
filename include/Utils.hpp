#ifndef UTILS_HPP
#define UTILS_HPP
#pragma once

#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <thread>

template <typename T>
bool checkIfExistsInList(const std::list<T> &lst, const T &element) {
    if (std::find(lst.begin(), lst.end(), element) != lst.end()) {
        return true;
    } else {
        return false;
    }
}

inline void printMessage(const std::string &message) {
    std::cout << message << std::endl;
}

inline auto timeNow() { return std::chrono::high_resolution_clock::now(); }
inline auto timeDiffInMilliseconds(
    const std::chrono::high_resolution_clock::time_point &start,
    const std::chrono::high_resolution_clock::time_point &end) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
        .count();
}
inline void
sleepUntil(const std::chrono::high_resolution_clock::time_point &timePoint) {
    std::this_thread::sleep_until(timePoint);
}
inline void sleepForMilliseconds(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

#endif // UTILS_HPP
