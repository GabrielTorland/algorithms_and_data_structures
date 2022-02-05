//
// Created by MSI Gaming PC on 10/20/2021.
//

#ifndef SORTING_ALGORITHMS_SORTING_H
#define SORTING_ALGORITHMS_SORTING_H

#include <iostream>
#include <cmath>

int comparisons_glob();

void print_arr(int [], size_t);

void bubble_sort(int [], size_t);

void insertion_sort(int [], size_t);

void select_sort(int [], size_t);

void merge_sort(int [], int begin, int end);

void merge(int [], int, int, int);

int partition(int [], int, int);

void quick_sort(int [], int, int);

void heapify(int [], size_t, int);

void heap_sort(int [], int);

#endif //SORTING_ALGORITHMS_SORTING_H
