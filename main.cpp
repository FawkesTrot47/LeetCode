#include "leetcode.cpp"

int main() {
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