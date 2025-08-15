#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {-1,0,1,2,-1,-4};
    // std::vector<int> nums = {0,1,1};
    // std::vector<int> nums = {0,0,0,0};
    std::vector<int> nums = {-2,0,1,1,2};
    std::vector<std::vector<int>> res = A.threeSum(nums);
    for (const auto& vec : res) {
        std::cout << "[ ";
        for (const auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}