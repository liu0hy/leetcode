// https://leetcode.com/problems/merge-two-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head{0};
    ListNode* prev{&head};
    while (l1 && l2) {
      if (l1->val < l2->val) {
        prev->next = l1;
        while (l1->next && l1->next->val < l2->val) l1 = l1->next;
        prev = l1;
        l1 = l1->next;
      } else {
        prev->next = l2;
        while (l2->next && l2->next->val < l1->val) l2 = l2->next;
        prev = l2;
        l2 = l2->next;
      }
    }
    prev->next = l1 ? l1 : l2;
    return head.next;
  }
};
