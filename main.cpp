#include "leetcode.cpp"

int main() {
    leetcode A;
    std::vector<std::string> strs = {"flower","flow","flogger"};
    std::string res = A.longestCommonPrefix(strs);
    std::cout << res;
    return 0;
}