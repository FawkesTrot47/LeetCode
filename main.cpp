#include "leetcode.cpp"

int main() {
    leetcode A;
    // std::vector<char> s = {'h','e','l','l','o'};
    // std::vector<char> s = {'h','e','l','l','o',' ','w','o','r','l','d'};
    std::vector<char> s = {'H','a','n','n','a'};
    // std::vector<char> s = {'a','b','c','d','e','f','g','h','i','j'};
    // std::vector<char> s = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    A.reverseString(s);
    for (char c : s) {
        std::cout << c;
    }
    return 0;
}