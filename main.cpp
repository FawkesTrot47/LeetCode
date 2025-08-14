#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::string s = "AABABBA"; // Expected output: 5
    // std::string s = "ABAB"; // Expected output: 4
    // std::string s = "AABBA"; // Expected output: 4
    std::string s = "AABABBA"; // Expected output: 5
    int k = 2; // Number of characters we can replace
    int res = A.characterReplacement(s, k);
    std::cout << res;
    return 0;
}