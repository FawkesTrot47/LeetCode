#include "leetcode.cpp"

int main() {
    leetcode A;
    int n = 11; // Expected output: 3
    // int n = 128; // Expected output: 1
    // int n = 2147483645; // Expected output: 30
    int res = A.hammingWeight(n);
    std::cout << res;
    return 0;
}