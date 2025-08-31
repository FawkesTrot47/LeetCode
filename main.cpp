#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4}; // Expected output: 6
    // std::vector<int> nums = {1}; // Expected output: 1
    std::vector<int> nums = {5,4,-1,7,8}; // Expected output: 23
    int res = A.maxSubArray(nums);
    std::cout << res;
    return 0;
}