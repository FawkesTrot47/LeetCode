#include "leetcode.cpp"

int main() {
    leetcode A;
    // int numCourses = 2;
    // std::vector<std::vector<int>> prerequisites = {{1,0}}; // Expected output: true
    int numCourses = 2;
    std::vector<std::vector<int>> prerequisites = {{1,0},{0,1}}; // Expected output: false
    bool res = A.canFinish(numCourses, prerequisites);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}