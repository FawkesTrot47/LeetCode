#include "leetcode.cpp"

int main() {
    leetcode A;
    uint32_t n = 43261596; // Expected output: 964176192
    // uint32_t n = 4294967293; // Expected output: 3221225471
    uint32_t res = A.reverseBits(n);
    std::cout << res;
    return 0;
}