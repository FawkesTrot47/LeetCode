#include <iostream>

class leetcode {
public:
    leetcode()
    : m_a{0}
    , m_b(0) {}

    ~leetcode() {}    
    void printAandB() {
        std::cout << "A:" << m_a << std::endl << " B:" << m_b;
    }
    void setAandB(int32_t A, int32_t B) {
        m_a = A;
        m_b = B;
    }

private:
    int32_t m_a;
    int32_t m_b;
};