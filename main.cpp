#include "leetcode.cpp"

int main() {
    leetcode A;
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    // std::string s = "a";
    // std::string t = "a";
    // std::string s = "a";
    // std::string t = "aa";
    std::string res = A.minWindow(s, t);
    std::cout << res;
    return 0;
}