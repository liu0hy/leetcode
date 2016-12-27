// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode** slow{&head};
    ListNode* fast{head};
    while (--n) fast = fast->next;
    while (fast->next) {
      fast = fast->next;
      slow = &((*slow)->next);
    }
    *slow = (*slow)->next;
    return head;
  }
};
