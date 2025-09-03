#include "leetcode.cpp"

int main() {
    leetcode A;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int left = 2, right = 4;
    ListNode* res = A.reverseBetween(head, left, right);
    A.printRes(res);
    return 0;
}