#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {4,3,2,7,8,2,3,1};
    // std::vector<int> nums = {1,1};
    std::vector<int> nums = {2,2};
    std::vector<int> res = A.findDisappearedNumbers(nums);
    A.printRes(res);
    return 0;
}