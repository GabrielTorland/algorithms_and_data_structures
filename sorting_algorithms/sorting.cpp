//
// Created by MSI Gaming PC on 10/20/2021.
//

#include "sorting.h"

// Globals
int comparisons_global = 0;

int comparisons_glob(){
    return comparisons_global;
}

void bubble_sort(int arr[], size_t size){
    int comparisons = 0;
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size-i-1; ++j){
            comparisons++;
            if (arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
    print_arr(arr, size);
    printf("The number of comparisons is: %d\n", comparisons);
}

void insertion_sort(int arr[], size_t size){
    int comparisons = 0;
    for (int i = 1; i < size; ++i){
        int key = arr[i];
        int j = i-1;
        int temp_counter = 0;
        while (j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            temp_counter++;
            j--;
        }
        if (temp_counter != 0)
            comparisons += temp_counter;
        else
            comparisons++;
        arr[j+1] = key;
    }
    print_arr(arr, size);
    printf("The number of comparisons is: %d\n", comparisons);
}

void select_sort(int arr[], size_t size){
    int comparisons = 0;
    for (int i = 0; i < size; ++i){
        int min_index = i;
        for (int j = i+1; j < size; ++j){
            comparisons++;
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        std::swap(arr[i], arr[min_index]);
    }
    print_arr(arr, size);
    printf("The number of comparisons is: %d\n", comparisons);
}

void merge(int arr[], int left, int mid, int right){
    auto const sub_array_one = mid - left + 1;
    auto const sub_array_two = right - mid;

    // Create temp array.
    auto *left_arr = new int[sub_array_one];
    auto *right_arr = new int[sub_array_two];

    // Copy data to temp arrays.
    for (int i = 0; i < sub_array_one; ++i){
        left_arr[i] = arr[left + i];
    }
    for (int i = 0; i < sub_array_two; ++i){
        right_arr[i] = arr[mid + 1 + i];
    }
    auto index_of_sub_array_one = 0; // Initial index of first sub-array
    auto index_of_sub_array_two = 0; // Initial index of second sub-array
    int index_of_merged_array = left; // Initial index of merged array
    while (index_of_sub_array_one < sub_array_one && index_of_sub_array_two < sub_array_two){
        comparisons_global ++;
        if (left_arr[index_of_sub_array_one] <= right_arr[index_of_sub_array_two]){
            arr[index_of_merged_array] = left_arr[index_of_sub_array_one];
            index_of_sub_array_one++;
        }
        else{
            arr[index_of_merged_array] = right_arr[index_of_sub_array_two];
            index_of_sub_array_two++;
        }
        index_of_merged_array++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (index_of_sub_array_one < sub_array_one) {
        arr[index_of_merged_array] = left_arr[index_of_sub_array_one];
        index_of_sub_array_one++;
        index_of_merged_array++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (index_of_sub_array_two < sub_array_two) {
        arr[index_of_merged_array] = right_arr[index_of_sub_array_two];
        index_of_sub_array_two++;
        index_of_merged_array++;
    }
    delete[] left_arr;
    delete[] right_arr;
}

void merge_sort(int arr[], int begin, int end){
    if (begin >= end)
        return;
    int middle = begin + (end-begin)/2;
    merge_sort(arr, begin, middle);
    merge_sort(arr, middle+1, end);
    merge(arr, begin, middle, end);
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; ++j){
        comparisons_global++;
        if (arr[j] < pivot){
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}

void quick_sort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

// Max heap.
void heapify(int arr[], size_t size, int index){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    comparisons_global += 3;

    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != index){
        std::swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heap_sort(int arr[], int size){
    // Turn array to implicit max heap.
    for (int i = size/2 -1; i >= 0; --i){
        heapify(arr, size, i);
    }
    // Reduce size of array in heapify every iteration.
    for (int i = size-1; i > 0; --i){
        // Swapping the first and the last element. Setting the current largest element at the end of the array.
        std::swap(arr[0], arr[i]);

        // Converting the array back to max heap without  earlier arr[0]
        heapify(arr, i, 0);
    }
}