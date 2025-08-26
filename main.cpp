#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {4,1,2,1,2};
    std::vector<int> nums = {2,2,1};
    int res = A.singleNumber(nums);
    std::cout << res;
    return 0;
}