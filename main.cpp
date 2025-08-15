#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> numbers = {2,3,4,5,8};
    std::vector<int> numbers = {2,7,11,15};
    // std::vector<int> numbers = {2,3,4};
    // std::vector<int> numbers = {-1,0};
    int target = 9;
    A.printRes(A.twoSumSecond(numbers, target));
    return 0;
}