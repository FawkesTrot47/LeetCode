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
    std::string S = "sususy";
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