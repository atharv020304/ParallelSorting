#include "parallelMergeSort.hpp"
#include <thread>
#include <iostream>
#include <algorithm>  


ParallelMergeSort::ParallelMergeSort(std::vector<int>* nums) : nums(nums) {}


void ParallelMergeSort::helper(int left, int right) {
    if (left >= right) {
        return;
    }

    
    const int threshold = 1000;
    
    if (right - left <= threshold) {
        std::sort((*nums).begin() + left, (*nums).begin() + right + 1);
        return;
    }

    int mid = (left + right) / 2;
    int mid_plus_1 = mid + 1;


    std::thread thread_1([this, left, mid] { this->helper(left, mid); });
    std::thread thread_2([this, mid_plus_1, right] { this->helper(mid_plus_1, right); });


    thread_1.join();
    thread_2.join();

    
    std::vector<int> result;
    int i = left;
    int j = mid_plus_1;

    while (i <= mid && j <= right) {
        if ((*nums)[i] <= (*nums)[j]) {
            result.push_back((*nums)[i]);
            i++;
        } else {
            result.push_back((*nums)[j]);
            j++;
        }
    }

    
    while (i <= mid) {
        result.push_back((*nums)[i]);
        i++;
    }

    while (j <= right) {
        result.push_back((*nums)[j]);
        j++;
    }

    
    for (int k = 0; k < result.size(); k++) {
        (*nums)[left + k] = result[k];
    }
}


void ParallelMergeSort::sort() {
    if ((*nums).size() == 0) {
        return;
    }
    helper(0, (*nums).size() - 1);
}


ParallelMergeSort::~ParallelMergeSort() {
    
}
