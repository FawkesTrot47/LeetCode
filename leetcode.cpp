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

