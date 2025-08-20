#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {1,1,1,2,2,3};
    // int k = 2;
    // std::vector<int> nums = {1};
    // int k = 1;
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10,8,9,10};
    int k = 3; // Top 3 frequent elements
    std::vector<int> res = A.topKFrequent(nums, k);
    A.printRes(res);
    return 0;
}