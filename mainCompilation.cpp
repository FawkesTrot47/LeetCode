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
Problem 4: findMedianSortedArrays
int main_findMedianSortedArrays() {
    leetcode A;
    // std::vector<int> nums1 = {1,3};
    // std::vector<int> nums2 = {2};
    // std::vector<int> nums1 = {1,2};
    // std::vector<int> nums2 = {3,4};
    std::vector<int> nums1 = {1,2,3,4,5};
    std::vector<int> nums2 = {6,7,8,9,10};
    double res = A.findMedianSortedArrays(nums1, nums2);
    std::cout << res;
    return 0;
}
*/

/*
Problem 5: longestPalindrome
int main_longestPalindrome() {
    leetcode A;
    // std::string S = "babad"; // Expected output: "bab" or "aba"
    // std::string S = "cbbd"; // Expected output: "bb"
    // std::string S = "a"; // Expected output: "a"
    // std::string S = "ac"; // Expected output: "a" or "c"
    std::string S = "racecar"; // Expected output: "racecar"
    std::string res = A.longestPalindrome(S);
    std::cout << res;
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
Problem 15: 3Sum
int main_3Sum() {
    leetcode A;
    // std::vector<int> nums = {-1,0,1,2,-1,-4};
    // std::vector<int> nums = {0,1,1};
    // std::vector<int> nums = {0,0,0,0};
    std::vector<int> nums = {-2,0,1,1,2};
    std::vector<std::vector<int>> res = A.threeSum(nums);
    for (const auto& vec : res) {
        std::cout << "[ ";
        for (const auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}   
*/

/*
Problem 36: Valid Sudoku
int main_isValidSudoku() {
    leetcode A;
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool res = A.isValidSudoku(board);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
*/

/*
Problem 49: groupAnagrams
int main_groupAnagrams() {
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
*/

/*
Problem 53: maxSubArray
int main_maxSubArray() {
    leetcode A;
    // std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4}; // Expected output: 6
    std::vector<int> nums = {1}; // Expected output: 1
    // std::vector<int> nums = {5,4,-1,7,8}; // Expected output: 23
    int res = A.maxSubArray(nums);
    std::cout << res;
    return 0;
}
*/

/*
Problem 66: plusOne
int main_plusOne() {
    leetcode A;
    // std::vector<int> digits = {1,2,3}; // Expected output: [1,2,4]
    // std::vector<int> digits = {4,3,2,1}; // Expected output: [4,3,2,2]
    std::vector<int> digits = {9,9,9}; // Expected output: [1,0,0,0]
    std::vector<int> res = A.plusOne(digits);
    A.printRes(res);
    return 0;
}
*/

/*
Problem 76: minWindow
int main_minWindow() {
    leetcode A;
    // std::string s = "ADOBECODEBANC";
    // std::string t = "ABC";
    // std::string s = "a";
    // std::string t = "a";
    std::string s = "a";
    std::string t = "aa";
    std::string res = A.minWindow(s, t);
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
Problem 122: maxProfitII
int main_maxProfitII() {
    leetcode A;
    // std::vector<int> prices = {7,1,5,3,6,4};
    // std::vector<int> prices = {1,2,3,4,5}; // Max profit is 4
    std::vector<int> prices = {7,6,4,3,1}; // No profit
    int res = A.maxProfitII(prices);
    std::cout << res;
    return 0;
}
*/

/*
Problem 136: singleNumber
int main_singleNumber() {
    leetcode A;
    // std::vector<int> nums = {4,1,2,1,2};
    std::vector<int> nums = {2,2,1};
    int res = A.singleNumber(nums);
    std::cout << res;
    return 0;
}
*/

/*
Problem 190: Reverse Bits
int main_reverseBits() {
    leetcode A;
    uint32_t n = 43261596; // Expected output: 964176192
    // uint32_t n = 4294967293; // Expected output: 3221225471
    uint32_t res = A.reverseBits(n);
    std::cout << res;
    return 0;
}
*ß/

/*
Problem 191: hammingWeight
int main_hammingWeight() {
    leetcode A;
    int n = 11; // Expected output: 3
    // int n = 128; // Expected output: 1
    // int n = 2147483645; // Expected output: 30
    int res = A.hammingWeight(n);
    std::cout << res;
    return 0;
}
*/

/*
Problem 238: Product of Array Except Self
int main_productExceptSelf() {
    leetcode A;
    // std::vector<int> nums = {1,2,3,4};
    std::vector<int> nums = {-1,1,0,-3,3};
    std::vector<int> res = A.productExceptSelf(nums);
    A.printRes(res);
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
Problem 167: twoSum
int main_twoSumSecond() {
    leetcode A;
    // std::vector<int> numbers = {2,3,4,5,8};
    std::vector<int> numbers = {2,7,11,15};
    // std::vector<int> numbers = {2,3,4};
    // std::vector<int> numbers = {-1,0};
    int target = 9;
    A.printRes(A.twoSumSecond(numbers, target));
    return 0;
}
*/

/*
Problem 207: canFinish
int main_canFinish() {
    leetcode A;
    // int numCourses = 2;
    // std::vector<std::vector<int>> prerequisites = {{1,0}}; // Expected output: true
    int numCourses = 2;
    std::vector<std::vector<int>> prerequisites = {{1,0},{0,1}}; // Expected output: false
    bool res = A.canFinish(numCourses, prerequisites);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
*/

/*
Problem 217: containsDuplicate
int main_containsDuplicate() {
    leetcode A;
    // std::vector<int> nums = {1,2,3,1};
    // std::vector<int> nums = {1,2,3,4};
    // std::vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10}; // No duplicates
    bool res = A.containsDuplicate(nums);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
*/

/*
Problem 231: isPowerOfTwo
int main_isPowerOfTwo() {
    leetcode A;
    // int n = 1; // Expected output: true
    int n = 16; // Expected output: true
    // int n = 3; // Expected output: false
    bool res = A.isPowerOfTwo(n);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
*/

/*
Problem 242: isAnagram
int main_isAnagram() {
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
*/

/* 
Problem 268: missingNumber
int main_missingNumber() {
    leetcode A;
    // std::vector<int> nums = {3,0,1};
    // std::vector<int> nums = {0,1};
    std::vector<int> nums = {9,6,4,2,3,5,7,0,1};
    int res = A.missingNumber(nums);
    std::cout << res << std::endl;
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
Problem 347: topKFrequent
int main_topKFrequent() {
    leetcode A;
    // std::vector<int> nums = {1,1,1,2,2,3};
    // int k = 2;
    // std::vector<int> nums = {1};
    // int k = 1;
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};
    int k = 3; // Top 3 frequent elements
    std::vector<int> res = A.topKFrequent(nums, k);
    A.printRes(res);
    return 0;
}
*/

/*
Problem 383: canConstruct
int main_canConstruct() {
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

/*
Problem 448: findDisappearedNumbers
int main_findDisappearedNumbers() {
    leetcode A;
    // std::vector<int> nums = {4,3,2,7,8,2,3,1};
    // std::vector<int> nums = {1,1};
    std::vector<int> nums = {2,2};
    std::vector<int> res = A.findDisappearedNumbers(nums);
    A.printRes(res);
    return 0;
}
*/

/*
Problem 560: subarraySum
int main_subarraySum() {
    leetcode A;
    // std::vector<int> nums = {1,1,1};
    // int k = 2; // Expected output: 2
    std::vector<int> nums = {1,2,3};
    int k = 3; // Expected output: 2
    int res = A.subarraySum(nums, k);
    std::cout << res;
    return 0;
}
*/