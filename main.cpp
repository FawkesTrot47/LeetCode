#include "leetcode.cpp"

int main() {
    leetcode A;
    // int n = 1; // Expected output: true
    int n = 16; // Expected output: true
    // int n = 3; // Expected output: false
    bool res = A.isPowerOfTwo(n);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}