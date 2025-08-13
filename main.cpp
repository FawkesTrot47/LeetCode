#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {0,1,0,3,12};
    // std::vector<int> nums = {0,0,1};
    // std::vector<int> nums = {1,0,0,0,3,12};
    std::vector<int> nums = {0,1,0,3,12,0,0,0,0,0,11};
    A.moveZeroes(nums);
    A.printRes(nums);
    return 0;
}