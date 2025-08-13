#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::string S = "sususy";
    // std::string S = "abcabcbb"; // Expected output: 3
    // std::string S = "bbbbb"; // Expected output: 1
    // std::string S = "pwwkew"; // Expected output: 3
    std::string S = "dvdf"; // Expected output: 3
    int x = A.lengthOfLongestSubstring(S);
    std::cout << std::endl << x;
    return 0;
}