#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    // std::vector<std::string> strs = {"",""};
    // std::vector<std::string> strs = {"a"};
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat","tab","tab"};
    std::vector<std::vector<std::string>> res = A.groupAnagrams(strs);
    for (const auto& group : res) {
        A.printRes(group);
        std::cout << std::endl;
    }
    return 0;
}