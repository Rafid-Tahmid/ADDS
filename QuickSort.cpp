#include "QuickSort.h"

std::vector<int> QuickSort::sort(std::vector<int> list) {
    quickSort(list, 0, list.size() - 1);
    return list;
}

void QuickSort::quickSort(std::vector<int>& list, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(list, left, right);
        quickSort(list, left, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, right);
    }
}

int QuickSort::partition(std::vector<int>& list, int left, int right) {
    int pivotIndex;
    if (right - left >= 2) {
        pivotIndex = left + 2;
    } else {
        pivotIndex = left + (right - left) / 2;
    }
    
    int pivotValue = list[pivotIndex];
    std::swap(list[pivotIndex], list[right]);
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (list[i] < pivotValue) {
            std::swap(list[i], list[storeIndex]);
            storeIndex++;
        }
    }
    std::swap(list[storeIndex], list[right]);
    return storeIndex;
}