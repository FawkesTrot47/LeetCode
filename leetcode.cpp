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
    std::map<char,int> map1;
    int index=0, subsLenMax = 0, lastRepeatIndex = -1;
    for (auto c : s) {
        if (map1.find(c)!=map1.end() && lastRepeatIndex < map1.at(c)) {
            lastRepeatIndex = map1.at(c);
        }
        if (index - lastRepeatIndex > subsLenMax) {
            subsLenMax = index - lastRepeatIndex;
        }
        map1[c] = index++;
    }
    return subsLenMax;
}