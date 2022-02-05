#include <iostream>
#include <cmath>
#include "sorting.h"

#define RANGE 500000

int main() {

    int arr[RANGE] = {0};
    for (int i = 0; i < RANGE; ++i){
        arr[i] = RANGE-i;
    }
    int answer = 0;
    printf("1. Bubble sort algorithm\n"
                  "2. Insertion sort algorithm\n"
                  "3. Select sort algorithm\n"
                  "4. Merge sort algorithm\n"
                  "5. Quick sort algorithm\n"
                  "6. Heap sort algorithm\n");
    scanf("%d", &answer);
    if (answer == 1)
        // 1.
        /* The number of comparison depend on the initial order. If the array is almost sorted, there is fewer complications. */
        bubble_sort(arr, sizeof(arr)/sizeof(int));

    else if (answer == 2)
        // 2.
        /* The number of comparison depend on the initial order. If the array is almost sorted, there is fewer complications. */
        insertion_sort(arr, sizeof(arr)/sizeof(int));

    else if (answer == 3)
        // 3.
        /* The number of comparison doesn't depend on the initial order. */
        select_sort(arr, sizeof(arr)/sizeof(int));

    else if (answer == 4){
        // 4.
        /* The number of comparison depend on the initial order. If the array is almost sorted, there is fewer complications. */
        merge_sort(arr, 0, sizeof(arr)/sizeof(int));
        print_arr(arr, sizeof(arr)/sizeof(int));
        printf("The number of comparisons is: %d\n", comparisons_glob());
    }
    else if (answer == 5){
        // 5.
        /* The number of comparison depend on the initial order. If the array is almost sorted, there is fewer complications. */
        // TODO : Find out why the quick sort algorithm is slow.
        // TODO : 6. Test with median as pivot.
        quick_sort(arr, 0, sizeof(arr)/sizeof(int)-1);
        print_arr(arr, sizeof(arr)/sizeof(int));
        printf("The number of comparisons is: %d\n", comparisons_glob());
    }
    else if (answer == 6){
       // 6.
       /* Heap sort is extremely efficient on larger arrays */
        heap_sort(arr, sizeof(arr)/sizeof(arr[0]));
        print_arr(arr, sizeof(arr)/sizeof(arr[0]));
        printf("The number of comparisons is: %d\n", comparisons_glob());
    }
    else
        // pass
    return 0;
}

void print_arr(int arr[], size_t size){
    printf("[");
    for (int i = 0; i < size; ++i){
        if (i == size-1){
            printf("%d", arr[i]);
        }
        else
            printf("%d, ", arr[i]);
    }
    printf("]\n");
}











