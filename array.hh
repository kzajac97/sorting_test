#pragma once

#include <iostream>
#include <fstream>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
#include <iostream>

//pseudo random number generator seed
static const unsigned seed_t = std::chrono::system_clock::now().time_since_epoch().count();

template <typename type_t>
void print(std::vector<type_t> array);
template <typename type_t>
const bool isSorted(std::vector<type_t> array);
template <typename type_t>
void randomArrayGenerator(std::vector<type_t> &array, int size, float sorted);
//reverts elements in vector
template <typename type_t>
void revert(std::vector<type_t> &array);
//fills vector with increasing ints
template <typename type_t>
inline void arrayGenerator(std::vector<type_t> &array, int size);
//randomly shuffles array values
template <typename type_t>
inline void arrayShuffle(std::vector<type_t> &array, float sorted) { std::random_shuffle(array.begin()+(int)sorted*array.size(),array.end()); }
//average of values in an array
template <typename type_t>
inline double average(std::vector<type_t> array) { return (std::accumulate(array.begin(),array.end(),0.0f))/(array.size()); }