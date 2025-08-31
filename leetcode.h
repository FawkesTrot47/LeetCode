

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode()
        : val(0)
        , next(nullptr) {}
    ListNode(int x)
        : val(x)
        , next(nullptr) {}
    ListNode(int x, ListNode *n)
        : val(x)
        , next(n) {}    
    ListNode* addToListAtStart(ListNode *head, int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        return head;
    }
};

class leetcode : public ListNode {
public:
    leetcode()
        : m_a{0}
        , m_b(0) {}

    ~leetcode() {}    
    void printAandB();
    void setAandB(int32_t A, int32_t B);
    template <typename T>
    void printRes(std::vector<T> v1);
    void printRes(ListNode* l);

    // Leetcode exercise in order
    std::vector<int> twoSum(std::vector<int>& nums, int target);                                                                    // 1    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);                                                                            // 2
    int lengthOfLongestSubstring(std::string s);                                                                                    // 3
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);                                                // 4
    std::string longestPalindrome(std::string s); std::pair<int,int> widen(std::string s, int l, int r);                            // 5
    std::string longestCommonPrefix(std::vector<std::string>& strs);                                                                // 14
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);                                                                 // 15
    bool isValidSudoku(std::vector<std::vector<char>>& board);                                                                      // 36
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);                                            // 49
    int maxSubArray(std::vector<int>& nums);                                                                                        // 53
    std::string minWindow(std::string s, std::string t);                                                                            // 76
    int maxProfit(std::vector<int>& prices);                                                                                        // 121
    int singleNumber(std::vector<int>& nums);                                                                                       // 136
    std::vector<int> twoSumSecond(std::vector<int>& numbers, int target);                                                           // 167
    uint32_t reverseBits(uint32_t n);                                                                                               // 190
    int hammingWeight(int n);                                                                                                       // 191
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);                                                   // 207
    bool containsDuplicate(std::vector<int>& nums);                                                                                 // 217
    bool isPowerOfTwo(int n);                                                                                                       // 231
    std::vector<int> productExceptSelf(std::vector<int>& nums);                                                                     // 238
    bool isAnagram(std::string s, std::string t);                                                                                   // 242
    int missingNumber(std::vector<int>& nums);                                                                                      // 268        
    void moveZeroes(std::vector<int>& nums);                                                                                        // 283   
    void reverseString(std::vector<char>& s);                                                                                       // 344
    std::vector<int> topKFrequent(std::vector<int>& nums, int k);                                                                   // 347
    bool canConstruct(std::string ransomNote, std::string magazine);                                                                // 383
    int characterReplacement(std::string s, int k);                                                                                 // 424
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums);                                                                // 448
    int subarraySum(std::vector<int>& nums, int k);                                                                                 // 560

private:
    int32_t m_a;
    int32_t m_b;
};