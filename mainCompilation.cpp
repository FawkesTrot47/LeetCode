/*
    Compilation of all the main() functions per LeetCode problem
*/

/*
Problem 1: twoSum
int main_twoSum() {
    leetcode A;
    std::vector<int> B = {2,3,4,5,8};
    int target = 9;
    A.printRes(A.twoSum(B,target));
    return 0;
}
*/ 

/*
Problem 2: addTwoNumbers
int main_addTwo {
    leetcode A;
    ListNode* B = new ListNode(9);
    ListNode* C = new ListNode(9);
    B = B->addToListAtStart(B,9);
    B = B->addToListAtStart(B,9);
    B = B->addToListAtStart(B,9);
    C = C->addToListAtStart(C,9);
    C = C->addToListAtStart(C,9);
    // A.printRes(B);
    // A.printRes(C);
    ListNode *res = nullptr;
    res = A.addTwoNumbers(B,C);
    A.printRes(res);
    return 0;
}
*/

/*
Problem 3: lengthOfLongestSubstring
int main_lenSubs() {
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
*/

/*
Problem 14: longestCommonPrefix
int main_longestCommonPrefix() {
    leetcode A;
    std::vector<std::string> strs = {"flower","flow","flight"};
    std::string res = A.longestCommonPrefix(strs);
    std::cout << res;
    return 0;
}
*/

/*
Problem 121: maxProfit
int main_maxProfit() {
    leetcode A;
    // std::vector<int> prices = {7,1,5,3,6,4};
    // std::vector<int> prices = {7,6,4,3,1}; // No profit
    // std::vector<int> prices = {2,1}; // No profit
    std::vector<int> prices = {1,2,3,4,5}; // Max profit is 4
    int res = A.maxProfit(prices);
    std::cout << res;
    return 0;
}   
*/

/*
Problem 283: moveZeroes
int main_moveZeroes() {
    leetcode A;
    // std::vector<int> nums = {0,1,0,3,12};
    // std::vector<int> nums = {0,0,1};
    // std::vector<int> nums = {1,0,0,0,3,12};
    std::vector<int> nums = {0,1,0,3,12,0,0,0,0,0,11};
    A.moveZeroes(nums);
    A.printRes(nums);
    return 0;
}
*/

/*
Problem 344: reverseString
int main_reverseString() {
    leetcode A;
    // std::vector<char> s = {'h','e','l','l','o'};
    // std::vector<char> s = {'h','e','l','l','o',' ','w','o','r','l','d'};
    // std::vector<char> s = {'H','a','n','n','a'};
    std::vector<char> s = {'a','b','c','d','e','f','g','h','i','j'};
    // std::vector<char> s = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    A.reverseString(s);
    for (char c : s) {
        std::cout << c;
    }
    return 0;
}
*/

/*
Problem 424: characterReplacement
int main_characterReplacement() {
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
*/