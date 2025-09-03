#include "leetcode.cpp"

int main() {
    leetcode A;
    // Creating two linked lists that intersect
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode* res = A.getIntersectionNode(headA, headB);
    if (res) {
        std::cout << "Intersected at node with value: " << res->val << std::endl;
    } else {
        std::cout << "No intersection." << std::endl;
    }
    return 0;
}