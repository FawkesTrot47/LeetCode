#include "leetcode.cpp"

int main() {
    leetcode A;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* res = A.reverseList(head);
    A.printRes(res);
    return 0;
}