#ifndef UTILS_HPP
#define UTILS_HPP
#pragma once

#include <algorithm>
#include <iostream>
#include <list>

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

#endif // UTILS_HPP
