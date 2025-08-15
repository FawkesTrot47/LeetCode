

#include <iostream>
#include <vector>
#include <map>
#include <string>

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
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    int lengthOfLongestSubstring(std::string s);
    std::string longestCommonPrefix(std::vector<std::string>& strs);
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
    int maxProfit(std::vector<int>& prices);
    std::vector<int> twoSumSecond(std::vector<int>& numbers, int target);
    void moveZeroes(std::vector<int>& nums);
    void reverseString(std::vector<char>& s);
    int characterReplacement(std::string s, int k);
    

private:
    int32_t m_a;
    int32_t m_b;
};