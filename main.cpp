#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {1,2,3,4};
    std::vector<int> nums = {-1,1,0,-3,3};
    std::vector<int> res = A.productExceptSelf(nums);
    A.printRes(res);
    return 0;
}