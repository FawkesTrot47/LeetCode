#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {3,0,1};
    // std::vector<int> nums = {0,1};
    std::vector<int> nums = {9,6,4,2,3,5,7,0,1};
    int res = A.missingNumber(nums);
    std::cout << res << std::endl;
    return 0;
}