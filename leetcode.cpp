#include "leetcode.h"

void leetcode::printAandB() {
    std::cout << "A:" << m_a << std::endl << " B:" << m_b;
}

void leetcode::setAandB(int32_t A, int32_t B) {
    m_a = A;
    m_b = B;
}

void leetcode::printRes(std::vector<int> v1) {
    std::cout <<"[ ";
    for (auto x : v1) {
        std::cout << x << " ";
    }
    std::cout<<"]";
}

// Traversing through the linked list
void leetcode::printRes(ListNode* l) {
    std::cout << "[ ";
    while(l!=nullptr) {
        std::cout << l->val << " ";
        l = l->next;
    }
    std::cout << "]";
}

/*
LeetCode 1: Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/
std::vector<int> leetcode::twoSum(std::vector<int>& nums, int target) {
    std::vector<int> ret;  
    std::map<int,int> map1;
    for (int i=0; i<nums.size(); i++) {
        // Case where second number is not found
        if (map1.find(nums.at(i))==map1.end()) {
            map1[target-nums.at(i)] = i;
        }
        // Second number was found
        else {
            ret.push_back(i);
            ret.push_back(map1[nums.at(i)]);
            break;
        }
    }
    return ret;
}

/*
LeetCode 2: Add two numbers
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

ListNode* leetcode::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l3 = nullptr;
    ListNode** head = &l3;
    int carryOver = 0, sum=0;
    while (l1!=nullptr || l2!=nullptr || carryOver) {
        sum=0;
        if (l1!=nullptr) {
            sum+= l1->val;
            l1 = l1->next;
        }
        if (l2!=nullptr) {
            sum+= l2->val;
            l2 = l2->next;
        }
        ListNode* newNode = new ListNode((carryOver + sum)%10); 
        carryOver = ((carryOver + sum)/10) ? 1:0;   
        *head = newNode;
        head = &newNode->next;
    }
    return l3;
}

/*
LeetCode 3: Length of longest substring
Given a string s, find the length of the longest substring without repeating characters.

Example:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Idea:   
    Update a char-int map with position of char. If a repeat is found, update that as last repeated position.
    Current index - last repeated position would be length of substring w/o repeat cha. Update for max.
*/

int leetcode::lengthOfLongestSubstring(std::string s) {
    if (!s.length() || s.length()==1) return s.length();
    int sublength=0, l=0;
    std::unordered_map <char, int> strmap;
    strmap[s[0]]=0;
    for (auto i = 1; i<s.length(); i++) {
        auto it = strmap.find(s[i]);
        if (it!=strmap.end() && it->second >= l) {
            l = it->second + 1;
        }
        strmap[s[i]]=i;
        sublength = std::max(sublength,i-l+1);
    }
    return sublength;
}

/* 
LeetCode 14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "". 

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Idea:
    Compare each string with the first string. If a mismatch is found, return the prefix till that point.
    If no mismatch is found, return the first string.
*/

std::string leetcode::longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    size_t min_len = strs[0].size();
    for (size_t i= 1; i<strs.size(); i++) {
        min_len = std::min(min_len, strs[i].size());
    }
    if (!min_len) {
        return "";
    }
    std::string ch = "";
    for (size_t i=0; i<min_len; i++) {
        ch.push_back(strs[0][i]);
        for (size_t j=1; j<strs.size(); j++) {
            if (ch.back()!=strs[j][i]) {
                ch.pop_back();
                return ch;
            }
        }
    }
    return ch;
}

/*
LeetCode 121. Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Idea:
    Keep track of the minimum price seen so far and calculate the profit if sold on each day.
    Update the maximum profit if the current profit is greater than the previous maximum.
*/

int leetcode::maxProfit(std::vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int currmin = prices[0], max_profit = 0;
    for (size_t i=1; i<prices.size(); i++) {
        currmin = std::min(currmin, prices[i]);
        max_profit = std::max(prices[i]-currmin,max_profit);
    }
    return max_profit;
}

/*
LeetCode 344. Reverse String
Write a function that reverses a string. The input string is given as an array of characters.
You must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Idea:
    Use two pointers, one at the start and one at the end of the string.
    Swap characters at these pointers and move them towards the center until they meet.
*/

void leetcode::reverseString(std::vector<char>& s) {
    for (size_t l=0, r=s.size()-1; l<r; l++,r--) {
        std::swap(s[l],s[r]);
    }
}