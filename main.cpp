#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> digits = {1,2,3}; // Expected output: [1,2,4]
    // std::vector<int> digits = {4,3,2,1}; // Expected output: [4,3,2,2]
    std::vector<int> digits = {9,9,9}; // Expected output: [1,0,0,0]
    std::vector<int> res = A.plusOne(digits);
    A.printRes(res);
    return 0;
}