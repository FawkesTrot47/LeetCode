#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {1,2,3,1};
    // std::vector<int> nums = {1,2,3,4};
    // std::vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10}; // No duplicates
    bool res = A.containsDuplicate(nums);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}