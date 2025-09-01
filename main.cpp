#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {1,3,4,2,2};
    std::vector<int> nums = {3,1,3,4,2};
    // std::vector<int> nums = {1,1};
    int res = A.findDuplicate(nums);
    std::cout << res << std::endl;
    return 0;
}