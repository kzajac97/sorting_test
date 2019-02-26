#pragma once

#include <cstddef>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

//macro for checking array size
#define array_size(array) sizeof(array)/sizeof(*array)

//hybrid sort paramter sub-arrays smaller than parameter 
//are sorted by insertion sort 
static const int introSortConstant = 9; 

//splits array so every element is part one is smaller
//than any element in part two function
template <typename type_t>
int split(std::vector<type_t> &array, int first, int last);
//merges arrays sorting elements
template <typename type_t>
void merge(std::vector<type_t> &array, int first, int middle, int last);
//recursively splits array into one-element arrays
template<typename type_t>
void mergesort(std::vector<type_t> &array, int first, int last);
//recursively sorts splited arrays
template <typename type_t>
void quicksort(std::vector<type_t> &array, int first, int last);
template <typename type_t>
void insertionsort(std::vector<type_t> &array,int first, int last);
//functions return left and right indexes of an array based heap
//indexing starts from 0
inline unsigned int getLeftIndex(unsigned int index) { return 2*index + 1; }
inline unsigned int getRightIndex(unsigned int index) { return 2*index + 2; }
template <typename type_t>
void heapsort(std::vector<type_t> &array, int first, int last);
//builds heap from an array
template <typename type_t>
void buildHeap(std::vector<type_t> &array, int first, int last);
//corrects a single violation of the heap property 
//in a subtree and it's root
template <typename type_t>
void heapify(std::vector<type_t> &array, int first, int last, int index);
//quicksort function with additinal argument preventing it from going
//to worst case scenario O(n^2) by using heap sort instead
//if sub-array's size is smaller than passed parameter
//function calls insertionsort
template <typename type_t>
void introsort(std::vector<type_t> &array, int first, int last, int depth);
//functon to calling introsort and insertion sort for small arrays
template <typename type_t>
inline void introsortCaller(std::vector<type_t> &array) { introsort(array,0,array.size()-1,(int)floor(2*log(array.size())/M_LN2)); }
//function calls mergesort with arguments for sorting whole array
template <typename type_t>
inline void mergesortCaller(std::vector<type_t> &array) { mergesort(array,0,array.size()-1); }
//function calls quicksort with arguments for sorting whole array
template <typename type_t>
inline void quicksortCaller(std::vector<type_t> &array) { quicksort(array,0,array.size()-1); }
//function calls std::sort with arguments for sorting whole array
template <typename type_t>
inline void sortCaller(std::vector<type_t> &array) { std::sort(array.front(),array.back()); }
template <typename type_t>
inline void heapsortCaller(std::vector<type_t> &array) { heapsort(array,array.size()); }