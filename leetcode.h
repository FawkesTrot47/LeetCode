

#include <iostream>
#include <vector>
#include <map>


class leetcode {
public:
    leetcode()
        : m_a{0}
        , m_b(0) {}

    ~leetcode() {}    
    void printAandB();
    void setAandB(int32_t A, int32_t B);
    void printRes(std::vector<int> v1);

    // Leetcode exercise in order
    std::vector<int> twoSum(std::vector<int>& nums, int target);

private:
    int32_t m_a;
    int32_t m_b;
};