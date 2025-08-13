

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
    void printRes(std::vector<int> v1);
    void printRes(ListNode* l);

    // Leetcode exercise in order
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    int lengthOfLongestSubstring(std::string s);
    std::string longestCommonPrefix(std::vector<std::string>& strs);
    int maxProfit(std::vector<int>& prices);
    void reverseString(std::vector<char>& s);
    

private:
    int32_t m_a;
    int32_t m_b;
};