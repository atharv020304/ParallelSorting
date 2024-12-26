#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "mergeSort.hpp"
#include "parallelMergeSort.hpp"

using namespace std;

int main() {
    vector<int> nums(10000000);
    vector<int> nums1(10000000);


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10000000);

    for (int i = 0; i < 10000000; i++) {
        nums[i] = dis(gen);
        nums1[i] = dis(gen);
    }


    MergeSort ms(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    ms.sort();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> mergesortDuration = end - start;
    std::cout << "MergeSort algorithm took: " << mergesortDuration.count() << " seconds" << std::endl;

    
    ParallelMergeSort pms(&nums1);
    auto start1 = std::chrono::high_resolution_clock::now();
    pms.sort();
    auto end1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> parallelMergeSortDuration = end1 - start1;
    std::cout << "ParallelMergeSort algorithm took: " << parallelMergeSortDuration.count() << " seconds" << std::endl;

    return 0;
}
