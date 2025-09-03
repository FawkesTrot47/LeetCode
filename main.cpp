#include "leetcode.cpp"

int main() {
    leetcode A;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    ListNode* res = A.deleteDuplicates(head);
    A.printRes(res);
    return 0;
}