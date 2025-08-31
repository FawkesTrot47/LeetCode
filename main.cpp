#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> nums = {2,3,1,1,4}; // Expected output: true
    std::vector<int> nums = {3,2,1,0,4}; // Expected output: false
    // std::vector<int> nums = {0}; // Expected output: true
    bool res = A.canJump(nums);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}