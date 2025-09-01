#include "leetcode.cpp"

int main() {
    leetcode A;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle
    bool res = A.hasCycle(head);
    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}