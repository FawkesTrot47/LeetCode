#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::string ransomNote = "a";
    // std::string magazine = "b";
    // std::string ransomNote = "aa";
    // std::string magazine = "ab";
    // std::string ransomNote = "aa";
    // std::string magazine = "aab";
    std::string ransomNote = "aa";
    std::string magazine = "aab";
    bool res = A.canConstruct(ransomNote, magazine);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}