#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::string s = "anagram";
    // std::string t = "nagaram";
    // std::string s = "rat";
    // std::string t = "car";
    std::string s = "listen";
    std::string t = "silent";
    bool res = A.isAnagram(s, t);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}