#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<int> prices = {7,1,5,3,6,4};
    // std::vector<int> prices = {1,2,3,4,5}; // Max profit is 4
    std::vector<int> prices = {7,6,4,3,1}; // No profit
    int res = A.maxProfitII(prices);
    std::cout << res;
    return 0;
}