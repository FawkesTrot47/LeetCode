#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {1,1,1};
    // int k = 2; // Expected output: 2
    std::vector<int> nums = {1,2,3};
    int k = 3; // Expected output: 2
    int res = A.subarraySum(nums, k);
    std::cout << res;
    return 0;
}