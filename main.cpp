#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::string S = "babad"; // Expected output: "bab" or "aba"
    std::string S = "cbbd"; // Expected output: "bb"
    // std::string S = "a"; // Expected output: "a"
    // std::string S = "ac"; // Expected output: "a" or "c"
    // std::string S = "racecar"; // Expected output: "racecar"
    std::string res = A.longestPalindrome(S);
    std::cout << res;
    return 0;
}