#include "leetcode.h"

void leetcode::printAandB() {
    std::cout << "A:" << m_a << std::endl << " B:" << m_b;
}

void leetcode::setAandB(int32_t A, int32_t B) {
    m_a = A;
    m_b = B;
}

template <typename T>
void leetcode::printRes(std::vector<T> v1) {
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
Leetcode 4: Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Idea:
    Use two pointers to traverse both arrays and find the median.
    If the total number of elements is odd, return the middle element.
    If it is even, return the average of the two middle elements.
*/

double leetcode::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    const size_t m=nums1.size(), n=nums2.size(), total = m+n, mid1 = (total-1)/2, mid2 = total/2;
    if (!m && !n) return 0.0;
    int i=0, j=0, k=0, lval=0, rval=0;
    while (k<=mid2) {
        int pick;
        if (i<m && (j>=n || nums1[i] <= nums2[j])) pick = nums1[i++];
        else pick = nums2[j++]; 
        if (k==mid1) lval=pick;
        if (k==mid2) rval=pick;
        ++k;
    }
    return (total%2) ? static_cast<double>(rval) : static_cast<double>(lval)/2+static_cast<double>(rval)/2;
}

/*
Leetcode 5: Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:
Input: s = "cbbd"
Output: "bb"

Idea:
    Use a helper function to expand around the center of the palindrome. Check both odd and even length palindromes.
    Update the longest palindrome found so far.
*/

std::string leetcode::longestPalindrome(std::string s) {
    size_t n = s.size();
    if (n<=1) return s;
    int bstart = 0, blen = 1;
    for (auto i=0; i<n; i++) {
        std::pair <int,int> res = widen(s,i,i);
        int ostart = res.first, olen = res.second;
        if (olen>blen) {
            blen = olen;
            bstart = ostart;
        }
        if (i<n-1){
            std::pair <int,int> res = widen(s,i,i+1);
            int estart = res.first, elen = res.second;
            if (elen>blen) {
                blen = elen;
                bstart = estart;
            }
        }
    }
    return s.substr(bstart, blen);
}   

std::pair<int,int> leetcode::widen(std::string s, int l, int r) {
    while (l>=0 && r<s.size() && s[l]==s[r]) {
        l--;
        r++;
    }
    ++l; --r;
    return {l,r-l+1};
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
Leetcode 15: 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Idea:
    Sort the array first. Then use a for loop to fix one element and use two pointers to find the other two elements.
    If the sum is less than zero, move the left pointer to the right. If the sum is greater than zero, move the right pointer to the left.
    If the sum is zero, add the triplet to the result and move both pointers inward.
*/

std::vector<std::vector<int>> leetcode::threeSum(std::vector<int>& nums) {
    if (nums.size()<3) return {};
    std::sort(nums.begin(), nums.end());
    size_t l=1, r=nums.size()-1, start=0;
    size_t n = nums.size();
    int target = 0, sum = 0;
    std::vector<std::vector<int>> v1;
    while (start<n-2) {
        target = nums[start];
        if (start>0 && target==nums[start-1]) {start++;l=start+1;r=n-1;continue;}
        while (l<r) {
            sum = nums[l]+nums[r];
            if (-target == sum) {
                v1.push_back({nums[start],nums[l],nums[r]});
                do {++l;} while(l<r && nums[l]==nums[l-1]);
                do {--r;} while(l<r && nums[r]==nums[r+1]);
            }
            else if (-target > sum)
                l++;
            else r--;
        }
        start++;
        l=start+1;
        r=n-1;
    }
    return v1;
}

/*
LeetCode 36: Valid Sudoku
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Example 1: 
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

Idea: 
    Use three 1D arrays to keep track of the numbers seen in each row, column, and 3x3 sub-box. The array is populated with bitwise OR operation at a location based on 1 shifted by the number seen - '1'.
    If the array & 1<<number seen is true, return false. If the loop completes without finding any duplicates, return true.
*/

bool leetcode::isValidSudoku(std::vector<std::vector<char>>& board) {
    int row[9] = {0}, col[9]={0}, box[9] = {0};
    for (size_t r=0; r<9; r++) {
        for (size_t c=0; c<9; c++) {
            char ch = board[r][c];
            if (ch!='.') {
                int l = ch - '1';
                int b = 1<<l;
                if (row[r] & b || col[c] & b || box[(r/3)*3 + (c/3)] & b)
                    return false;
                row[r] |= b;
                col[c] |= b;
                box[(r/3)*3 + (c/3)] |= b;
            }
        }
    } 
    return true;
}

/*
LeetCode 49: Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:
Input: strs = [""]
Output: [[""]]
Example 3:
Input: strs = ["a"]
Output: [["a"]]

Idea:
    Use a map to store the sorted string as the key and the original strings as the values.
    Iterate through each string, sort it, and add it to the map. Finally, return the values of the map.
*/

std::vector<std::vector<std::string>> leetcode::groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> ret;
    if (strs.empty()) return ret;
    std::unordered_map <std::string, std::vector<std::string>> map1;
    for (const auto &s : strs) {
        std::string s1 = s;
        std::sort(s1.begin(),s1.end());
        map1[s1].push_back(s);
    }
    auto it = map1.begin();
    while (it!=map1.end()) {
        ret.push_back(std::move(it->second));
        it++;
    }
    return ret;
}

/*
LeetCode 53: Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The contiguous subarray [4,-1,2,1] has the largest sum 6.
Example 2:
Input: nums = [1]
Output: 1
Explanation: The contiguous subarray [1] has the largest sum 1.

Idea:
    Check for the max between the current best and the current sum + current number.
    If the current sum + current number is less than the current number, reset the current sum to the current number.
    This way, we are always keeping track of the maximum sum subarray ending at the current position.
*/

int leetcode::maxSubArray(std::vector<int>& nums) {
    int l=0, curr=nums[0], currBest=curr;
    for (auto r=1; r<nums.size(); r++) {
        int n = nums[r];
        curr = std::max(n, curr+n);
        currBest = std::max(curr,currBest);
    }
    return currBest;
}

/*
Problem 55: Jump Game
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index. 

Idea:
    Keep track of the maximum index that can be reached at each step.
    If at any point, the current index is greater than the maximum reachable index, return false.
    If the maximum reachable index is greater than or equal to the last index, return true.
*/

bool leetcode::canJump(std::vector<int>& nums) {
    size_t n = nums.size();
    int maxReach = 0;
    for (int i=0; i<n; i++) {
        if (i > maxReach) return false;
        maxReach = std::max(maxReach, i+nums[i]);
        if (maxReach>=n-1) return true;
    }    
    return true;
}

/*
Leetcode 66: Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-toright order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].   

Idea: 
    Start from the last digit and add one. If the digit becomes 10, set it to 0 and carry over 1 to the next digit.
    If there is a carry over after the first digit, insert 1 at the beginning of the array.
*/

std::vector<int> leetcode::plusOne(std::vector<int>& digits) {
    const size_t n = digits.size();
    int carry = 1;
    for (int i=n-1; i>=0; i--) {
        digits[i] += carry;
        carry = digits[i] / 10;
        if (!carry) break;
        digits[i] %=10;
    }
    if (carry) {
        digits.insert(digits.begin(), carry);
    }
    return digits;
}

/*
LeetCode 76: Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Idea:
    Use two pointers to represent the window. Expand the right pointer to include more characters until all characters in t are included.
    Then, contract the left pointer to find the minimum window. Update the minimum window found so far.
    Use two maps to keep track of the character counts in t and the current window.
*/

std::string leetcode::minWindow(std::string s, std::string t) {
    const size_t m=s.size(), n=t.size();
    if ((m < n) || !n) return "";
    std::unordered_map <char, int> map1, map2;
    for (auto i=0; i<n; i++) {
        map1[t[i]]++;
    }
    int l=0, r=0, need=map1.size(), formed=0, blen=INT_MAX, bstart = 0;
    while (r<m) {
        auto c = s[r++];
        map2[c]++;
        auto it = map1.find(c);
        if (it!=map1.end() && it->second==map2[c])
            formed++;
        while (formed==need) {
            if (r-l<blen) {
                blen = std::min(r-l,blen);
                bstart = l;
            }
            auto c = s[l];
            map2[c]--;
            auto it = map1.find(c);
            if (it!=map1.end() && map2[c]<it->second)
                --formed;
            ++l;
        }
    }
    return (blen==INT_MAX) ? "" : s.substr(bstart,blen);
}

/*
LeetCode 83: Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Example 1:
Input: head = [1,1,2]
Output: [1,2]
Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

Idea: 
    Traverse the linked list and compare the current node with the next node.
    If they are the same, skip the next node. If they are different, move to the next node.
*/

ListNode* leetcode::deleteDuplicates(ListNode* head) {
    ListNode* current = head;
    while (current && current->next) {
        if (current->val==current->next->val) {
            current->next = current->next->next;
        }
        else {
            current = current->next;
        }
    }
    return head;
}

/*
LeetCode 92: Reverse Linked List II
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
*/

ListNode* leetcode::reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    current->next = head;
    for (int i=1; i<left; i++) {
        current = current->next;
    }
    ListNode* prev = nullptr;
    ListNode* curr = current->next;
    while (left<=right) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        left++;
    }
    ListNode* tail = current->next;
    current->next = prev;
    tail->next = curr;
    return dummy.next;        
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
Leetcode 122: Best Time to Buy and Sell Stock II
You are given an array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done and the max profit = 0.

Idea:
    Iterate through the prices array and add the profit for each day where the price is greater than the previous day.
    This way, we are effectively buying at the lowest point and selling at the highest point for each increasing sequence of prices.
*/

int leetcode::maxProfitII(std::vector<int>& prices) {
    const size_t n = prices.size();
    int currProfit=0;
    for (int i=1; i<n; i++) {
        if (prices[i] > prices[i-1])
            currProfit += prices[i] - prices[i-1];
    }
    return currProfit;        
}

    /*
Problem 136: Single Number
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
Example 1:
Input: nums = [2,2,1]
Output: 1
Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
Example 3:
Input: nums = [1]
Output: 1

Idea:
    Use XOR operation to find the single number. XOR of a number with itself is 0 and XOR of a number with 0 is the number itself.
    Therefore, XORing all the numbers will cancel out the numbers that appear twice and leave the single number.
*/

int leetcode::singleNumber(std::vector<int>& nums) {
    int res = 0;
    for (auto n : nums) {
    res ^= n;
    } 
    return res;
}

/*
LeetCode 141: Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Idea:
    Use two pointers, one moving at normal speed and the other moving at double speed. If there is a cycle, the two pointers will eventually meet.
    If the fast pointer reaches the end of the list, there is no cycle.
*/

bool leetcode::hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast==slow) return true;
    }
    return false;
}

/*
Leetcode 160: Intersection of Two Linked Lists
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null. 
*/

ListNode* leetcode::getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::unordered_set<ListNode*> s1;
    while (headA) {
        s1.insert(headA);
        headA = headA->next;
    }
    while (headB) {
        if (!s1.insert(headB).second) return headB;
        headB = headB->next;
    }
    return nullptr;
}

/*
LeetCode 167. Two Sum II - Input Array Is Sorted
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

Idea:
    Use two pointers, one at the start and one at the end of the array. If the sum of the two numbers is less than the target, move the left pointer to the right.
    If the sum is greater than the target, move the right pointer to the left. If the sum equals the target, return the indices.
*/

std::vector<int> leetcode::twoSumSecond(std::vector<int>& numbers, int target) {
    size_t l=0, r = numbers.size()-1;
    while (l<r) {
        if (target == numbers[l]+numbers[r])
            return {static_cast<int>(l+1),static_cast<int>(r+1)};
        if (numbers[l]+numbers[r] > target)
            r--;
        else if (numbers[l]+numbers[r] < target)
            l++;
    }
    return {};
}

/*
Leetcode 190: Reverse Bits
Reverse bits of a given 32 bits unsigned integer.
Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

Idea:
    Use bit manipulation to reverse the bits. Iterate through each bit of the input number, and set the corresponding bit in the result.
*/

uint32_t leetcode::reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for (int i=0; i<32; i++) {
        rev = (rev<<1) | (n & 1);
        n = n>>1;
    }
    return rev;
}

/*
Leetcode 191: Number of 1 Bits
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.
Example 2:
Input: n = 128
Output: 1
Explanation:
The input binary string 10000000 has a total of one set bit.
Example 3:
Input: n = 2147483645
Output: 30
Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.
*/

int leetcode::hammingWeight(int n) {
    int count = 0;
    while (n) {
        if (n & 1) count++;
        n = n>>1;
    }
    return count;
}

/*
Problem 203: Remove Linked List Elements
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:
Input: head = [], val = 1
Output: []
Example 3:
Input: head = [7,7,7,7], val = 7
Output: []

Idea:
    Use a dummy node to handle edge cases where the head needs to be removed. Iterate through the list, and if the current node's value is equal to val, skip it by adjusting the previous node's next pointer.
    Finally, return the next pointer of the dummy node as the new head of the list.
*/

ListNode* leetcode::removeElements(ListNode* head, int val) {
    ListNode dummy(0,head);
    ListNode* curr = &dummy;
    while (curr->next) {
        if (curr->next->val == val) {
            curr->next = curr->next->next;
        }
        else {
            curr = curr->next;
        }
    }
    return dummy.next;        
}

/*
Problem 206: Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:
Input: head = [1,2]
Output: [2,1]
Example 3:
Input: head = []
Output: []

Idea:
    Use three pointers to reverse the linked list. Iterate through the list, reversing the next pointer of each node to point to the previous node.
    Finally, return the new head of the reversed list.
*/

ListNode* leetcode::reverseList(ListNode* head) {      
    ListNode prev(0);
    while (head) {
        ListNode* nxt = head->next;
        head->next = prev.next;
        prev.next = head;
        head = nxt;
    }
    return prev.next;
}


/*
Leetcode 207: Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Idea: 
    Use Kahn's algorithm for topological sorting. Create an adjacency list and an in-degree array.
    Initialize a queue with all nodes having in-degree 0. Process each node, reducing the in-degree of its neighbors.
    If a neighbor's in-degree becomes 0, add it to the queue. If all nodes are processed, return true; otherwise, return false.
*/

bool leetcode::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> prereq_course(numCourses);
    std::vector<int> count1(numCourses, 0);
    for (const auto& u : prerequisites) {
        int course = u[0], prer = u[1];
        if (course<0 || course >= numCourses || prer<0 || prer>=numCourses || course==prer) return false;
        prereq_course[prer].push_back(course);
        ++count1[course];
    }
    std::queue<int> q;
    for (auto v=0; v<numCourses; v++) {
        if (count1[v]==0) q.push(v);
    }
    int count2=0;
    while (!q.empty()) {
        int first = q.front();
        q.pop();
        ++count2;
        for (auto v : prereq_course[first]) {
            if (--count1[v]==0) q.push(v);
        }
    }
    return (count2==numCourses);
}

/*
Leetcode 217: Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.
Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.
Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
Idea:
    Use a set to keep track of the elements seen so far. If an element is already in the set, return true.
    If the loop completes without finding any duplicates, return false.
*/

bool leetcode::containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> s1;
    for (auto n : nums) {
        if (!s1.insert(n).second) return true;
    }
    return false;
}

/*
Leetcode 231: Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2^x.
Example 1:
Input: n = 1
Output: true
Explanation: 2^0 = 1
Example 2:
Input: n = 16
Output: true
Explanation: 2^4 = 16
Example 3:
Input: n = 3
Output: false
Explanation: There is no x where 2^x = 3.

Idea:
    A number is a power of two if it is greater than zero and the bitwise AND of the number and one less than the number is zero.
*/

bool leetcode::isPowerOfTwo(int n) {
    return (n>0) && ((n & (n-1))==0);
}

/*
Leetcode 238: Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0] 

Idea:
    Use two passes to calculate the product of all elements to the left and right of each element.
    In the first pass, calculate the product of all elements to the left of each element and store it in the result array.
    In the second pass, calculate the product of all elements to the right of each element and multiply it with the corresponding element in the result array.
*/

std::vector<int> leetcode::productExceptSelf(std::vector<int>& nums) {
    size_t n = nums.size();
    std::vector <int> ret (n,1);
    int left=1, right=1;
    for(int i=0; i<n; i++) {
        ret[i] = left;
        left *=nums[i];
    }
    for (int i=n-1; i>=0; --i) {
        ret[i] *= right;
        right *= nums[i];
    }
    return ret;
}

/*
Leetcode 242: Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false
Idea: Sort both strings and compare them. If they are equal, return true; otherwise, return false.
*/

bool leetcode::isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return s == t;
}

/*
Leetcode 268: Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

Idea:
    Use XOR operation to find the missing number. XOR of a number with itself is 0 and XOR of a number with 0 is the number itself.
*/

int leetcode::missingNumber(std::vector<int>& nums) {
    int n = nums.size();
    int res = n;
    for (int i=0; i<n; i++) {
        res ^= i^nums[i];
    }
    return res;
}

/*
LeetCode 283. Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]

Idea:
    Use two pointers: one for the current position and one for the next non-zero element.
    When a non-zero element is found, swap it with the current position and move both pointers forward.
*/

void leetcode::moveZeroes(std::vector<int>& nums) {
    int next_non_zero = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] != 0) {
            std::swap(nums[next_non_zero], nums[i]);
            next_non_zero++;
        }
    }
}

/*
Problem 287: Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
Explanation: There is only one duplicate number in the array, return this number only.  

Idea:
    Use Floyd's Tortoise and Hare (Cycle Detection) algorithm. Treat the array as a linked list where the value at each index points to the next index.
    Use two pointers, one moving twice as fast as the other. If there is a cycle, they will meet. Then, find the entrance to the cycle which is the duplicate number.
*/

int leetcode::findDuplicate(std::vector<int>& nums) {
    int t=nums[0], h=nums[0];
    do {
        t = nums[t];
        h = nums[nums[h]];
    }  while(t!=h);
    t = nums[0];
    while (t!=h) {
        t=nums[t];
        h=nums[h];
    }
    return t;     
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

/*
LeetCode 347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]

Idea:
    Use a hash map to count the frequency of each element. Then, use a bucket sort approach to group elements by their frequency.
    Finally, collect the top k frequent elements from the buckets.
*/

std::vector<int> leetcode::topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int,int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    int n = nums.size();
    std::vector<std::vector<int>> buckets(n + 1);
    for (auto& [num, count] : freq) {
        buckets[count].push_back(num);
    }
    std::vector<int> result;
    for (int i = n; i > 0 && result.size() < k; i--) {
        for (int num : buckets[i]) {
            result.push_back(num);
            if (result.size() == k) return result;
        }
    }
    return result;
}

/*
Problem 383: Ransom Note
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.
Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true
Idea:
    Use a map to count the frequency of each character in the magazine. Then, iterate through the ransom note and check if each character is available in the magazine.
    If any character is not available or its count is insufficient, return false. Otherwise, return true.
*/

bool leetcode::canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> charCount;
    for (char c : magazine) {
        charCount[c]++;
    }
    for (char c : ransomNote) {
        if (charCount[c] == 0) return false;
        charCount[c]--;
    }
    return true;
}

/*
LeetCode 424. Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

Idea:
    Use a sliding window approach with two pointers. Maintain a count of the maximum frequency of any character in the current window.
    If the size of the window minus the maximum frequency exceeds k, move the left pointer to reduce the window size.
    Update the maximum length of the substring found so far.
*/
int leetcode::characterReplacement(std::string s, int k) {        
    if (s.empty()) return 0;
    std::unordered_map <char,int> map1;
    int l=0, best=0, maxFreq=0;
    for (int i=0; i<s.size(); i++) {
        maxFreq = std::max(maxFreq,++map1[s[i]]);
        while(i-l+1 > maxFreq+k) {
            --map1[s[l]];
            l++;
        }
        best = std::max(best,i-l+1);
    }
    return best;
}

/*
Problem 442: Find All Duplicates in an Array
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appear twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.
Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:
Input: nums = [1,1,2]
Output: [1]
Example 3:
Input: nums = [1]
Output: []  

Idea:
    sort and XOR each element with its index-1. The elements that appear twice will remain in the array.
*/

std::vector<int> leetcode::findDuplicates(std::vector<int>& nums) {
    sort(nums.begin(), nums.end());
    std::vector<int> ret;
    for (int i=1; i<nums.size(); i++)
        if ((nums[i]^nums[i-1]) == 0)
            ret.push_back(nums[i]);
    return ret;
}

/*
Leetcode 448: Find All Numbers Disappeared in an Array
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:
Input: nums = [1,1]
Output: [2]

Idea: 
    Count the frequency of each number in the array using a vector. Then, iterate through the vector to find the numbers that are missing (frequency is zero).
*/

std::vector<int> leetcode::findDisappearedNumbers(std::vector<int>& nums) {
    const size_t n = nums.size();
    std::vector<int> count (n+1,0);
    std::vector<int> ret;
    for (auto i=0; i<n; i++) {
        ++count[nums[i]];
    }
    for (auto i=1; i<=n; i++) {
        if (!count[i]) {
            ret.push_back(i);
        }
    }
    return ret;
}

/*
Leetcode 560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.  
Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Idea:
    Use a vector of size nums.size()+1 to store the cumulative sum of the array. For each cumulative sum, check if there is a previous cumulative sum that, when subtracted from the current sum, equals k.
    If such a previous sum exists, it means there is a subarray that sums to k. Count the occurrences of such previous sums.
*/

int leetcode::subarraySum(std::vector<int>& nums, int k) {
    int count = 0;
    size_t n = nums.size();
    std::vector<int> pref (n+1,0);
    for (auto i=1; i<=n; i++) {
        pref[i] = pref[i-1] + nums[i-1];
    }
    for (auto i=0; i<n; i++) {
        for (auto j=i+1; j<=n; j++)
            if (pref[j] - pref[i] == k)
                count++;
    }
    return count;
}