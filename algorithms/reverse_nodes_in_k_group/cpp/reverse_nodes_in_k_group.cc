// https://leetcode.com/problems/reverse-nodes-in-k-group/
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k < 2) return head;
    ListNode** front{&head};
    ListNode* back;
    ListNode* prev;
    ListNode* cur;
    ListNode* next;
    while (true) {
      int n{0};
      prev = back = *front;
      while (back && ++n < k) back = back->next;
      if (!back) break;
      cur = prev->next;
      while (--n > 1) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
      }
      cur = *front;
      cur->next = back->next;
      back->next = prev;
      *front = back;
      front = &cur->next;
    }
    return head;
  }
};
